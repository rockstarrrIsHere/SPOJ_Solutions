#include<stdio.h>
int main()
{
    int x,a;
    scanf("%d",&x);
    a=fact(x);
    printf("%d",a);
    return 0;
}
int fact(int x)
{

    if(x==1)
        return 1;
    return (x*fact(x-1));
}
