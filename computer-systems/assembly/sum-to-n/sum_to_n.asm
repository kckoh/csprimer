section .text
global sum_to_n
sum_to_n:
	; rdi -> argument from the function
	; rbx -> total sum
	; rax -> int i
	mov rbx, 0
	mov rcx, 1
.loop_start:
	cmp rcx, rdi
	; rcx - rdi or i < n
	jg .loop_end
	; otherwise
	; add i to the rax and jump to the loop_start
	add rbx, rcx
	inc rcx
	jmp .loop_start
.loop_end:
	mov rax, rbx
	ret
	
