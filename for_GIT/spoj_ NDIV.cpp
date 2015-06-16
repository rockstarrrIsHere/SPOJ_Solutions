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
#define MOD 1000000007
#define MAX 65536
#define LMT 256
#define ULL unsigned long long int
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
    ULL a,b,n,count=0,i,sum=0,ans=0,j;
    scanf("%llu %llu %llu",&a,&b,&n);
    for(i=a;i<=b;i++){
        count=1;
        for(j=0;j<=ceil(sqrt(i));j++){
            sum=0;
            if(i%prime[j]==0){
                while(i%prime[j]==0){
                    i/=prime[j];
                    sum++;
                }
                count*=(sum+1);
            }
        }
        if(i>1)
            count*=2;
        if(count==n)
            ans++;
    }
    printf("%llu\n",ans);
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
