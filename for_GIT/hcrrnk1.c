#include<stdio.h>
int min(int x,int y);
int main()
{
    int t,n;
    int i,j,x;
    int s[10][100];
    long long int d=0;
    long long int arr[100];
    scanf("%d",&t);
    for(j=0;j<t;j++)
    {
        scanf("%d",&arr[j]);
        n=arr[j];
        for(i=0;i<n;i++)
            scanf("%d",&s[t][i]);
    }
    x=0;
    while(x<t)
    {
        n=arr[t];
        d=s[t][0];
        for(j=0;j<n;j++)
            d=min(s[t][j],s[t][j+1]);
        j=0;
        if(d==1)
            printf("YES\n");
        if(d!=1)
        {
            for(j=0;j<n;j++)
            {
                while(1)
                {
                    if((s[t][j])%d==0)
                    {
                        s[t][j]=(s[t][j]/2);
                        if(s[t][j]==1)
                            break;
                    }
                    else
                    {
                      printf("YES\n");
                      break;
                    }
                }

            }
            if(j==n)
                printf("NO\n");
        }
        x++;
    }
    return 0;
}
int min(int x,int y)
{
    if(x>=y)
        return x;
    else
        return y;
    return 0;
}
