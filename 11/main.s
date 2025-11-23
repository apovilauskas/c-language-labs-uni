	.file	"main.c"
	.text
	.globl	fillArray
	.def	fillArray;	.scl	2;	.type	32;	.endef
	.seh_proc	fillArray
fillArray:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	16(%rbp), %eax
	addl	$1, %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rcx
	call	malloc
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movl	16(%rbp), %edx
	movl	%edx, (%rax)
	movl	$1, -4(%rbp)
	jmp	.L2
.L3:
	call	rand
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,4), %rcx
	movq	-16(%rbp), %rdx
	leaq	(%rcx,%rdx), %r8
	movslq	%eax, %rdx
	imulq	$680390859, %rdx, %rdx
	shrq	$32, %rdx
	sarl	$4, %edx
	movl	%eax, %ecx
	sarl	$31, %ecx
	subl	%ecx, %edx
	imull	$101, %edx, %ecx
	subl	%ecx, %eax
	movl	%eax, %edx
	movl	%edx, (%r8)
	addl	$1, -4(%rbp)
.L2:
	movl	-4(%rbp), %eax
	cmpl	16(%rbp), %eax
	jle	.L3
	movq	-16(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "%d \0"
	.text
	.globl	printArray
	.def	printArray;	.scl	2;	.type	32;	.endef
	.seh_proc	printArray
printArray:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	$1, -4(%rbp)
	jmp	.L6
.L7:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, %edx
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	printf
	addl	$1, -4(%rbp)
.L6:
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, -4(%rbp)
	jle	.L7
	nop
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC1:
	.ascii "file1.bin\0"
.LC2:
	.ascii "file2.bin\0"
.LC3:
	.ascii "all good\0"
.LC4:
	.ascii "something's wrong\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	call	__main
	movl	$50, %ecx
	call	fillArray
	movq	%rax, -8(%rbp)
	movl	$50, %ecx
	call	fillArray
	movq	%rax, -16(%rbp)
	movl	$50, %ecx
	call	fillArray
	movq	%rax, -24(%rbp)
	movq	-8(%rbp), %rax
	leaq	.LC1(%rip), %rdx
	movq	%rax, %rcx
	call	saveToFile
	movq	-24(%rbp), %rax
	leaq	.LC1(%rip), %rdx
	movq	%rax, %rcx
	call	saveToFile
	movq	-8(%rbp), %rax
	leaq	.LC1(%rip), %rdx
	movq	%rax, %rcx
	call	loadFromFile
	movq	-16(%rbp), %rax
	leaq	.LC2(%rip), %rdx
	movq	%rax, %rcx
	call	saveToFile
	movq	-24(%rbp), %rax
	leaq	.LC2(%rip), %rdx
	movq	%rax, %rcx
	call	loadFromFile
	movq	-16(%rbp), %rax
	leaq	.LC2(%rip), %rdx
	movq	%rax, %rcx
	call	loadFromFile
	movq	.refptr.readCount(%rip), %rax
	movl	(%rax), %eax
	cmpl	$3, %eax
	jne	.L9
	movq	.refptr.writeCount(%rip), %rax
	movl	(%rax), %eax
	cmpl	$3, %eax
	jne	.L9
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	puts
	jmp	.L10
.L9:
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	call	puts
.L10:
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	free
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	free
	movq	-24(%rbp), %rax
	movq	%rax, %rcx
	call	free
	movl	$0, %eax
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (Rev2, Built by MSYS2 project) 14.2.0"
	.def	malloc;	.scl	2;	.type	32;	.endef
	.def	rand;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	saveToFile;	.scl	2;	.type	32;	.endef
	.def	loadFromFile;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	free;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr.writeCount, "dr"
	.globl	.refptr.writeCount
	.linkonce	discard
.refptr.writeCount:
	.quad	writeCount
	.section	.rdata$.refptr.readCount, "dr"
	.globl	.refptr.readCount
	.linkonce	discard
.refptr.readCount:
	.quad	readCount
