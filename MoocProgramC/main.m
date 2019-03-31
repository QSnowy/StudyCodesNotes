//
//  main.m
//  WeekTest
//
//  Created by Speed on 2018/5/13.
//  Copyright © 2018年 Speed. All rights reserved.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        /**********三位数逆序**********/
        // 要提取3位整数的单个数字，个位数：对10取余，十位数：对100取余再除以10；百位数：直接除以100即可
        /*
         int count = 0;
         scanf("%d",&count);
         int reverseCount = count / 100 +  count % 100 / 10 * 10 + count % 10 * 100;
         printf("%d\n",reverseCount);
         return 0;
         */
        
        /**********时间换算************/
        // BJT -> UTC 相差8小时数
        /*
         int bjt = 0;
         printf("请输入北京时间：");
         scanf("%d",&bjt);
         // 提取百位和千位数字
         int bjt_hour = bjt / 100;
         int bjt_min = bjt % 100;
         
         int utc_hour = bjt_hour - 8;
         if (utc_hour < 0){
         utc_hour += 24;
         }
         int utc = utc_hour * 100 + bjt_min;
         printf("UTC = %d\n", utc);
         */
        
        /**********分队列************/
        // 班级同学编号 取奇数编号
        /*
         int count = 0;
         scanf("%d", &count);
         int last = count;
         if (count % 2 == 0){
         last = count - 1;
         }
         for (int i = 1; i <= last; i += 2){
         printf("%d%s", i, i == last ? "\n" : " ");
         }
         */
        
        /**********奇偶个数************/
        // 读取一系列正整数，-1结束，输出奇数个数和偶数个数
        /*
         int num = 0;
         int oddCount = 0;
         int evenCount = 0;
         scanf("%d",&num);
         while (num != -1) {
         
         if (num % 2 == 0){
         
         evenCount ++;
         }else{
         
         oddCount ++;
         }
         scanf("%d",&num);
         }
         printf("%d %d\n",oddCount,evenCount);
         */
        
        /**********数组特征值************/
        /*
         数字       | 3 | 4 | 2 | 3 | 1 | 5 |
         数位       | 6 | 5 | 4 | 3 | 2 | 1 |
         数字奇偶    | o | e | e | o | o | o |
         数位奇偶    | e | o | e | o | e | o |
         奇偶一致    | 0 | 0 | 1 | 1 | 0 | 1 |
         二进制位值   | 32 | 16 | 8 | 4 | 2 | 1 |
         342315 -> 13
         */
        /*
         int num = 0;
         int count = 0;
         int ret = 0;
         scanf("%d",&num);
         while (num > 0) {
         count ++;
         if (num % 10 % 2 == count % 2){
         int digt = 1;
         for (int i = 1; i < count; i ++) {
         digt *= 2;
         }
         ret += digt;
         }
         num /= 10;
         }
         printf("%d\n",ret);
         */
        
    }
    return 0;
}

