#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//指针常量和常量指针的区别
//1. 指针常量（Pointer Constant）：指针本身是一个常量，不能改变指向的地址，但可以通过指针修改所指向的值。
//2. 常量指针（Constant Pointer）：指针所指向的值是常量，不能通过指针修改所指向的值，但可以改变指针的指向。

int main()
{
    // 指针常量示例
    int value1 = 10;
    int value2 = 20;
    int *const ptrConst = &value1; // 指针常量，指针本身是常量
    printf("指针常量: %d\n", *ptrConst);
    *ptrConst = 30; // 可以修改所指向的值
    printf("指针常量修改后: %d\n", *ptrConst);
    // ptrConst = &value2; // 错误，不能改变指针的指向
    // 常量指针示例
    int value3 = 40;
    const int *constPtr = &value3; // 常量指针，指针所指向的值是常量
    printf("常量指针: %d\n", *constPtr);
    // *constPtr = 50; // 错误，不能修改所指向的值
    // constPtr = &value2; // 错误，不能改变指针的指向

    return 0;

}