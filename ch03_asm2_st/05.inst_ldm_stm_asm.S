
	.global	asm_stm
asm_stm:
	mov	r1, #10
	mov	r3, #30
	mov	r4, #40
	mov	r5, #50

	stmia	r0, {r1, r3-r5}
	mov	pc, lr
	

	.global	asm_ldm_stm
asm_ldm_stm:
	ldmia	r0, {r6-r9}
	stmia	r1, {r6-r9}

	mov	pc, lr



