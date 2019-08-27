/*-------------------------------------------------------------------------
 * Filename:      xmodem.c
 * Version:       $Id: xmodem.c,v 1.2 2002/01/06 19:02:29 erikm Exp $
 * Copyright:     Copyright (C) 2001, Hewlett-Packard Company
 * Author:        Christopher Hoover <ch@hpl.hp.com>
 * Description:   xmodem functionality for uploading of kernels 
 *                and the like
 * Created at:    Thu Dec 20 01:58:08 PST 2001
 *-----------------------------------------------------------------------*/
/*
 * xmodem.c: xmodem functionality for uploading of kernels and 
 *            the like
 *
 * Copyright (C) 2001 Hewlett-Packard Laboratories
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */
/*------------------------------------------------------------------------
 * Filename     : xmodem.c 
 * Program      : excalibur linux loader.
 * Author       : newboder@hybus.net
 * Description  : 
 * Based on     : blob-xscale 
 * Created      : 
 * Modified     : 2003.11.1
 ------------------------------------------------------------------------*/
#include <serial.h>
#include <lstring.h>
#include <xmodem.h>

#define SOH 0x01
#define STX 0x02
#define EOT 0x04
#define ACK 0x06
#define NAK 0x15
#define CAN 0x18
#define BS  0x08 

#define TIMEOUT 10
#define MAXERRORS 5

#define ERROR(...) do { } while (0)

int  SerialInputBlock(char *buf, int bufsize, const int timeout);
static char blockBuf[1024];

/*--------------------------------------------------*/
void  SerialPutChar(const char c){
    // FIFO에 데이타가 없을때까지 기다린다.
    while ((FFLSR & 0x00000020) == 0 );
    FFTHR = ((ulong)c & 0xFF);
}

int  SerialInPutflush() { 
	volatile ulong tmp; 
	tmp = FFRBR; //Rx 버퍼 클리어
	return 0;
}

int SerialInputChar(char *c){
    // FIFO에 데이타가 있을때까지 기다린다.
    while(!(FFLSR & 0x00000001));
	(volatile char)*c = FFRBR;
	return 1;
}

int Serialtstc(void){
    if((FFLSR & 0x00000001)==0)
        return 0;//FIFO에 데이타가 없다면
    else 
        return 1;//있다면
}
/*------------------------------------------------------*/

static inline void WriteByte(char cc) {
	SerialPutChar(cc);
}

static inline void ReadFlush() { 
	SerialInPutflush();
}

int ReadByteWithTimeout(unsigned int timeout) {
	char buf[1];
	int n;

	n = SerialInputBlock(buf, 1, timeout);

	if (n == 1)
		return buf[0] & 0xff;
	else
		return -1;
}

