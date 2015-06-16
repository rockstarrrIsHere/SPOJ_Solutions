#include<stdio.h>
#include<string.h>

int main()
{
    long int t,n,c,m;
    int i,k,d,e,x,p;
    int s[1000][3];
    scanf("%ld",&t);
    for(i=0;i<t;i++)
    {
        for(k=0;k<=2;k++)
            scanf("%d",&s[i][k]);
    }
    for(i=0;i<t;i++)
    {
        n=s[i][0];
        c=s[i][1];
        m=s[i][2];
        d=n/c;
        e=d;
        while(e>=c)
        {
            d=d+(e/c);
            x=(e%c);
            p=(e/c);
            e=m+p;

        }
        printf("%d\n",d);
    }
}
