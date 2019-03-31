## hello.c convert to assemble file 

```as
.section	__TEXT,__text,regular,pure_instructions
.build_version macos, 10, 14
.globl	_main  ## -- Begin function main
.p2align	4, 0x90
```
以上是汇编文件的前几行代码，这里是汇编指令，`.section`指令指定接下来会执行哪一段。`.global`指令说明`_main`是一个外部符号，即`main()`函数，表明这个符号是外部可见的，因为系统需要调用它来执行文件。`.p2align`指令指明后面代码的对齐方式，按照`16(2^4)`字节对齐，如果需要用`0x90`对齐。

接下来是`main()`函数头部：

```as
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
```
`.cfi_startproc`指令通常用于函数的开始处。CFI是调用帧信息(Call Frame Information)的缩写。`.cfi_startproc`指令给了函数一个`.eh_frame`入口，这个入口包含了一些调用栈的信息（抛出异常时也是用其来展开调用帧堆栈的）。这个指令也会发送一些和具体平台相关的指令给CFI。它与`.cfi_endproc`指令相匹配，以此标记出`main()`函数结束的地方。

接着是另外一个label`## %bb.0:`。然后，终于，看到第一句汇编代码：`pushq %rbp`。从这里开始事情开始变得有趣。在 OS X上，我们会有 X86_64 的代码，对于这种架构，有一个东西叫做*ABI ( 应用二进制接口 application binary interface)*，*ABI*指定了函数调用是如何在汇编代码层面上工作的。在函数调用期间，*ABI*会让`rbp`寄存器 (基础指针寄存器 base pointer register) 被保护起来。当函数调用返回时，确保`rbp`寄存器的值跟之前一样，这是属于`main`函数的职责。`pushq %rbp`将`rbp`的值`push`到栈中，以便我们以后将其`pop`出来。

接下来是两个CFI指令：`.cfi_def_cfa_offset 16`和`.cfi_offset %rbp, -16`。这将会输出一些关于生成调用堆栈展开和调试的信息。我们改变了堆栈和基础指针，而这两个指令可以告诉编译器它们都在哪儿，或者更确切的，它们可以确保之后调试器要使用这些信息时，能找到对应的东西。

接下来，`movq %rsp, %rbp`将把局部变量放置到栈上。`subq $32, %rsp`将栈指针移动`32`个字节，也就是函数会调用的位置。我们先将老的栈指针存储到`rbp`中，然后将此作为我们局部变量的基址，接着我们更新堆栈指针到我们将会使用的位置。

```as
	leaq	L_.str(%rip), %rax
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rax, %rdi
	movb	$0, %al
	callq	_printf
	xorl	%ecx, %ecx
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	movl	%ecx, %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"hello world\n"


.subsections_via_symbols
```



