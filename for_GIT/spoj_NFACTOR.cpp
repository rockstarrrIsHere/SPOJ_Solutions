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
#include<bitset>
#include<string.h>
using namespace std;
#define ULL unsigned long long int
void seive();
ULL arr[1000005];
bool isprime(ULL n);
int main()
{
	seive();
    ULL a,b,n,count=0,i,sum=0,ans=0,j,x,t;
    scanf("%llu",&t);
    while(t--){
        ans=0;
        scanf("%llu %llu %llu",&a,&b,&n);
        for(i=a;i<=b;i++){
        	if(arr[i]==n)
        		ans++;
    	}
    	printf("%llu\n",ans);
    }
    return 0;
}


void seive(){
	ULL i,j,m;
	arr[0]=0;
	for(i=2;i<=1000001;i+=2){
        arr[i]=1;
		arr[i-1]=0;
	}
    for(i=3;i<=1000001;i+=2){
		if(arr[i]==0){
            for(j=i;j<=1000001;j=j+i)
				arr[j]++;
		}
	}
}

