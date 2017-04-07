	.file	"basics-of-pointers.c"
	.section	.rodata
.LC0:
	.string	"Manikant"
.LC1:
	.string	"%c\n"
.LC2:
	.string	"GATE-2017"
.LC3:
	.string	"%d\n"
.LC4:
	.string	"%c%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	movl	$.LC0, 24(%esp)
	movl	$0, 28(%esp)
	movl	24(%esp), %eax
	addl	$1, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edx
	movl	24(%esp), %eax
	addl	$4, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	subl	%eax, %edx
	movl	24(%esp), %eax
	addl	%edx, %eax
	movl	%eax, (%esp)
	call	puts
	movl	24(%esp), %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	printf
	movl	$.LC2, (%esp)
	call	printf
	movl	%eax, 4(%esp)
	movl	$.LC3, (%esp)
	call	printf
	movl	28(%esp), %eax
	leal	1(%eax), %edx
	movl	%edx, 28(%esp)
	movl	%eax, %edx
	movl	24(%esp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	28(%esp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$.LC4, (%esp)
	call	printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
