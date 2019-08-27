#include <uucodec.h>

#ifdef USE_SERIAL_UUCODEC

#define INT_BUF_SIZE				128
#define	MAX_RETRIES				10

#define TEST_MAX_RETRIES	do {					\
		if(retries++ > MAX_RETRIES){				\
		        printf("\n*** Timeout exceeded. Aborting.\n");	\
			return -1;					\
		}							\
	} while(0)

#define	ENC(c) ((c) ? ((c) & 077) + ' ': '`')
#define	DEC(c)	(((c) - ' ') & 077)		// single character decode.
#define IS_DEC(c) ((((c) - ' ') >= 0) &&  (((c) - ' ') <= 077 + 1))

#define OUT_OF_RANGE	do {							\
		printf("\n");							\
   	    printf(buf);							\
        printf("\n&^^ Received character out of range. Aborting. ^^&\n");	\
        return -1;								\
	} while(0)

#define PUT_CHAR(x)		do {					\
		if(bytesWritten < bufLen)				\
        bufBase[bytesWritten++] = x;					\
	} while(0)

static int	UUDecode(char *bufBase, int bufLen);
static int	SerialInputString(char *s, const int len, const int timeout);

#define SCRToBaud(A)  (14745600 / (16 * (A)))
bool DoDownload(CMD_TBL *cptr, int argc, char **argv){
	char	*addr=0;
	ulong	len=0;
	ulong	numRead=0;

	if (!StrCmp(argv[1], "loader") || !StrCmp(argv[1], "kernel") || !StrCmp(argv[1], "ramdisk") \
			|| !StrCmp(argv[1], "root") )
	{

		if (!StrCmp(argv[1], "kernel")){
			addr = (char *)KERNEL_DRAM_BASE;
			len = KERNEL_MAX_SIZE;
		}if(!StrCmp(argv[1], "ramdisk")){
			addr = (char *)RAMDISK_DRAM_BASE;
			len = RAMDISK_MAX_SIZE;
		}if(!StrCmp(argv[1], "loader")){
			addr = (char *)LOADER_DRAM_BASE;
			len = LOADER_MAX_SIZE;
		}if(!StrCmp(argv[1], "root")){
			addr = (char *)LOADER_DRAM_BASE;
			len = LOADER_MAX_SIZE;
		}
		
	}
	else {
		if (argc < 3 || !HexToInt(argv[1], &addr, 32) ||
						!HexToInt(argv[2], &len, 32)){
			printf(cptr->usage);
			return false;
		}
	}

	printf("Download speed is %ld baud.\n", SCRToBaud(status.downloadSpeed));
	printf("exec \"uuencode\" at Host PC \n");

	// Download image.
	numRead = UUDecode(addr, len);

	// Some error exists in received image.
	if(numRead < 0) {
		printf("Uudecode receive failed ^^&\n");
		SerialInit(SERIAL_BAUD_115200);
		return false;
	}

	// Success.
	printf("Received 0x%08lx (%ld) bytes.", numRead, numRead);
	printf("\n");

	return true;
}	// DoDownload.

// 역할 : serial로 받은 uuencode된 data를 decode하여 memory에 기록.
// 매개 : 
// 반환 : 
// 주의 : 
static int UUDecode(char *bufBase, int bufLen) {
	// Receives and decodes an incoming uuencoded stream. Returns the number of 
	// bytes put in the buffer on success, or -1 otherwise.
	int n, linesReceived = 0;
	char ch, *p;
	int bytesWritten = 0, retries = 0;
	char buf[INT_BUF_SIZE];

	// Search for header line. We don't care about the mode or filename.
	retries = 0;
	do {
		SerialInputString(buf, sizeof(buf), INT_BUF_SIZE);
		TEST_MAX_RETRIES;		
	} while (StrNCmp(buf, "begin ", 6) != 0);

	// for each input line.
	for (;;){
		if (SerialInputString(p=buf, sizeof(buf), 2) == 0) {
			printf("\n&^^ Short file. Aborting ^^&\n");
			return -1;
		}
		// Status print to show where we are at right now.
		if((linesReceived++ & 0x007F) == 0) {
			printf(".");
		}

		// `n' is used to avoid writing out all the characters
		// at the end of the file.
		if ((n = DEC(*p)) <= 0) break;
		for (++p; n > 0; p += 4, n -= 3)
			if (n >= 3) {
				if (!(IS_DEC(*p) && IS_DEC(*(p+1)) && IS_DEC(*(p+2)) && IS_DEC(*(p+3))))
					OUT_OF_RANGE;

				ch = DEC(p[0]) << 2 | DEC(p[1]) >> 4;
				PUT_CHAR(ch);
				ch = DEC(p[1]) << 4 | DEC(p[2]) >> 2;
				PUT_CHAR(ch);
				ch = DEC(p[2]) << 6 | DEC(p[3]);
				PUT_CHAR(ch);
			}
			else {
				if (n >= 1) {
					if (!(IS_DEC(*p) && IS_DEC(*(p + 1))))
						OUT_OF_RANGE;
					ch = DEC(p[0]) << 2 | DEC(p[1]) >> 4;
					PUT_CHAR(ch);
				}
				if (n >= 2) {
					if (!(IS_DEC(*(p + 1)) && 
						IS_DEC(*(p + 2))))
						OUT_OF_RANGE;

					ch = DEC(p[1]) << 4 | DEC(p[2]) >> 2;
					PUT_CHAR(ch);
				}
				if (n >= 3) {
					if (!(IS_DEC(*(p + 2)) && 
						IS_DEC(*(p + 3))))
						OUT_OF_RANGE;
					ch = DEC(p[2]) << 6 | DEC(p[3]);
					PUT_CHAR(ch);
				}
			}
	}
	printf("\n");
	if (SerialInputString(p = buf, sizeof(buf), 2) == 0 || (StrNCmp(buf, "end", 3))) {
		printf("&^^ No \"end\" line. Aborting. ^^&\n");
		return(-1);
	}
	return(bytesWritten);
} // UUDecode.

// read a string with maximum length len from the serial port
// using a timeout of timeout seconds.
// len is the length of array s _including_ the trailing zero,
// the function returns the number of bytes read _excluding_
// the trailing zero.
static int SerialInputString(char *s, const int len, const int timeout){
	ulong	endTime;
	char	c;
	int		i, numRead;

	endTime = GetTime() + HZ * timeout;
	for (numRead=0, i=0; numRead<len-1;){
		// try to get a byte from the serial port.
		while (!SerialInputByte(&c)) {
			// check timeout value.
			if (GetTime() > endTime){
				// timeout.
				s[i++] = '\0';
				return numRead;
			}
		}

		// eat newline characters at start of string.
		if (numRead!=0 || (c!='\r' && c!='\n')){
			if ((c=='\r') || (c=='\n')){
				s[i++] = '\0';
				return(numRead);
			} else {
				s[i++] = c;
				numRead++;
			}
		}
	}
	return(numRead);
}	// SerialInputString.

#endif		// end USE_SERIAL_UUDECODE.
