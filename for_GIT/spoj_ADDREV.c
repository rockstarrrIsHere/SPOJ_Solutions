#include<stdio.h>
#include<math.h>
#include<string.h>
#include<malloc.h>

long int arr[10000][2];
int main(){
    int n,i;
    long int d,m,sum=0,d1=0,m1=0,sum1=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%ld",&arr[i][0]);
        scanf("%ld",&arr[i][1]);
    }
    i=0;
    while(i<n){
        d=arr[i][0];
        m=arr[i][1];
        d1=0;m1=0;sum=0;sum1=0;
        while(d!=0){
            d1=((d%10)+10*(d1));
            d=d/10;
        }
        while(m!=0){
            m1=((m%10)+10*(m1));
            m=m/10;
        }
        sum=(d1+m1);
        while(sum!=0){
            sum1=((sum%10)+10*(sum1));
            sum=sum/10;
        }
        printf("%ld\n",sum1);

        i++;
    }
    return 0;
}

