;*******************************************************************
;                           ARM
;                Assembly Programming 실습
;
;                XScale Compatible Target
;
; File : armlib.s
; By   : Kim, Soo Hyun
;*******************************************************************
;-------------------------------------------------------------------
DRAM_BASE		EQU		0xA0000000
DRAM_SIZE		EQU		0x04000000
FIQSTACKEND		EQU		DRAM_BASE +DRAM_SIZE-4		;A3FFFFFC
IRQSTACKEND		EQU		SVCSTACKEND-0x00010000		;A3FDFFFC
SVCSTACKEND		EQU		FIQSTACKEND-0x00010000		;A3FEFFFC
;-------------------------------------------------------------------
INTERRUPT_CONTROL_BASE EQU      0x40D00000

ICIP			EQU		0x00
ICMR			EQU		0x04
ICLR			EQU		0x08
ICFP			EQU		0x0C
ICPR			EQU		0x10
ICCR			EQU		0x14
;-------------------------------------------------------------------
SDRAM_BASE      EQU		0xA0000000

;-------------------------------------------------------------------
FFUART_BASE       EQU      0x40100000

FFRBR             EQU      0x00
FFTHR             EQU      0x00
FFIER             EQU      0x04
FFIIR             EQU      0x08
FFFCR             EQU      0x08
FFLCR             EQU      0x0C
FFMCR             EQU      0x10
FFLSR             EQU      0x14
FFMSR             EQU      0x18
FFSPR             EQU      0x1C
FFISR             EQU      0x20
FFDLL             EQU      0x00
FFDLH             EQU      0x04

FFFCR_VALUE       EQU      0x00000041
FFISR_VALUE       EQU      0x00000000
;-------------------------------------------------------------------
GPIO_BASE         EQU      0x40E00000

GPLR0             EQU      0x00
GPLR1             EQU      0x04
GPLR2             EQU      0x08
GPDR0             EQU      0x0C
GPDR1             EQU      0x10
GPDR2             EQU      0x14
GPSR0             EQU      0x18
GPSR1             EQU      0x1C
GPSR2             EQU      0x20
GPCR0             EQU      0x24
GPCR1             EQU      0x28
GPCR2             EQU      0x2C
GRER0             EQU      0x30
GRER1             EQU      0x34
GRER2             EQU      0x38
GFER0             EQU      0x3C
GFER1             EQU      0x40
GFER2             EQU      0x44
GDER0             EQU      0x48
GDER1             EQU      0x4C
GDER2             EQU      0x50
GAFR0_L           EQU      0x54
GAFR0_U           EQU      0x58
GAFR1_L           EQU      0x5C
GAFR1_U           EQU      0x60
GAFR2_L           EQU      0x64
GAFR2_U           EQU      0x68

GPDR0_VALUE       EQU      0xC0439330
GPDR1_VALUE       EQU      0xFCFFAB82
GPDR2_VALUE       EQU      0x0001FFFF

GPSR0_VALUE       EQU      0x00408030
GPSR1_VALUE       EQU      0x00BFA882
GPSR2_VALUE       EQU      0x0001C000

GPCR0_VALUE       EQU      0xC0031100
GPCR1_VALUE       EQU      0xFC400300
GPCR2_VALUE       EQU      0x00003FFF

GRER0_VALUE       EQU      0x0F800000
GRER1_VALUE       EQU      0x00000001
GRER2_VALUE       EQU      0x0020000C

GFER0_VALUE       EQU      0x00000000
GFER1_VALUE       EQU      0x00000000
GFER2_VALUE       EQU      0x00004001

GAFR0L_VALUE      EQU      0x80000000
GAFR0U_VALUE      EQU      0xA5000010
GAFR1L_VALUE      EQU      0x60008018
GAFR1U_VALUE      EQU      0xAAA5AAAA
GAFR2L_VALUE      EQU      0xAAA0000A
GAFR2U_VALUE      EQU      0x00000002

;-------------------------------------------------------------------
PSSR              EQU      0x40F00004
PSSR_PH           EQU      0x00000010
PSSR_RDH          EQU      0x00000020

