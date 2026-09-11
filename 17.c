#include <string.h>
#include <stdio.h>

//代码实现strcat函数
/*
    函数名: my_strcat
    功能: 将两个字符串连接起来
    参数:
        dest: 目标字符串
        src: 源字符串
    返回值: 连接后的目标字符串
*/
char *my_strcat(char *dest, const char *src)
{
    char *ptr = dest + strlen(dest); //找到目标字符串的末尾
    while (*src != '\0') //循环遍历源字符串
    {
        *ptr++ = *src++; //将源字符串的字符复制到目标字符串的末尾
    }
    *ptr = '\0'; //添加字符串结束符
    return dest; //返回连接后的目标字符串
}
//主函数框架
int main(int argc,char const *argv[])
{
    char str1[100] = "Hello, "; //定义目标字符串并初始化
    char str2[] = "World!"; //定义源字符串并初始化
    my_strcat(str1, str2); //调用my_strcat函数连接两个字符串
    printf("连接后的字符串: %s\n", str1); //输出连接后的字符串
    return 0;
}
