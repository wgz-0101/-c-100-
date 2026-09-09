#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define 和 typedef 的区别
//define 是预处理指令，主要用于定义宏和常量，而 typedef 是用于为已有类型创建新的类型别名。define 在编译时进行替换，而 typedef 在编译时创建新的类型名称。
//define 的使用示例
#define PI 3.14159
//typedef 的使用示例
typedef unsigned int uint;
int main(int argc, char const *argv[])
{
    // 使用 define 定义的常量
    printf("The value of PI is: %f\n", PI);
    // 使用 typedef 定义的类型别名
    uint myNumber = 10;
    printf("The value of myNumber is: %u\n", myNumber);
    return 0;
}
