	.text
	.file	"order_of_eval.c"
	.globl	A
	.align	16, 0x90
	.type	A,@function
A:                                      # @A
# BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	leal	.L.str, %eax
	movl	%eax, (%esp)
	calll	printf
	movl	$1, %ecx
	movl	%eax, -4(%ebp)          # 4-byte Spill
	movl	%ecx, %eax
	addl	$8, %esp
	popl	%ebp
	retl
.Ltmp0:
	.size	A, .Ltmp0-A

	.globl	B
	.align	16, 0x90
	.type	B,@function
B:                                      # @B
# BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	leal	.L.str1, %eax
	movl	%eax, (%esp)
	calll	printf
	movl	$2, %ecx
	movl	%eax, -4(%ebp)          # 4-byte Spill
	movl	%ecx, %eax
	addl	$8, %esp
	popl	%ebp
	retl
.Ltmp1:
	.size	B, .Ltmp1-B

	.globl	C
	.align	16, 0x90
	.type	C,@function
C:                                      # @C
# BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	leal	.L.str2, %eax
	movl	%eax, (%esp)
	calll	printf
	movl	$3, %ecx
	movl	%eax, -4(%ebp)          # 4-byte Spill
	movl	%ecx, %eax
	addl	$8, %esp
	popl	%ebp
	retl
.Ltmp2:
	.size	C, .Ltmp2-C

	.globl	D
	.align	16, 0x90
	.type	D,@function
D:                                      # @D
# BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	leal	.L.str3, %eax
	movl	%eax, (%esp)
	calll	printf
	movl	$4, %ecx
	movl	%eax, -4(%ebp)          # 4-byte Spill
	movl	%ecx, %eax
	addl	$8, %esp
	popl	%ebp
	retl
.Ltmp3:
	.size	D, .Ltmp3-D

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
# BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	$0, -4(%ebp)
	calll	A
	movl	%eax, -8(%ebp)          # 4-byte Spill
	calll	B
	movl	%eax, -12(%ebp)         # 4-byte Spill
	calll	C
	movl	%eax, -16(%ebp)         # 4-byte Spill
	calll	D
	leal	.L.str4, %ecx
	movl	%ecx, (%esp)
	movl	-8(%ebp), %ecx          # 4-byte Reload
	movl	%ecx, 4(%esp)
	movl	-12(%ebp), %ecx         # 4-byte Reload
	movl	%ecx, 8(%esp)
	movl	-16(%ebp), %ecx         # 4-byte Reload
	movl	%ecx, 12(%esp)
	movl	%eax, 16(%esp)
	calll	printf
	movl	$0, %ecx
	movl	%eax, -20(%ebp)         # 4-byte Spill
	movl	%ecx, %eax
	addl	$40, %esp
	popl	%ebp
	retl
.Ltmp4:
	.size	main, .Ltmp4-main

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"Hello A\n"
	.size	.L.str, 9

	.type	.L.str1,@object         # @.str1
.L.str1:
	.asciz	"Hello B\n"
	.size	.L.str1, 9

	.type	.L.str2,@object         # @.str2
.L.str2:
	.asciz	"Hello C\n"
	.size	.L.str2, 9

	.type	.L.str3,@object         # @.str3
.L.str3:
	.asciz	"Hello D\n"
	.size	.L.str3, 9

	.type	.L.str4,@object         # @.str4
.L.str4:
	.asciz	"%d %d %d %d \n"
	.size	.L.str4, 14


	.ident	"Ubuntu clang version 3.5.0-4ubuntu2~trusty2 (tags/RELEASE_350/final) (based on LLVM 3.5.0)"
	.section	".note.GNU-stack","",@progbits
