#include <stdio.h>
#include <unistd.h>

int main()
{
    int i, j;

    /*
    for (;;){
        /// 如果输入字符，则会不停的输出第一句。
        /// 因为scanf只会接收整数，输入的字符会被放入输入缓存区。
        /// 由于缓存区非空，所以scanf直接去缓存区拿字符。
        /// 然而拿到的字符不是整数，就又回到第一句，字符又一次被放入缓存区，陷入死循环。
        fputs("Please input a integer: ",stdout);
        scanf("%d",&i);
        printf("%d\n",i);
    }
    */

    /* 每隔一秒，打印a */
    for (i = 0; i < 10; i++)
    {
        printf("a");
        fflush(stdout);
        sleep(1);
    }
    /* 10秒后，直接输出一堆b */
    for (j = 0; j < 10; j++)
    {
        printf("b");
        sleep(1);
    }
    return 0;
}