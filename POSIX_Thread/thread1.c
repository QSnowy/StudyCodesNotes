/* create thread demo */
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void *thread_fun(void *arg){
    int i;
    for (i = 0; i < 200; i ++){
        printf("Thread says hi! arg value = %c, address = %p\n",*(char *)arg, arg);
        sleep(1);
    }
    return NULL;
}

int main(){
    /* pthread_t == _opaque_pthread_t结构体类型指针，通常被成为线程id，被认为是一种线程句柄 */
    pthread_t mythread;
    // 0x7ffeea79866c
    char c = '5';
    char *pt = &c;

    /// pthread_create创建线程，如果成功返回0，失败返回非0。
    /// pthread_create(线程句柄指针，线程属性指针，线程启动后调用的函数名（函数返回后，线程会终止），调用函数的所需参数) 
    /// 如果线程创建成功，那么当前会有两个线程，一个是程序的主线程，另一个就是我们创建的新线程。
    /// 新线程结束后，会被停止，然后作为其清理过程的一部分，等待与另一个线程合并或者连接。
    if ( pthread_create( &mythread, NULL, thread_fun, pt)){
        printf("error creating thread");
        abort();
    }
    /// pthread_join(thread句柄，thread返回值？)，将两个线程合并，会等待thread里面的方法执行完毕再返回，
    /// 主线程休眠，等mythread线程里面的thread_fun执行结束，然后才回到主线程，继续执行退出代码。
    /// 如果不join的话，主线程不会等mythread，直接执行下面的退出代码。
    
    /* fork()系统调用创建新的进程，那么新进程就是子进程，原始进程就是父进程；
    如果让父进程等待子进程结束，直接调用waitpid()就可以让当前进程等待其所有子进程终止。
    POSIX里面没有父线程子线程的说法，所以如果想实现线程等待的话，
    使用pthread_join()，将新线程的tid传进去，会让当前线程等待新线程结束 */
    if ( pthread_join( mythread, NULL)){
        printf("error joining thread");
        abort();
    }
    exit(0);
}
