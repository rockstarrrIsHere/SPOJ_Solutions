#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
using namespace std;
long long int x(long int j,long int n);
long long int arr[10002];
int main()
{
    long int t,j=1,i,n;
    long long int d=0;
    scanf("%ld",&t);
    while(j<=t){
        d=0;
        scanf("%ld",&n);
        for(i=1;i<=n;i++)
            scanf("%lld",&arr[i]);
        if(n>2){
            //dp[1]=arr[1];
            arr[2]=max(arr[1],arr[2]);
            d=x(3,n);
        }
        if(n==1)
            d=arr[1];
        if(n==2)
            d=max(arr[1],arr[2]);
        printf("Case %ld: %lld\n",j,d);
        j++;
    }
    return 0;
}
long long int x(long int i,long int n){
    long long int d;
    if(i==n+1)
        return arr[n];
    d=max(arr[i-1],(arr[i-2]+arr[i]));
    arr[i]=d;
    d=x(i+1,n);
    return d;
}
