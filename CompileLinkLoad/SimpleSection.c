/*
 * SimpleSection.c
 * 
 * Linux: 
 * 
 * 编译源代码文件，-c 不链接
 * gcc -c SimpleSection.c
 * 
 * 查看各段的基本信息
 * objdump -h SimpleSection.o
 * 
 * 查看各段的长度
 * size SimpleSection.o
 *
 * 查看各段内容 -s 将段内容以16进制方式打印出来，-d将包含指令的段反汇编。
 * objdump -s -d SimpleSection.o
 * 
 */

int printf(const char *format, ...);

int global_init_var = 84;
int global_uninit_var;

void func1(int i)
{
	printf("%d\n", i);
}

int main(void)
{

	static int static_var = 85;
	static int static_var2;

	int a = 1;
	int b;
	func1(static_var + static_var2 + a + b);
	return a;
}
