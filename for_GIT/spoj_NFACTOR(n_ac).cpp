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
#define ULL int
#define MAX 1024
#define LMT 32
#define ULL int
ULL flag[MAX/64];
ULL prime[MAX/10];
ULL primelen;
void seive();
bool isprime(ULL n);
#define ifC(n) (flag[n>>6]&(1<<((n>>1)&31)))
#define isC(n) (flag[n>>6]|=(1<<((n>>1)&31)))
int main()
{
	//long long int i,j,m;
	//for(i=2;i<=1000005;i+=2)
      //  arr[i]=false;
	seive();
    ULL a,b,n,count=0,i,sum=0,ans=0,j,x,t;
    scanf("%d",&t);
    while(t--){
        ans=0;
        scanf("%d %d %d",&a,&b,&n);
        for(i=a;i<=b;i++){
            x=i;
            count=0;
            if(binary_search(prime,prime+primelen,x))
                count=1;
        	else{
                for(j=0;prime[j]*prime[j]<=x;j++){
                    if(x%prime[j]==0){
                        while(x%prime[j]==0)
                            x/=prime[j];
                        count++;
                    }
                }
                if(x>1)
                    count++;
            }
            if(count==n)
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
void seive() {
	ULL i, j, k;
	for(i = 3; i < LMT; i += 2)
		if( !ifC(i) )
			for(j = i*i, k = (i<<1); j < MAX; j += k)
				isC(j);
	prime[0]=2;
	for(i = 3, j = 1; i<MAX; i += 2)
		if( !ifC(i) )
			prime[j++] = i;
	primelen = j;
}/*
bool isprime(ULL n){
    ULL i=0;
    for(i=0;i<primelen && prime[i]*prime[i]<=n;i++){
        if(n%prime[i]==0)
            return false;
    }
    return true;
}*/


