#include <stdio.h>
#include <string.h>

//写一个宏，让他返回比较小的值
#define MIN(a,b) ((a)<(b)?(a):(b))


int main(int argc, char const *argv[])
{
    int a = 0;
    a = MIN(10,20);
    printf("比较小的值为：%d\n",a);
    return 0;
}