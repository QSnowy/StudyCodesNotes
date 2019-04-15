#include <stdio.h>
int main()
{
    // BJT -> UTC 相差8小时数
    /* UTC是世界协调时，BJT是北京时间，UTC时间相当于BJT减去8。
    现在，你的程序要读入一个整数，表示BJT的时和分。
    整数的个位和十位表示分，百位和千位表示小时。
    如果小时小于10，则没有千位部分；
    如果小时是0，则没有百位部分；
    如果小时不是0而分小于10分，需要保留十位上的0；
    如果小时是0而分小于10分的，则不需要保留十位上的0。
    如1124表示11点24分，而905表示9点5分，36表示0点36分，7表示0点7分。
     */

    int bjt = 0;
    // printf("请输入北京时间：");
    scanf("%d", &bjt);
    // 提取百位和千位数字
    int bjt_hour = bjt / 100;
    int bjt_min = bjt % 100;

    int utc_hour = bjt_hour - 8;
    if (utc_hour < 0)
    {
        utc_hour += 24;
    }
    int utc = utc_hour * 100 + bjt_min;
    printf("%d\n", utc);

    /* 分队列 
    班级第一次列队，通常老师会让同学按身高排成一列，然后1、2报数，喊到1的同学向前一步，就这样，队伍就变成两列了。
    假设现在一个班级有n个同学，并且他们已经按身高排成了一列，
    同学按身高从1到n编号，你能告诉我最后哪些编号的同学站在了第一列么?
    输入一个正整数，表示班级人数，按顺序输出所有在第一列同学的编号，每个编号用一个空格隔开，最后一个没有空格。
    */

    int count = 0;
    scanf("%d", &count);
    int last = count;
    if (count % 2 == 0)
    {
        last = count - 1;
    }
    for (int i = 1; i <= last; i += 2)
    {
        printf("%d%s", i, i == last ? "\n" : " ");
    }

    return 0;
}