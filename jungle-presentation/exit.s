.section .data
msg:
    .ascii "Hello World!!!\n"
len = . - msg

.section .text

.global _start

_start:


    mov $0x01, %rax
    mov $0x01, %rdi
    mov $msg, %rsi
    mov $len,   %rdx
    syscall


    mov $0x3c, %rax
    mov $0, %rdi
    syscall
