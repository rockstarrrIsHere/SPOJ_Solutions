#include<stdio.h>
int main()
{
    int i=0,x,m;
    int s[]={1,2,3,4,5,6,7,8,9,0};
    scanf("%d",&x);
    while(1)
    {
        if(s[i]>x)
        {
            for(m=9;m>i;m--)
                s[m]=s[m-1];
            s[i]=x;
            break;
        }
        i++;
    }
    printf("%d",i);
}
