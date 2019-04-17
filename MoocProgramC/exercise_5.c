#include <stdio.h>
#include <string.h>
#include <math.h>

/* 素数之和 求第n个素数到第m个素数之间所有素数之和 */
// 判断数字是否是素数
int is_prime(int num)
{
    if (num < 2)
    {
        return 0;
    }
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return 0;
            break;
        }
    }
    return 1;
}

void prime_sum()
{
    int n, m;
    scanf("%d %d", &n, &m);
    if (n < 0 || m > 200){
        return;
    }
    if (n > m){
        return;
    }

    int sort = 0;
    int sum = 0;
    for (int i = 2; ; i++)
    {
        if (is_prime(i) == 1){
            sort ++;
            if (sort >= n){
                // 找到第n个素数，开始累加
                sum += i;
            }
            if (sort == m){
                break;
            }
        }
    }
    printf("%d\n",sum);
}

/*
题目内容：
你的程序要读入一个整数，范围是[-100000,100000]。然后，用汉语拼音将这个整数的每一位输出出来。
如输入1234，则输出：
yi er san si
注意，每个字的拼音之间有一个空格，但是最后的字后面没有空格。
当遇到负数时，在输出的开头加上“fu”，如-2341输出为：
fu er san si yi

输入样例：
-30

输出样例：
fu san ling
*/
void read_num(int num)
{

    char *hans[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    /* 取出整数的每个位置上的数字 */
    int digs[6] = {0};
    int len = 0;

    unsigned int pure_num = num;
    if (num < 0)
    {
        pure_num = 0 - num;
        printf("fu ");
    }
    do
    {
        int dig = pure_num % 10;
        pure_num /= 10;
        digs[len] = dig;
        len++;

    } while (pure_num > 0);

    for (int i = len - 1; i >= 0; i--)
    {
        int d = digs[i];
        char *h = hans[d];
        printf("%s%s", h, i != 0 ? " " : "");
    }
}
int main()
{
  
    prime_sum();
    return 0;
}