int XModemReceive(char *bufBase, int bufLen)
{
	unsigned int errors = 0;
    unsigned int wantBlockNo = 1;
    unsigned int length = 0;
    int crc = 1;
    char nak = 'C';

    ReadFlush();

    printf("\rReady for xmodem download..\n");
    /* Ask for CRC; if we get errors, we will go with checksum */
    WriteByte(nak);

    for (;;) {
		int blockBegin;
        int blockNo, blockNoOnesCompl;
        int blockLength;
        int cksum = 0;
        int crcHi = 0;
        int crcLo = 0;

        blockBegin = ReadByteWithTimeout(TIMEOUT);
        if (blockBegin < 0)
			goto timeout;

        nak = NAK;

        switch (blockBegin) {
        case SOH:
        case STX:
			break;

        case EOT:
			WriteByte(ACK);
			goto done;

        default:
			goto error;
		}

        /* block no */
        blockNo = ReadByteWithTimeout(TIMEOUT);
        if (blockNo < 0)
			goto timeout;
        /* block no one's compliment */
        blockNoOnesCompl = ReadByteWithTimeout(TIMEOUT);
        if (blockNoOnesCompl < 0)
			goto timeout;

        if (blockNo != (255 - blockNoOnesCompl)) {
			ERROR("bad block ones compl\n");
			goto error;
        }

		blockLength = (blockBegin == SOH) ? 128 : 1024;

        {
			int i;
			for (i = 0; i < blockLength; i++) {
				int cc = ReadByteWithTimeout(TIMEOUT);
				if (cc < 0)
					goto timeout;
				blockBuf[i] = cc;
			}
		}

		if (crc) {
			crcHi = ReadByteWithTimeout(TIMEOUT);
			if (crcHi < 0)
				goto timeout;

			crcLo = ReadByteWithTimeout(TIMEOUT);
			if (crcLo < 0)
				goto timeout;
		} else {
			cksum = ReadByteWithTimeout(TIMEOUT);
			if (cksum < 0)
				goto timeout;
		}

        if (blockNo == ((wantBlockNo - 1) & 0xff)) {
			/* a repeat of the last block is ok, just ignore it. */
            /* this also ignores the initial block 0 which is */
            /* meta data. */
			goto next;
		} else if (blockNo != (wantBlockNo & 0xff)) {
			ERROR("unexpected block no, 0x%08x, expecting 0x%08x\n", blockNo, wantBlockNo);
			goto error;
		}

        if (crc) {
			int crc = 0;
            int i, j;
            int expectedCrcHi;
            int expectedCrcLo;

            for (i = 0; i < blockLength; i++) {
				crc = crc ^ (int) blockBuf[i] << 8;
				for (j = 0; j < 8; j++)
					if (crc & 0x8000)
						crc = crc << 1 ^ 0x1021;
					else
						crc = crc << 1;
			}

            expectedCrcHi = (crc >> 8) & 0xff;
            expectedCrcLo = crc & 0xff;

            if ((crcHi != expectedCrcHi) || (crcLo != expectedCrcLo)) {
				ERROR("crc error, expected 0x%02x 0x%02x, got 0x%02x 0x%02x\n", \
						expectedCrcHi, expectedCrcLo, crcHi, crcLo);
				goto error;
			}
		} else {
			unsigned char expectedCksum = 0;
			int i;

			for (i = 0; i < blockLength; i++)
				expectedCksum += blockBuf[i];
			if (cksum != expectedCksum) {
				ERROR("checksum error, expected 0x%02x, got 0x%02x\n", expectedCksum, cksum);
				goto error;
			}
		}

		wantBlockNo++;
        length += blockLength;

        if (length > bufLen) {
			ERROR("out of space\n");
			goto error;
		}

		{
			int i;
			for (i = 0; i < blockLength; i++)
				*bufBase++ = blockBuf[i];
		}
next:
		errors = 0;
		WriteByte(ACK);
		continue;

error:
timeout:
		errors++;
		if (errors == MAXERRORS) {
			/* Abort */
			int i;

			// if using crc, try again w/o crc
			if (nak == 'C') {
				nak = NAK;
				errors = 0;
				crc = 0;
				goto timeout;
			}

			ERROR("too many errors; giving up\n");
			for (i = 0; i < 5; i ++)
				WriteByte(CAN);
			for (i = 0; i < 5; i ++)
				WriteByte(BS);
			return -1;
		}

		ReadFlush();
		WriteByte(nak);
	}

done:
	return length;
}
                           
bool DoRX(CMD_TBL *cptr, int argc, char **argv)
{
	ulong     size;
	ulong     addr=0, len=0;

	if (!StrCmp(argv[1], "loader") || !StrCmp(argv[1], "kernel") || \
			!StrCmp(argv[1], "ramdisk") || !StrCmp(argv[1], "root"))
	{
		if (!StrCmp(argv[1], "kernel")){
			addr = (ulong)KERNEL_DRAM_BASE;
			len = KERNEL_MAX_SIZE; 
		}if(!StrCmp(argv[1], "ramdisk")){
			addr = (ulong)RAMDISK_DRAM_BASE;
			len = RAMDISK_MAX_SIZE;
		}if(!StrCmp(argv[1], "loader")){
			addr = (ulong)LOADER_DRAM_BASE;
			len = LOADER_MAX_SIZE;
		}if(!StrCmp(argv[1], "root")){
			addr = (ulong)ROOT_DRAM_BASE;
			len = ROOT_MAX_SIZE;
		} 
	}
	else {
		if (argc < 2 || !HexToInt(argv[1], &addr, 32))
		{
			printf(cptr->usage);
			return false;
		}
	}
	printf("Received sdram addr 0x%08lx \n", (long unsigned int)addr );
	size = XModemReceive((char *) addr, len);
	return 0;
}

/* 
 * SerialInputBlock(): almost the same as SerialInputString(), but
 * this one just reads a block of characters without looking at
 * special characters.
 */
int  SerialInputBlock(char *buf, int bufsize, const int timeout)
{
	ulong startTime, currentTime;
	char c;
	int i;
	int numRead;
	int maxRead = bufsize;
    
	startTime = GetTime();

	for(numRead = 0, i = 0; numRead < maxRead;) {
		/* try to get a byte from the serial port */
		while( Serialtstc() == 0) {
			currentTime = GetTime();

			/* check timeout value */
			if((currentTime - startTime) > (timeout * HZ)) {
				/* timeout! */
				return(numRead);
			}
		}
		
		SerialInputChar(&c);
		/* check for errors */
		if( c < 0 )
			return c;

		buf[i++] = c;
		numRead ++;
	}
	return(numRead);
}
