#include <stdio.h>
#include <string.h>
//sizaof 和 strlen得区别

int main(int argc, char const *argv[])
{
    printf("sizof:%d,strlen:%d\n",sizeof("ABC"),strlen("ABC"));
    return 0;
}