;-------------------------------------------------------------------
CLOCK_MANAGER_BASE	EQU      0x41300000

CCCR              EQU      0x00
CKEN              EQU      0x04
OSCC              EQU      0x08

CCCR_VALUE        EQU      0x00000241

CKEN_VALUE        EQU      0x00000040
OSCC_VALUE        EQU      0x00000002

OSCR              EQU      0x40A00010
CLK_TO_10MS       EQU      36864         ; 3.686400 Mhz

;-------------------------------------------------------------------
; Control Registers
MEM_CTL_BASE      EQU      0x48000000

MDCNFG            EQU      0x00
MDREFR            EQU      0x04
MSC0              EQU      0x08
MSC1              EQU      0x0C
MSC2              EQU      0x10
MECR              EQU      0x14
SXCNFG            EQU      0x1C
MCMEM0            EQU      0x28
MCMEM1            EQU      0x2C
MCATT0            EQU      0x30
MCATT1            EQU      0x34
MCIO0             EQU      0x38
MCIO1             EQU      0x3C
MDMRS             EQU      0x40
;-------------------------------------------------------------------
; Control Register initial values
MDCNFG_VALUE      EQU      0x00001AC9
MDREFR_VALUE      EQU      0x020DF016

;255B type
MSC0_VALUE        EQU      0x7ff07ff0
MSC1_VALUE        EQU      0x12BC5554
MSC2_VALUE        EQU      0x7FF07FF5

MECR_VALUE        EQU      0x00000000
SXCNFG_VALUE      EQU      0x00000000
MCMEM0_VALUE      EQU      0x00010504
MCMEM1_VALUE      EQU      0x00010504
MCATT0_VALUE      EQU      0x00010504
MCATT1_VALUE      EQU      0x00010504
MCIO0_VALUE       EQU      0x00004715
MCIO1_VALUE       EQU      0x00004715
MDMRS_VALUE       EQU      0x00000000
;-------------------------------------------------------------------

	AREA		ARMLIB, CODE, READONLY

;;	ENTRY

	EXPORT		ResetProcess
	
	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;                                                
