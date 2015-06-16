#include<stdio.h>
#include<malloc.h>
int main()
{
    int *p=(int* )malloc(sizeof(int));

    p[0]=4;
    printf("%d",p[0]);
    return 0;
}
