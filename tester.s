	.text
	.file	"tester.i"
	.globl	f
	.align	16, 0x90
	.type	f,@function
f:                                      # @f
# BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	8(%ebp), %eax
	movl	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	%eax, -8(%ebp)
.LBB0_1:                                # =>This Inner Loop Header: Depth=1
	movl	-4(%ebp), %eax
	movl	%eax, %ecx
	addl	$4, %ecx
	movl	%ecx, -4(%ebp)
	cmpl	$0, 4(%eax)
	je	.LBB0_3
# BB#2:                                 #   in Loop: Header=BB0_1 Depth=1
	jmp	.LBB0_1
.LBB0_3:
	movl	-4(%ebp), %eax
	movl	-8(%ebp), %ecx
	subl	%ecx, %eax
	sarl	$2, %eax
	addl	$8, %esp
	popl	%ebp
	retl
.Ltmp0:
	.size	f, .Ltmp0-f

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
# BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	12(%ebp), %eax
	movl	8(%ebp), %ecx
	leal	.L.str, %edx
	movl	$0, -4(%ebp)
	movl	%ecx, -8(%ebp)
	movl	%eax, -12(%ebp)
	movl	%edx, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	calll	f
	leal	.L.str1, %ecx
	movl	%ecx, (%esp)
	movl	%eax, 4(%esp)
	calll	printf
	movl	$0, %ecx
	movl	%eax, -20(%ebp)         # 4-byte Spill
	movl	%ecx, %eax
	addl	$40, %esp
	popl	%ebp
	retl
.Ltmp1:
	.size	main, .Ltmp1-main

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"GATECS"
	.size	.L.str, 7

	.type	.L.str1,@object         # @.str1
.L.str1:
	.asciz	"%d\n"
	.size	.L.str1, 4


	.ident	"Ubuntu clang version 3.5.0-4ubuntu2~trusty2 (tags/RELEASE_350/final) (based on LLVM 3.5.0)"
	.section	".note.GNU-stack","",@progbits
