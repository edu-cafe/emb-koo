/*------------------------------------------------------------------------
 * Filename     : xmodem.h 
 * Program      : excalibur linux loader.
 * Author       : newboder@hybus.net
 * Description  : 
 * Based on     : blob-xscale 
 * Created      : 
 * Modified     : 2003.11.1
 ------------------------------------------------------------------------*/

#ifndef _XMODEM_H_46146832674264632647324
#define _XMODEM_H_46146832674264632647324

#define CMD_TBL_RX                  \
                {"rx", DoRX,        \
                "  rx {loader/kernel/ramdisk/root}          Receives file with XMODEM protocol.\n",  \
                0,                                                                                   \
                "  rx {loader/kernel/ramdisk/root}          Receives file with XMODEM protocol.\n",  \
                }

bool    DoRX(CMD_TBL *cptr, int argc, char **argv);
int 	XModemReceive(char *bufBase, int bufLen);

#endif
