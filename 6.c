#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//结构体定义方式
struct Student
{
    char name[20];
    int age;
    float score;
};

//共用体定义方式
union Student_1
{
    int i;
    float f;
    char c;
};

int main(int argc, char const *argv[])
{
    struct Student stu = {"张三",18,90.5};
    printf("姓名：%s,年龄：%d,成绩：%.2f\n",stu.name,stu.age,stu.score);
    printf("结构体的大小：%lu\n",sizeof(stu));
    
    union Student_1 stu_1;
    stu_1.i = 10;
    printf("共用体中的整数：%d\n",stu_1.i);
    printf("共用体的大小：%lu\n",sizeof(stu_1));
    return 0;
}
