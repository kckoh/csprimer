section .text
global binary_convert
binary_convert:
	; what gets stored in the register is the ascii
	; 30 -> 0
	; 31 -> 1
	; 0 is the null pointer
	; shift left first then add or no depending on the ascii value
	; set each bit using bts
	mov rdi, 0 ; num of binary
	mov r8, 0; for loop i pointer
	mov r9, 0
	.loop_start:
		cmp byte [rax+r8], 0x31
		je .one ; check zf = 1
		cmp byte [rax+r8], 0
		je .end ; check if it's null terminator
		inc r8
		shl r9, 1
		jmp .loop_start
	.one:
		shl r9, 1
		inc r9
		inc r8
		jmp .loop_start
	.end:
		mov rax, r9
	ret
