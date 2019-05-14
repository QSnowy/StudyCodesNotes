#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutexattr_t attr;
pthread_mutex_t mutex;

void f();
void g();
void test();

struct
{
    int a;
    int b;
    int c;
} A;

void f()
{
    pthread_mutex_lock(&mutex);
    A.a++;
    g();
    A.c = 3;
    pthread_mutex_unlock(&mutex);
}

void g()
{
    pthread_mutex_lock(&mutex);
    A.b += A.a;
    printf("g fun is invoke\n");
    pthread_mutex_unlock(&mutex);
}

void test()
{
    /// 同一个互斥对象，如果对已锁定的互斥对象加锁，会造成死锁
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&mutex, &attr);
    f();
    printf("structure A.a = %d, A.b = %d, A.c = %d", A.a, A.b, A.c);
}

int main()
{
    test();
    return 0;
}