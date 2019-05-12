#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int myglobal;

void *thread_func(void *arg)
{

    int i, j;
    for (i = 0; i < 10; i++)
    {
        j = myglobal;
        j = j + 1;
        printf(".");
        fflush(stdout);
        sleep(1);
        myglobal = j;
    }
    return NULL;
}

int main()
{
    // 创建thread句柄
    pthread_t mythread;
    int i;
    // 创建新线程，执行thread_func任务。
    if (pthread_create(&mythread, NULL, thread_func, NULL))
    {
        printf("error creating thread.");
        abort();
    }

    /// 主线程和新线程同时对myglobal进行加一操作，两个线程是并发的，不是串行执行。
    /// 主线程+1，1s后新线程将旧址重新赋给myglobal
    for (i = 0; i < 10; i++)
    {
        myglobal = myglobal + 1;
        printf("m");
        /* 通常printf函数被调用后，会将内容存入到缓存区，等遇到\n的时候去打印，或者等到时间片轮转到系统的输出程序时。
        fflush()会让printf立马输出，然后清除缓存区 */
        fflush(stdout);
        sleep(1);
    }
    if (pthread_join(mythread, NULL))
    {
        printf("error joining thread.");
        abort();
    }
    printf("\n myglobal equals %d\n", myglobal);
    exit(0);
}