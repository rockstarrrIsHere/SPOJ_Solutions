#include<iostream>
#include<string>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<algorithm>
#include<stack>
#include<vector>
#include<list>
#include<string.h>
using namespace std;
#define MOD 1000000007
long long int ETP(long long int n);
long long int arr[1000002];
long long int brr[1000002];
int main()
{
	long long int t,n,x,i,j;
	for(i=0;i<1000002;i++){
		arr[i]=i;
		brr[i]=0;
	}
	for(i=2;i<1000002;i++){
		if(arr[i]==i){
			for(j=i;j<1000002;j=j+i)
				arr[j]=arr[j]-arr[j]/i;
		}
	}
	for(i=1;i<1000002;i++){
		for(j=i;j<1000002;j=j+i)
			brr[j]+=i*arr[i];
	}
	scanf("%lld",&t);
	while(t--){
		x=0;
		scanf("%lld",&n);
		x=((1+brr[n])*n)/2;
		printf("%lld\n",x);
	}
    return 0;
}







