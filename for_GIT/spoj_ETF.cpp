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

int main()
{
	bool arr[1000005];
	long long int i,j;
	for(i=0;i<=1000004;i++)
        arr[i]=true;
	arr[0]=false;arr[1]=false;
	for(i=2;i<=1001;i++){
		if(arr[i]==true){
			for(j=i*i;j<=1000004;j=j+i)
				arr[j]=false;
		}
	}
	for(i=1;i<=1000004;i++)
		if(arr[i]==true)
			printf("%lld ",i);
	/*
	int t;long long int n,d;
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		d=n;
		for(i=2;i<=n;i++){
			if(arr[i]==true && n%i==0)
				d=(d/i)*(i-1);
		}
		printf("%lld\n",d);
	}
	*/
    return 0;
}


