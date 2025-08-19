global _start

section .data


section .text
_start:
    ;mov rax, 0x01
    ;syscall
    ; exit code with 0
    mov rax, 0x3c
    mov rdi, 0
    syscall
