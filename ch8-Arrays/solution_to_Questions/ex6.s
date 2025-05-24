	.file	"ex6.c"
	.text
	.p2align 4
	.globl	try1
	.type	try1, @function
try1:
.LFB0:
	.cfi_startproc
	testl	%esi, %esi
	jle	.L4
	movslq	%esi, %rsi
	xorl	%eax, %eax
	leaq	(%rdi,%rsi,4), %rdx
	.p2align 4
	.p2align 4
	.p2align 3
.L3:
	addl	(%rdi), %eax
	addq	$4, %rdi
	cmpq	%rdx, %rdi
	jne	.L3
	ret
	.p2align 4,,10
	.p2align 3
.L4:
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	try1, .-try1
	.p2align 4
	.globl	try2
	.type	try2, @function
try2:
.LFB1:
	.cfi_startproc
	testl	%esi, %esi
	je	.L10
	movl	%esi, %esi
	xorl	%eax, %eax
	leaq	(%rdi,%rsi,4), %rdx
	.p2align 4
	.p2align 4
	.p2align 3
.L9:
	addq	$4, %rdi
	addl	-4(%rdi), %eax
	cmpq	%rdx, %rdi
	jne	.L9
	ret
	.p2align 4,,10
	.p2align 3
.L10:
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE1:
	.size	try2, .-try2
	.ident	"GCC: (Debian 14.2.0-19) 14.2.0"
	.section	.note.GNU-stack,"",@progbits
