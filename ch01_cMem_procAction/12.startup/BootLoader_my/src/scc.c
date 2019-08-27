/////////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2001-2002 Hybus Co,.ltd. All rights reserved.
//
// Module name:
//      scc.c
//
// Description:
//
//
// Author:
//      bedguy
//
// Created:
//      2002.10
//
///////////////////////////////////////////////////////////////////////////////

#include <net.h>
#include <scc.h>

static void		WriteToPPR(short addr, short value);
static short	ReadFromPPR(short addr);

static void WriteToPPR(short addr, short value){
	IO_PPPTR = addr;
	IO_PPDATA = value;
	return;
}	// WriteToPPR.


static short ReadFromPPR(short addr){
	IO_PPPTR = addr;
	return IO_PPDATA;
}	// ReadFromPPR.


bool EthTx(void *txPktBuf, int len){
	short *endPtr, *s;

	// Check Link on.
	if (!(ReadFromPPR(PP_LineST) & LINK_OK)){
		printf("\nEthernet Link failed. Check line.\n");
		return false;
	}
	
	// packet 전체가 CS8900A에 보내진 후 전송시작.
	IO_TXCMD = TX_AFTER_ALL;
	IO_TXLEN = len;

	// Tx가 준비될 때까지 대기.
	while ((ReadFromPPR(PP_BusST) & READY_FOR_TX_NOW)==0);

	// CS8900으로 packet 전송. 이것이 끝난 후 CS8900A가 RJ45로 packet 전송을 시작함.
	for (s=txPktBuf, endPtr=txPktBuf+len; s<endPtr; s++){
		IO_RTX_DATA = *s;
	}
	
	return true;
}	// EthTx.


int EthRx(void *rxPktBuf){
	int		i;
	char	*s;
	short	isq, status, len, cnt;

	// loop while something exists in ISQ.
	while ((isq=IO_ISQ)){
		// some packet is received.
		if (isq & ISQ_RECEIVER_EVENT){
			// 1. get status.
			status = IO_RTX_DATA;
			if ((status & RX_OK) && RX_IA_ACCEPT){
				// 2. get length.
				len = IO_RTX_DATA;

				// 3. get packet.
				cnt = len/2 + len%2;
				MemSet(rxPktBuf, 0, MAX_PKT_SIZE);
				for (i=0, s=rxPktBuf; i<cnt; i++){
					*((ushort *)s)++ = IO_RTX_DATA;
				}

				// 4. packet 처리.
				RxPacketHandle((char *)rxPktBuf, len);
			}
			// 비정상적으로 도착한 packet 무시.
			else {
			}
		}
		// 다른 event 무시.
		else if (isq & ISQ_TRANSMITTER_EVENT){
		}
		else if (isq & ISQ_BUFFER_EVENT){
		}
		else if (isq & ISQ_RX_MISS_EVENT){
		}
		else if (isq & ISQ_TX_COL_EVENT){
		}
	}
	return true;
}	// EthRx.

bool EthInit(){
	int		i;

	// 1. check memory mapping (read IOBase Address).
	// check value of IO_PPPTR is 0x3000.
	// 1~3 bit(011b) is read only. so clear others.

	MemSet((char *)0x04000000, 0x0, 2);		// Test Code
	
	if ((IO_PPPTR&0x7000) != 0x3000){
		printf("Can't access to Memory of CS8900A.\n");
		return false;
	}
	
	// 2. check CS8900A Chip ID (read packet page 0x0000~0x0003).
	if (ReadFromPPR(PP_ChipID)!=0x630E){
		printf("\nEthernet Chip is not CS8900A. Are you use CS8900A.\n");
		return false;
	}

	// 3. Rx, Tx disable.
	WriteToPPR(PP_LineCTL, 			0x0000);

	// 4. if needs, set Bus Interface Registers(view CS8900 Manual 4.2 p40).
	WriteToPPR(PP_CS8900_ISAINT,	INTRQ_HIGH_IMPEDENCE);
	WriteToPPR(PP_CS8900_ISADMA,	DMRQ_HIGH_IMPEDENCE);

	// 5. set Status and Control Registers.
	WriteToPPR(PP_RxCFG,	RX_OK_ENBL | RX_CRC_ERROR_ENBL);
	WriteToPPR(PP_RxCTL,	RX_OK_ACCEPT | RX_IA_ACCEPT);
	
	WriteToPPR(PP_TxCFG,	TX_LOST_CRS_ENBL | TX_SQE_ERROR_ENBL | TX_OK_ENBL |
							TX_LATE_COL_ENBL | TX_JBR_ENBL | TX_ANY_COL_ENBL);
	WriteToPPR(PP_TxCMD,	TX_START_ALL_BYTES);
	WriteToPPR(PP_BufCFG,	0x0000);
	WriteToPPR(PP_BusCTL,	ENABLE_IRQ | IO_CHANNEL_READY_ON);
	WriteToPPR(PP_TestCTL,	0x0000);
	

	///// Initiate Transmit Registers. ////////////////////////////////////////
	WriteToPPR(PP_TxCommand,0x00c0);	// start Tx after the entire frame is in the CS8900A.

	// 6. set Address Filter Registers.
	// set Logical Address Filter.
	for (i=0; i<4; i++){
		WriteToPPR(PP_LAF+i*2, 0xffff);
	}

	for (i=0; i<3; i++){
		WriteToPPR(PP_IA+i*2, *((ushort *)&(clientEther[i*2])));
	}

    // 7. Rx, Tx enable.
	WriteToPPR(PP_LineCTL,	SERIAL_RX_ON | SERIAL_TX_ON);
	return true;
}	// EthInit.


void EthHalt(void){
}

void EthRestart(void){
}
