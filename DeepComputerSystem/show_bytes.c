#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* 打印字节 */
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    for (i = 0; i < len; i++)
    {
        /* C/C++里面指针可以当做数组来使用。
        按照指针的大小向后寻址，比如指针大小是4字节，第一次位置是0，第二次位置是4，依次类推*/
        printf("%.2x", start[i]);
    }
    printf("\n");
}
/* &取地址，创建一个与x同类型的指针 */
void show_int(int x)
{
    show_bytes((byte_pointer)&x, sizeof(int));
}
void show_float(float x)
{
    show_bytes((byte_pointer)&x, sizeof(float));
}
void show_pointer(void *x)
{
    show_bytes((byte_pointer)&x, sizeof(void *));
}

void test_show_bytes(int val)
{
    int ival = val;
    float fval = (float)val;
    int *pval = &val;
    show_int(val);
    show_float(fval);
    show_pointer(pval);
}

/* 判断机器是大端还是小端 */
bool is_little()
{

    bool little = true;
    int val = 0x1234;
    // 定义单字节长度的指针
    int *pval = (int *)&val;
    /* 如果pval的类型定义为int，那么会提取了前4个字节的内容。 
        将pval[0]的int类型值，强制赋给char类型的first_byte，
        那么first_byte的值就是低位值。强制转换也可以判断大小端？
    */
    char first_byte = pval[0];
    printf("%x\n", first_byte);
    if (first_byte != 0x34)
    {
        little = false;
    }

    printf("当前机器是%s", little ? "小端字节序" : "大端字节序");

    return little;
}

int main()
{
    /*  */
    // test_show_bytes(12345);

    // int val = 0x87654321;
    // byte_pointer p = (byte_pointer)&val;
    // show_bytes(p, 1);
    // show_bytes(p, 2);
    // show_bytes(p, 3);

    // char *c = "12345";
    // show_bytes((byte_pointer)c, 6);
    // const char *s = "abcdef";
    // show_bytes((byte_pointer)s, strlen(s));
    // show_bytes((byte_pointer)s,7);

    bool little = is_little();

    return 0;
}
