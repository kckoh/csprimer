.section .data
msg:
    .ascii "Hello\n"
len = . - msg

.section .text
.global _start
_start:
    mov $1, %rax              # write
    mov $1, %rdi              # fd = stdout
    mov $msg, %rsi
	mov $6, %rdx            # count = 6
    syscall

    mov $60, %rax             # exit
    xor %rdi, %rdi            # status = 0
    syscall

