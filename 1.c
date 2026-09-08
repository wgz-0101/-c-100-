#include <stdio.h>

//什么是函数指针，什么是指针函数

//函数指针：指向一个函数得指针
//指针函数：一个函数得返回值是指针
int add(int a, int b)
{
    return a+b;
}

int *getadress()
{
    static int a = 10;
    return &a;
}

int main()
{
    //函数指针
    int (*ptr)(int ,int) = &add;
    int num = ptr(10,10);
    //指针函数
    int *p = getadress();
    printf("函数指针num得值为:%d\n指针函数得值为:%d\n",num,*p);
    return 0;
}