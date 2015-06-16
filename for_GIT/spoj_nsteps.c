#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    long long int n,x,y;
    scanf("%lld",&n);
    while(n--){
        scanf("%lld",&x);
        scanf("%lld",&y);
        if(x==y || x==y+2){
            if(x==y){
            if(x%2==0)
                printf("%lld",x+y);
            else
                printf("%lld",x+y-1);
            }
            else{
                if(x%2==0)
                   printf("%lld",x+y);
                else
                   printf("%lld",x+y-1);
            }
        }
        else
            printf("No Number");
        printf("\n");
    }
    return 0;
}
