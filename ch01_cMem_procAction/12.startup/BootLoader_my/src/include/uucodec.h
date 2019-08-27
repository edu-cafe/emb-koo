#ifndef _UUCODEC_H_46146832674264632647324
#define _UUCODEC_H_46146832674264632647324

#include "main.h"
#ifdef USE_SERIAL_UUCODEC

#define CMD_TBL_DOWNLOAD			\
		{"download", DoDownload,	\
		"  download {loader/kernel/ramdisk/root}    Download UUEncoded data in serial.\n"		\
		"  download [addr] [maxlen]                 Download UUEncoded data in serial.\n",	\
		"  download {loader/kernel/ramdisk/root}    Download UUEncoded data in serial.\n",	\
		"  download {loader/kernel/ramdisk/root}    Download UUEncoded data in serial.\n"		\
		"  download [addr] [maxlen]                 Download UUEncoded data in serial.\n",	\
		}

bool	DoDownload(CMD_TBL *cptr, int argc, char **argv);

#endif		// end USE_SERIAL_UUDECODE.

#endif		// end _UUCODEC_H_46146832674264632647324.
