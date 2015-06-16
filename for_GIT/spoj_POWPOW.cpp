#include <iostream>
#include<stdio.h>
using namespace std;
#define MOD 1000000007
unsigned long long int arr[100005];
int main() {
	unsigned long long int i,j;
	for(i=0;i<=100000;i++)
        arr[i]=0;
	arr[0]=arr[1]=1;
	for(i=2;i<100005;i++){
		for(j=0;j<i;j++)
			arr[i]=(arr[i]+arr[j]%(MOD-1)*arr[i-j-1]%(MOD-1))%(MOD-1);
	}
	unsigned long long int a,b,t,n;
	scanf("%llu",&t);
	while(t--){
       scanf("%llu %llu %llu",&a,&b,&n);
       n=(arr[n]*(n+1)%(MOD-1))%(MOD-1);
       n=power(b,n,1);
       a=power(n,a,0);
       printf("%lld",);
	}
	return 0;
}
unsigned long long int power(unsigned long long int b,unsigned long long int n,int x){
    x%2==0?m=MOD:m=MOD-1;
    unsigned long long int t,m;
    if(b==0)
        return 1;
    if(b==1)
        return n;
    t=power(b/2);
    return b%2==0?(t*t)%m:(t*t*n)%m;
}
