#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int myglobal;
// 定义一个互斥对象
pthread_mutex_t mymutex = PTHREAD_MUTEX_INITIALIZER;
void *thread_func(void *arg)
{
    int i, j;
    for (i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&mymutex);
        j = myglobal;
        j = j + 1;
        printf(".");
        fflush(stdout);
        sleep(1);
        myglobal = j;
        pthread_mutex_unlock(&mymutex);
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

    /// 多线程访问同一个变量时，加一个互斥对象锁，防止多线程同时访问，造成不可控的结果。
    /// 线程a试图对一个互斥对象加锁，如果线程b已经加锁了，则线程a进入休眠，一旦线程b释放了互斥对象后，线程a会对互斥对象加锁。
    for (i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&mymutex);
        myglobal = myglobal + 1;
        pthread_mutex_unlock(&mymutex);
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