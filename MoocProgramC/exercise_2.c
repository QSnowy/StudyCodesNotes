#include <stdio.h>

int main()
{
	/* 
	程序每次读入一个正三位数，然后输出逆序的数字。
	注意，当输入的数字含有结尾的0时，输出不应带有前导的0。比如输入700，输出应该是7。

	要提取3位整数的单个数字.
	个位数：对10取余，
	十位数：对100取余再除以10；
	百位数：直接除以100即可
	*/
	int num;
	scanf("%d", &num);
	int reverseCount = num / 100 + num % 100 / 10 * 10 + num % 10 * 100;
	printf("%d\n", reverseCount);
	return 0;
}
