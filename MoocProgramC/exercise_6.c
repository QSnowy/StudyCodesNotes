#include <stdio.h>
/* 高精度小数，最多小数点后200位。
10<=a<b<100，计算a/b的精确小数
 */

void precision(int a, int b)
{

    if (a < 10 || b >= 100)
    {
        return;
    }
    if (a >= b)
    {
        return;
    }

    // a*10 / b , a*10 % b * 10 /b
    int bit_count = 0;
    // 终止条件 a * 10 % b == 0,或者bit_count == 200;
    int remaind = a;
    int quotient = 0;

    printf("0.");
    while (remaind != 0 && bit_count < 200)
    {
        quotient = remaind * 10 / b;
        remaind = remaind * 10 % b;
        bit_count++;
        printf("%d", quotient);
    }
    printf("\n");
}

int main()
{
    int a, b;
    scanf("%d/%d", &a, &b);
    precision(a, b);
    return 0;
}