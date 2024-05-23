	.text
	.def	@feat.00;
	.scl	3;
	.type	0;
	.endef
	.globl	@feat.00
.set @feat.00, 0
	.file	"One Lang"
	.def	main;
	.scl	2;
	.type	32;
	.endef
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
main:                                   # @main
.seh_proc main
# %bb.0:                                # %entry
	pushq	%rbp
	.seh_pushreg %rbp
	subq	$32, %rsp
	.seh_stackalloc 32
	leaq	32(%rsp), %rbp
	.seh_setframe %rbp, 32
	.seh_endprologue
	callq	__main
	movl	$10, %ecx
	movl	$20, %edx
	movl	$20, %r8d
	callq	add_num
	leaq	.L.str(%rip), %rcx
	movl	%eax, %edx
	callq	printf
	movl	$42, %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.seh_endproc
                                        # -- End function
	.def	add_num;
	.scl	2;
	.type	32;
	.endef
	.globl	add_num                         # -- Begin function add_num
	.p2align	4, 0x90
add_num:                                # @add_num
# %bb.0:
                                        # kill: def $edx killed $edx def $rdx
                                        # kill: def $ecx killed $ecx def $rcx
	leal	(%rcx,%rdx), %eax
	imull	%r8d, %eax
	retq
                                        # -- End function
	.section	.rdata,"dr"
.L.str:                                 # @.str
	.asciz	"%d\n"

