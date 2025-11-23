	.file	"file.c"
	.text
	.globl	writeCount
	.bss
	.align 4
writeCount:
	.space 4
	.globl	readCount
	.align 4
readCount:
	.space 4
	.section .rdata,"dr"
.LC0:
	.ascii "wb\0"
	.text
	.globl	saveToFile
	.def	saveToFile;	.scl	2;	.type	32;	.endef
	.seh_proc	saveToFile
saveToFile:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	24(%rbp), %rax
	leaq	.LC0(%rip), %rdx
	movq	%rax, %rcx
	call	fopen
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	.L4
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-8(%rbp), %rcx
	movq	16(%rbp), %rax
	movq	%rcx, %r9
	movq	%rdx, %r8
	movl	$4, %edx
	movq	%rax, %rcx
	call	fwrite
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	movl	writeCount(%rip), %eax
	addl	$1, %eax
	movl	%eax, writeCount(%rip)
	jmp	.L1
.L4:
	nop
.L1:
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC1:
	.ascii "rb\0"
	.text
	.globl	loadFromFile
	.def	loadFromFile;	.scl	2;	.type	32;	.endef
	.seh_proc	loadFromFile
loadFromFile:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	24(%rbp), %rax
	leaq	.LC1(%rip), %rdx
	movq	%rax, %rcx
	call	fopen
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	.L8
	movq	-8(%rbp), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, %r9
	movl	$1, %r8d
	movl	$4, %edx
	movq	%rax, %rcx
	call	fread
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	movslq	%eax, %rdx
	movq	16(%rbp), %rax
	addq	$4, %rax
	movq	-8(%rbp), %rcx
	movq	%rcx, %r9
	movq	%rdx, %r8
	movl	$4, %edx
	movq	%rax, %rcx
	call	fread
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	movl	readCount(%rip), %eax
	addl	$1, %eax
	movl	%eax, readCount(%rip)
	jmp	.L5
.L8:
	nop
.L5:
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (Rev2, Built by MSYS2 project) 14.2.0"
	.def	fopen;	.scl	2;	.type	32;	.endef
	.def	fwrite;	.scl	2;	.type	32;	.endef
	.def	fclose;	.scl	2;	.type	32;	.endef
	.def	fread;	.scl	2;	.type	32;	.endef
