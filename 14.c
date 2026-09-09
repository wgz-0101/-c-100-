#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//用c语言实现函数strcpy的功能
char *my_strcpy(char *dest, const char *src) {
    while(*src != '\0'){
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return dest;
}

int main()
{
    char dest[100];
    const char *src = "Hello, World!";
    my_strcpy(dest, src);
    printf("%s\n", dest);
    return 0;

}