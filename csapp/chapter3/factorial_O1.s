	.file	"factorial.c"
	.text
	.globl	fact_for
	.type	fact_for, @function
fact_for:
.LFB0:
	.cfi_startproc
	endbr64
	cmpq	$1, %rdi
	jle	.L4
	addq	$1, %rdi
	movl	$1, %edx
	movl	$2, %eax
.L3:
	imulq	%rax, %rdx
	addq	$1, %rax
	cmpq	%rdi, %rax
	jne	.L3
.L1:
	movq	%rdx, %rax
	ret
.L4:
	movl	$1, %edx
	jmp	.L1
	.cfi_endproc
.LFE0:
	.size	fact_for, .-fact_for
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	endbr64
	movl	$1, %edi
	call	fact_for
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
