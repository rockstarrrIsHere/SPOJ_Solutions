#include<stdio.h>
#include<math.h>
#define X 100001

long long int arrA[X];
long long int arrB[X];
long long int arrC[X];
int main()
{
    long long int g=(pow(10,9)+7);
    long long int i,j,n,m;
    scanf("%lld",&n);
    scanf("%lld",&m);
    arrA[0]=0;
    arrB[0]=0;
    arrC[0]=0;
    for(i=1;i<=n;i++)
        scanf("%lld",&arrA[i]);
    for(i=1;i<=m;i++)
        scanf("%lld",&arrB[i]);
    for(i=1;i<=m;i++)
        scanf("%lld",&arrC[i]);
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j%arrB[i]==0)
            {
               arrA[j]=(arrA[j]%g);
                arrC[i]=(arrC[i]%g);
                arrA[j]=(arrA[j]*arrC[i]);
                arrA[j]=(arrA[j]%g);
            }
        }
    }
    for(i=1;i<=n;i++)
        printf("%lld\t",arrA[i]);
}
