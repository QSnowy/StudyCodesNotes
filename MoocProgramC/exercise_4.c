#include <stdio.h>

void feature_num(int num)
{
    /*
         数字       | 3 | 4 | 2 | 3 | 1 | 5 |
         数位       | 6 | 5 | 4 | 3 | 2 | 1 |
         数字奇偶    | o | e | e | o | o | o |
         数位奇偶    | e | o | e | o | e | o |
         奇偶一致    | 0 | 0 | 1 | 1 | 0 | 1 |
         二进制位值   | 32 | 16 | 8 | 4 | 2 | 1 |
         342315 -> 13
    */
    int count = 0;
    int ret = 0;
    while (num > 0)
    {
        count++;
        if (num % 10 % 2 == count % 2)
        {
            int digt = 1;
            for (int i = 1; i < count; i++)
            {
                digt *= 2;
            }
            ret += digt;
        }
        num /= 10;
    }
    printf("%d\n", ret);
}

int main()
{

    /**********奇偶个数************/
    // 读取一系列正整数，-1结束，输出奇数个数和偶数个数

    int num = 0;
    int oddCount = 0;
    int evenCount = 0;
    scanf("%d", &num);
    while (num != -1)
    {
        if (num % 2 == 0)
        {
            evenCount++;
        }
        else
        {
            oddCount++;
        }
        scanf("%d", &num);
    }
    printf("%d %d\n", oddCount, evenCount);

    /**********数组特征值************/

    int featureNum = 0;
    scanf("%d", &featureNum);
    feature_num(featureNum);

    return 0;
}