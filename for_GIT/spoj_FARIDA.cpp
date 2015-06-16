#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
using namespace std;
long long int x(long int i);
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
        if(n>2)
            d=max(x(n-1),(x(n-2)+arr[n]));
        if(n==1)
            d=arr[1];
        if(n==2)
            d=max(arr[1],arr[2]);
        printf("Case %ld: %lld\n",j,d);
        j++;
    }
    return 0;
}
long long int x(long int i){
    long long int d;
    if(i==1)
        return arr[1];
    if(i==2)
        return max(arr[1],arr[2]);
    d=max(x(i-1),(x(i-2)+arr[i]));
    return d;
}
