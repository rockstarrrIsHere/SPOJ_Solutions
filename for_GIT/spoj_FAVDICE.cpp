#include<stdio.h>
#include<math.h>
#include<string.h>

int main(){
    int t;
    float n,sum=0,x,i;
    scanf("%d",&t);
    while(t--){
        scanf("%f",&n);
        sum=0;
        for(i=1;i<=n;i++){
            x=1.0/i;
            sum=sum+x;
        }
        sum=sum*n;
        printf("%.2f\n",sum);

    }

    return 0;
}

