global _start

section .data
    hello db 'Hello World from Assembly!', 0x0a
    len_hello equ $ - hello

section .text
_start:
    ; order of the register args
    ; rax, rdi, rsi, rdx
    ; syscall for write
    mov rax, 0x01
    mov rdi, 1
    mov rsi, hello
    mov rdx, len_hello
    syscall
    ; exit syscall
    mov rax, 0x3c
    mov rdi, 0
    syscall