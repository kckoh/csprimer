section .text
global index
index:
	; rdi: matrix
	; esi: rows
	; edx: cols
	; ecx: rindex
	; r8d: cindex
	; calculation -> cols(rax) * rindex(ecx) + cindex
	mov eax, edx
	imul eax, ecx
	add eax, r8d

	mov rax, [rdi + rax*4]
	ret
