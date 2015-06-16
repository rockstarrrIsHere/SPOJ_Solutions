#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
unsigned long long int MOD=1000000007;

unsigned long long int* fun(long long int n,unsigned long long int *arr);
int main()
{
    int t;
    unsigned long long int arr[4]={1,1,1,0};
    unsigned long long int *a,x1,x2,d;
    long long int n,m;
    scanf("%d",&t);
    while(t--){
        arr[0]=1;
        arr[1]=1;
        arr[2]=1;
        arr[3]=0;
        a=arr;
        scanf("%lld",&n);
        scanf("%lld",&m);
        if(m==0)
            x1=0;
        else{
            a=fun(m+2,arr);
            x1=a[2]-1;
        }
        if(n==0)
            x2=0;
        else{
            a=fun(n+1,arr);
            x2=a[2]-1;
        }
        d=(x1-x2)%MOD;
        printf("%llu\n",d);
    }
    return 0;
}
unsigned long long int* fun(long long int n,unsigned long long int *arr){
    if(n==1){
        arr[0]=1;
        arr[1]=1;
        arr[2]=1;
        arr[3]=0;
        return arr;
    }
    unsigned long long int *t,a,b,c,d;
    t=fun(n/2,arr);
    a=((t[0]*t[0])+t[1]*t[2]);
    b=((t[0]*t[1])+(t[1]*t[3]));
    c=((t[2]*t[0])+(t[3]*t[2]));
    d=((t[2]*t[1])+(t[3]*t[3]));
    arr[0]=a;
    arr[1]=b;
    arr[2]=c;
    arr[3]=d;
    if(n%2==0)
        return arr;
    else{
        arr[0]=a+b;
        arr[1]=a;
        arr[2]=c+d;
        arr[3]=c;
        return arr;
    }

}
