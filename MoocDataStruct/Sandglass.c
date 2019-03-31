#include <stdio.h>
#include <math.h>

int main()
{

    int count;
    char c;
    scanf("%d %c", &count, &c);
    if (count < 0)
    {
        printf("%d", count);
    }

    /* 所谓"沙漏形状"，是指每行输出奇数个符号；
         各行符号中心对齐；相邻两行符号数差2；
         符号数先从大到小顺序递减到1，再从小到大顺序递增；首尾符号数相等。
         给定任意N个符号，不一定能正好组成一个沙漏。要求打印出的沙漏能用掉尽可能多的符号。
         ***
          *
         ***
         */
    // 沙漏和 Sn = 2*n2 - 1;所以行数 n = sqrtf((Sn+1)/2);向下取整
    int n = sqrt((count + 1) / 2);
    int An = 2 * n - 1;
    int Sn = 2 * n * n - 1;
    int remainder = count - Sn;
    remainder = remainder > count ? count : remainder;
    for (int i = An; i >= 1; i -= 2)
    {
        int preCount = (An - i) / 2;
        int printCount = preCount + i;

        for (int m = 0; m < printCount; m++)
        {
            if (m < preCount)
            {
                printf(" ");
            }
            else if (m == printCount - 1)
            {
                printf("%c\n", c);
            }
            else
            {
                printf("%c", c);
            }
        }
    }
    for (int i = 3; i <= An; i += 2)
    {
        int preCount = (An - i) / 2;
        int printCount = preCount + i;
        for (int m = 0; m < printCount; m++)
        {
            if (m < preCount)
            {
                printf(" ");
            }
            else if (m == printCount - 1)
            {
                printf("%c\n", c);
            }
            else
            {
                printf("%c", c);
            }
        }
    }

    printf("%d\n", remainder);
    return 0;
}
