//内存分配
//全局变量，静态变量再再全局区，malloc是堆区得，函数参数，函数返回值再栈区，
//常量再常量区，剩下得在代码段
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int *p = (int *)malloc(sizeof(int)*5);
    if(p == NULL)
    {
        printf("空间开辟失败\n");
        return 1;
    }
    for(int i = 0;i < 5;i++)
    {
        *(p+i) = i*1;
    }
    printf("开辟的空间为:\n");
    for(int i = 0;i < 5;i++)
    {
        printf("%d\t",*(p+i));
    }    
    printf("\n");
    free(p);
    p = NULL;
    return 0;
}