#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
long int recur(long int *arr,int n);
int main()
{
    int t,i,n,x=1;
    long int arr[101];long int sum=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        sum=0;
        for(i=0;i<n;i++)
            scanf("%ld",&arr[i]);
        sum=arr[0]+recur((arr+1),n-1);
        printf("Case %d: %ld\n",x++,sum);
    }
    return 0;
}
long int recur(long int *arr,int n)
{
     long int sum=0;
     if(n==0)
        return 0;
     if(n==1)
        return arr[0];
     sum=arr[0]+recur(arr+1,n-1);
     return sum;
}
