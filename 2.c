#include <stdio.h>

//指针的大小


int main()
{
    char *a;
    int *b;
    float *c;
    printf("%d %d %d\n",sizeof(a),sizeof(b),sizeof(c));
    return 0;
}