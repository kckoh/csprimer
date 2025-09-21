.section .data       # directive: switch to data section
msg: 
    .ascii "Hello\n"           
len = 
.section .text
.global _start

_start:
	mov $1, %rax
	mov $1, %rdi
	mov $msg, %rsi 
	mov $5, %rdx
	syscall

	mov $60, %rax
	mov $0, %rdi
	syscall