;;;;;     Reset Process Function                                                                       
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; 
ResetProcess  
        
        mov             r9, lr
                                                                                                 
        ; Mask All interrupt                                                                             
        ldr     r12, =INTERRUPT_CONTROL_BASE	;PXA 255 manual 4-21참조, 교재 304 참조
		ldr     r0, =0x00000000                                                                          
        str     r0, [r12, #ICMR]				;[40d0 0004] <- 0
        str     r0, [r12, #ICLR]				;[40d0 0008] <- 0 All interrupt disable
                                                                                                         
        ; Initialize GPIO                                                                                
		bl      gpio_init                                                                                
                                                                                                         
        ; Initialize SDRAM                                                                               
        bl      init_sdram   
        
;**** Variable Area Initialization ********************************************
;
;

        IMPORT  |Image$$RO$$Limit|      ; End of ROM code (=start of ROM data)
        IMPORT  |Image$$RW$$Base|       ; Base of RAM to initialise
        IMPORT  |Image$$ZI$$Base|       ; Base and limit of area
        IMPORT  |Image$$ZI$$Limit|      ; to zero initialise;

        ldr     r0, =|Image$$RO$$Limit| ; Get pointer to ROM data
        ldr     r1, =|Image$$RW$$Base|  ; and RAM copy									//data 영역의 처음부분
        ldr     r3, =|Image$$ZI$$Base|  ; Zero init base => top of initialised data		//bss  영역의 처음부분
        cmp     r0, r1                  ; Check that they are different
        beq     %1
0       cmp     r1, r3                  ; Copy init data			//data 영역을 copy하여 sdram에 paste한다.
        ldrcc   r2, [r0], #4
        strcc   r2, [r1], #4
        bcc     %0
1       ldr     r1, =|Image$$ZI$$Limit| ; Top of zero init segment
        mov     r2, #0
2       cmp     r3, r1                  ; Zero init					//BSS 영역을 copy하여 sdram에 paste한다.
        strcc   r2, [r3], #4
        bcc     %2

;**** Stack Point Setting Each CPU Mode ****************************************
;	
;

	; Fiq and Irq Interrupt Diable
	ldr     r0, =0x000000d2		; IRQ Mode sp Setting
	msr     cpsr_cf, r0
	ldr     r13, =IRQSTACKEND
	
	; Fiq and Irq Interrupt Disable
	ldr     r0, =0x000000d1		; FIQ Mode sp Setting
	msr     cpsr_cf, r0
	ldr     r13, =FIQSTACKEND
	
	; Fiq Interrupt Enable
	ldr     r0, =0x000000d3		; SVC Mode sp Setting
	msr     cpsr_cf, r0
	ldr     r13, =SVCSTACKEND
	
	
	mov		pc, r9
	


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;                                                
;;;;;     Initialize GPIO                                                              
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;                                                                                                         
gpio_init                                                                                                
		ldr		r12, =FFUART_BASE
		                                                                                                 
		ldr		r0, =0x00000000                                                                          
		str		r0, [r12, #FFLCR]                                                                        
		ldr		r0, =0x00000000                                                                          
		str		r0, [r12, #FFIER]                                                                        
		ldr		r0, =0x00000080                                                                          
		str		r0, [r12, #FFLCR]                                                                        
		ldr		r0, =0x00000008                                                                          
		str		r0, [r12, #FFDLL]                                                                        
		ldr		r0, =0x00000000                                                                          
		str		r0, [r12, #FFDLH]                                                                        
		ldr		r0, =0x00000000                                                                          
		str		r0, [r12, #FFLCR]                                                                        
		ldr		r0, =0x00000003                                                                          
		str		r0, [r12, #FFLCR]                                                                        
		ldr		r0, =0x00000001                                                                          
		str		r0, [r12, #FFFCR]                                                                        
		ldr		r0, =0x00000007                                                                          
		str		r0, [r12, #FFFCR]                                                                        
		ldr		r0, =0x0000000                                                                           
		str		r0, [r12, #FFIER]                                                                        
		ldr		r0, =0x0000000                                                                           
		str		r0, [r12, #FFMCR]                                                                        
		                                                                                                 
		ldr		r0, =FFISR_VALUE                                                         
		str		r0, [r12, #FFISR]                                                        		                                                                                                 
		                                                                                                 
		ldr		r12, =GPIO_BASE                                       
		                                                              
		ldr		r0, =GAFR0L_VALUE                                     
		str		r0, [r12, #GAFR0_L]                                   
		ldr		r0, =GAFR0U_VALUE                                     
		str		r0, [r12, #GAFR0_U]                                   
		                                                              
		ldr		r0, =GAFR1L_VALUE                                     
		str		r0, [r12, #GAFR1_L]                                   
		ldr		r0, =GAFR1U_VALUE                                     
		str		r0, [r12, #GAFR1_U]                                   
		                                                              
		ldr		r0, =GAFR2L_VALUE                                     
		str		r0, [r12, #GAFR2_L]                                   
		ldr		r0, =GAFR2U_VALUE                                     
		str		r0, [r12, #GAFR2_U]                                   
		                                                             
		ldr		r0, =GPSR0_VALUE
		str		r0, [r12, #GPSR0]
		ldr		r0, =GPSR1_VALUE                                      
		str		r0, [r12, #GPSR1]                                     
		ldr		r0, =GPSR2_VALUE                                      
		str		r0, [r12, #GPSR2]                                     
		                                                             
		ldr		r0, =GPCR0_VALUE                                      
		str		r0, [r12, #GPCR0]                                     
		ldr		r0, =GPCR1_VALUE                                      
		str		r0, [r12, #GPCR1]                                     
		ldr		r0, =GPCR2_VALUE                                      
		str		r0, [r12, #GPCR2]                                     
		                                                             
		ldr		r0, =GPDR0_VALUE                                      
		str		r0, [r12, #GPDR0]                                     
		ldr		r0, =GPDR1_VALUE                                      
		str		r0, [r12, #GPDR1]                                     
		ldr		r0, =GPDR2_VALUE                                      
		str		r0, [r12, #GPDR2]                                     
		                                                              
		; Clear the peripheral control register bits                      
		ldr		r1, =PSSR                                             
		ldr		r2, =(PSSR_RDH | PSSR_PH)                             
		str		r2, [r1]                                              
		                                                              
		ldr		r12, =FFUART_BASE                                         
		ldr		r0, =0x00000040                                           
		str		r0, [r12, #FFIER]                                         
		                                                              
		;clear the rx fifo errors                                     
		ldr		r0, =FFFCR_VALUE                              
		and		r0, r0, #0x00000002                           
		str		r0, [r12, #FFFCR]                             
		                                                              
		mov		pc, lr       
		
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;                               
;;;;;      Initialize SDRAM     ;;;;;;;        
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
                                                                      
init_sdram                                                            
		mov             r10, lr                               
                                                                      
		ldr		r12, =CLOCK_MANAGER_BASE                              
                                                                      
		ldr		r0, =CKEN_VALUE
		str		r0, [r12, #CKEN]                                      
		ldr		r0, =OSCC_VALUE                                       
		str		r0, [r12, #OSCC]                                      
                                                                      
		ldr		r0, =CCCR_VALUE                                       
		str		r0, [r12, #CCCR]                                      
		mov		r1, #3                                                
		mcr		p14, 0, r1, c6, c0, 0                                 
                                                                     
		ldr		r1, =OSCR
		ldr		r0, =0                                
		str		r0, [r1]                              
		                                                      
		ldr		r0, =0x300            
		                                
wait_for_clock                                                        
		ldr		r2, [r1]                                              
		cmp		r0, r2                                                
		bne		wait_for_clock                                        
		                                                              
		;Step 1 in Intel's code                                       
		ldr		r12, =MEM_CTL_BASE                                    
		                                                              
		ldr		r0, =MSC0_VALUE                                       
		str		r0, [r12, #MSC0]                                      
		;Intel's code reads it back to make sure it works...          
		                                                              
		ldr		r0, =MSC1_VALUE                                       
		str		r0, [r12, #MSC1]                                      
		ldr		r0, [r12, #MSC1]                                      
		                                                              
		ldr		r0, =MSC2_VALUE                                       
		str		r0, [r12, #MSC2]                                      
		ldr		r0, [r12, #MSC2]                                      
		                                                              
		ldr		r0, =MECR_VALUE                                       
		str		r0, [r12, #MECR]                                      
		                                                              
		ldr		r0, =MCMEM0_VALUE                                     
		str		r0, [r12, #MCMEM0]                                    
		                                                              
		ldr		r0, =MCMEM1_VALUE                                     
		str		r0, [r12, #MCMEM1]                                    
		                                                              
		ldr		r0, =MCATT0_VALUE                                     
		str		r0, [r12, #MCATT0]                                    
		                                                              
		ldr		r0, =MCATT1_VALUE                                     
		str		r0, [r12, #MCATT1]                                    
		                                                              
		ldr		r0, =MCIO0_VALUE
		str		r0, [r12, #MCIO0]                                     
		                                                              
		ldr		r0, =MCIO1_VALUE                                      
		str		r0, [r12, #MCIO1]                                     
                                                                                                         
		ldr		r0, =MDREFR_VALUE                                     
		ldr		r3, [r12, #MDREFR]                                    
		ldr		r1, =0xFFF                                            
		and		r0, r0, r1                                            
		                                                  
		bic		r3, r3, r1                                                                               
		bic		r3, r3, #0x03800000                                                      
		orr		r3, r3, r0                                                                               
		                                                                                     
		;Write it back                                                                                       
		str		r3, [r12, #MDREFR]                                                                       
		                                                                                                                                                   
		ldr		r0, =MDREFR_VALUE                                                                        
		ldr		r1, =0xF6000
		and		r0, r0, r1                                                               
		bic		r3, r3, r1                                                                               
		orr		r3, r3, r0                                                               
		                                                                                     
		str		r3, [r12, #MDREFR]                                                                       
		ldr		r3, [r12, #MDREFR]                                                       
		                                                                                     
		bic		r3, r3, #0x00400000                                                                      
		str		r3, [r12, #MDREFR]                                                                       
		                                                                                     
		ldr		r0, =MDREFR_VALUE                                                        
		ldr		r1, =0x03809000                                                          
		and		r0, r0, r1                                                               
		orr		r3, r3, r0                                                               
		str		r3, [r12, #MDREFR]                                                                       
		nop
		nop
		                                                                                     
		;Step 4 in Intel's code                                                                          
		ldr		r0, =MDCNFG_VALUE
		                                                                                     
		;disable all sdram banks
		bic		r0, r0, #0x00000003
		bic		r0, r0, #0x00030000
		                                                                                     
		;program banks 0/1 for 32 bit bus width
		bic		r0, r0, #0x00000004
		                                                                                     
		;test with 16 bit bus width                                                                      
		;      orr     r0, r0, #0x00000004                                                                       
		                                                                                     
		;write MDCNFG, without enabling SDRAM banks                                                      
		str		r0, [r12, #MDCNFG]
		                                                                                     
		;Step 5 in Intel's code
		ldr		r0, =OSCR
		mov		r1, #0
		str		r1, [r0]
		                                                                                     
		;pause for approx 200 usecs                                                                      
		ldr		r4, =0x300                                                                               
                                                                                                         
sdram_dly                                                                                                
		ldr		r1, [r0]                                                                                 
		cmp		r4, r1                                                                                   
		bgt		sdram_dly                                                                                
		                                                                                         
		;Step 6 in Intel's code                                                                          
		;turn everything off                                                                             
		mov		r0, #0x78                                                                                
		mcr		p15, 0, r0, c1, c0, 0                                                                    
		                                                                                         
		                                                                                         
		;Step 7 in Intel's code                                                                          
		;Access memory that has not been enabled for CBR refresh cycles (8)                              
		ldr		r0, =SDRAM_BASE                                                                  
		str		r0, [r0]                                                                                 
		str		r0, [r0]                                                                                 
		str		r0, [r0]                                                                                 
		str		r0, [r0]                                                                                 
		str		r0, [r0]                                                                                 
		str		r0, [r0]                                                                                 
		str		r0, [r0]                                                                                 
		str		r0, [r0]                                                                                 
		                                                                                         
		;Step 8 is blank in Intel's code, though they mention dcache should                              
		;be enabled here if it is desired (we don't care)                                                
		                                                                                         
		                                                                                         
		;Step 9                                                                                          
		ldr		r0, [r12, #MDCNFG]
		                                                                                         
		;enable bank 0 (what about bank 1?)
		orr		r0, r0, #0x00000001
		str		r0, [r12, #MDCNFG]
		                                                                                         
		;Step 10                                                                                         
		;write MDMRS again                                                                               
		ldr		r0, =MDMRS_VALUE
		str		r0, [r12, #MDMRS]		                                                                                         
		                                                                                         
		;Step 11                                                                                         
		;are we A1_Cotulla?                                                                              
		ldr		r0, [r12, #MDREFR]
		                                                                                         
		ldr		r11, =0xFFEFFFFF
		and		r0, r0, r11
		                                                                                         
		str		r0, [r12, #MDREFR]
		
		mov		pc, r10

;        /* Subroutine that sends a byte over the serial port. */
;        /* The byte is in r0 */
        EXPORT        print_byte        

print_byte
		stmfd	sp!,{r1 - r12, lr}                ; push(추가된 부분)

print_byte1
;        /* Wait for room in the tx fifo */
;        mov     r1, #0x40000000
;        add     r1, r1, #0x100000

		ldr		r1, =FFUART_BASE
		ldr		r1, [r1, #FFLSR]
		ands	r1, r1, #0x20
		beq		print_byte1

;        mov     r1, #0x40000000
;        add     r1, r1, #0x100000
		ldr		r1, =FFUART_BASE
		str		r0, [r1, #FFTHR]
;        mov		pc, lr 
		ldmfd	sp!,{r1 - r12, pc}                ; pop(추가된 부분)

    	
	END