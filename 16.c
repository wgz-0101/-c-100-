#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//使用c语言编写一个strcmp函数
/*
    函数名: my_strcmp
    功能: 比较两个字符串的大小
    参数:
        str1: 第一个字符串
        str2: 第二个字符串
    返回值:
        0: 两个字符串相等
        <0: str1小于str2
        >0: str1大于str2
*/

int my_strcmp(const char *str1,const char *str2)
{
    while(*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

int main(int argc, char const *argv[])
{
    /* code */
    const char *str1 = "hello";
    const char *str2 = "world";
    int result = my_strcmp(str1, str2);
    printf("结果: %d\n", result);
    if (result == 0)
    {
        printf("两个字符串相等\n");
    }
    else if (result < 0)
    {
        printf("str1小于str2\n");
    }
    else
    {
        printf("str1大于str2\n");
    }
    return 0;
}
