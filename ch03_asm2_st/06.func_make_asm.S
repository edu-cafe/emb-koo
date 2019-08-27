
	.extern print_data
	.global	asm_sum_1_10
asm_sum_1_10:
	mov	r5, #1		// r5(i)
	mov	r6, #0		// r6(sum)
sum_loop:
	cmp	r5, #10
	bgt	end_sum_loop
	add	r6, r6, r5	// sum += i
	add	r5, r5, #1	// i++
	b	sum_loop
	
end_sum_loop:	
	mov	r0, r6

	mov	pc, lr


	.global	asm_sum_1_x
asm_sum_1_x:
	mov	r5, #1		// r5(i)
	mov	r6, #0		// r6(sum)
sumx_loop:
	cmp	r5, r0
	bgt	end_sumx_loop
	add	r6, r6, r5	// sum += i
	add	r5, r5, #1	// i++
	b	sumx_loop
	
end_sumx_loop:	
	mov	r0, r6

	mov	pc, lr


	.global	asm_sum_x_y
asm_sum_x_y:
	mov	r5, r0		// r5(i)
	mov	r6, #0		// r6(sum)
sumxy_loop:
	cmp	r5, r1
	bgt	end_sumxy_loop
	add	r6, r6, r5	// sum += i
	add	r5, r5, #1	// i++
	b	sumxy_loop
	
end_sumxy_loop:	
	mov	r0, r6

	mov	pc, lr




