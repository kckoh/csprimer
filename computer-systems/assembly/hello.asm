global _start

section .data
    msg db 'Hello, Assembly!', 0x0a
    len_msg equ $ - msg

section .text
_start:
    ; write syscall to output
    mov rax, 0x01
    mov rdi, 1
    mov rsi, msg
    mov rdx, len_msg
    syscall
    ; exit code with 0
    mov rax, 0x3c
    mov rdi, 0
    syscall
