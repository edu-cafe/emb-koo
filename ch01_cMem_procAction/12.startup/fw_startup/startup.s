;*******************************************************************
;                           ARM
;                Assembly Programming 실습
;
;                XScale Compatible Target
;
; File : startup.s
; By   : Kim, Soo Hyun
;*******************************************************************
;

	IMPORT		ResetProcess
	IMPORT		print_byte
	IMPORT		print_str
	IMPORT		get_byte

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;   Program Start Up
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	AREA    STARTUP, CODE, READONLY

	ENTRY

	b       ResetHandler 
;	b       UndefHandler
;	b       SWIHandler
;	b       PAbortHandler
;	b       DAbortHandler  
;	b       UnusedHandler
;	b       IRQHandler
;	b       FIQHandler	
	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;                                                
;;;;;     Reset                                                                        
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; 
ResetHandler
	bl		ResetProcess
	b		assem_main
                                                                                   

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;                                                
;;;;;     응용 프로그램 시작                                                                      
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; 
assem_main
	
	mov		r0, #'O'
	bl		print_byte
	
	mov		r0, #'K'
	bl		print_byte
	
	mov		r0, #'!'
	bl		print_byte
	
	mov		r0, #'!'
	bl		print_byte
	
	
	
loop						;; NOP, Infinite Loop
	mov		r0, r0
	b		loop
	
    	
	END