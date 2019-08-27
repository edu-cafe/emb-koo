
	.global	asm_str
asm_str:

	str	r1, [r0]

	add	r1, r1, #1
	add	r0, r0, #4
	str	r1, [r0]

	add	r1, r1, #1
	add	r0, r0, #4
	str	r1, [r0]

	add	r1, r1, #1
	add	r0, r0, #4
	str	r1, [r0]

	add	r1, r1, #1
	add	r0, r0, #4
	str	r1, [r0]

	mov r0, #5
	mov	pc, lr


	.global	asm_ldr_str
asm_ldr_str:
	ldr	r4, [r0]
	str	r4, [r1]

	add	r0, r0, #4
	add	r1, r1, #4
	ldr	r4, [r0]
	str	r4, [r1]

	add	r0, r0, #4
	add	r1, r1, #4
	ldr	r4, [r0]
	str	r4, [r1]

	add	r0, r0, #4
	add	r1, r1, #4
	ldr	r4, [r0]
	str	r4, [r1]

	add	r0, r0, #4
	add	r1, r1, #4
	ldr	r4, [r0]
	str	r4, [r1]

	mov r0, #5
	mov	pc, lr

