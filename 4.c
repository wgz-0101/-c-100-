#include <stdio.h>
#include <string.h>
//数组指针和指针数组
//数组指针：指向一个数组得指针，本质指针
//指针数组：时候一个数组
int main(int argc, char const *argv[])
{
    //数组指针
    int a = 10 ,b = 20,c = 30;
    int p_arr[3] = {0,1,2};
    int len = 0;
    char p_arr_1[2][10] = {
        "Hello",
        "World"
    };
    int (*p)[3] = &p_arr;
    printf("数组指针：\n");
    for(int i = 0;i < 3; i++)
    {
        printf("%d\t",(*p)[i]);
    }
    printf("数组指针字符串：\n");
    char (*p_1)[10] = p_arr_1;
    printf("%s\n",*p_1);
    printf("%s\n",*(p_1+1));
    printf("%c",**p_1);
    printf("\n");
    //指针数组‘
    int *p_prr[3] = {&a,&b,&c};
    printf("指针数组：\n");
    for(int i = 0;i < 3; i++)
    {
        printf("%d\t",*p_prr[i]);
    }
    printf("\n");
    return 0;
}
