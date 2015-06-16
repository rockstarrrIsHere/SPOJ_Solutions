#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    long long int t,n,sum=0;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        if(n>0)
            sum=sum+n;
    }
    printf("%lld",sum);
    return 0;
}
