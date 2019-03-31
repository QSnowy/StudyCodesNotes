#include <stdio.h>

// 冒泡排序
void bubbleSort(int arr[], int n)
{
}
// 插入排序
void insertSort(int arr[], int n)
{
    /* 如同打扑克时，将牌从小到大排序；
  从牌堆摸一张牌，将摸到的牌，跟手中牌最后一张比较，如果大于最后一张，直接插入即可；
  如果小于最后一张牌，那么依次往前比较，直到摸到的牌，大于前一张牌，插入 */
  for (int a = 0; a < n; a ++){
      printf("%d,",arr[a]);
  }
    int p, i;
    for (int p = 1; p < n; p++)
    {
        // 摸入一张牌，第一张牌不用比较，tmp就是摸到的牌
        int tmp = arr[p];
        // 将摸到的牌，从后往前，依次跟手中其他牌比较，如果tmp小的话，就交换
        for (i = p; i > 0 && arr[i-1] > tmp; i--)
        {
            arr[i] = arr[i-1];
        }
        // 为tmp找到了新位置，赋值即可
        arr[i] = tmp;
    }
    printf("插入排序后的数组：\n");
    for (int m = 0; m < n; m++)
    {
        printf("%d,", arr[m]);
    }
}

int main()
{

    int A[] = {32, 8, 34, 21, 50, 76};
    int count = sizeof(A) / sizeof(A[0]);
    insertSort(A, count);

    return 0;
}