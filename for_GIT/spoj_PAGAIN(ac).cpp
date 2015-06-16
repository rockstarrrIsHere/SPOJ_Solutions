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
#define ULL long long int
using namespace std;
//#define MOD 1000000007
//bitset<65538> arr;
bool isprime(ULL n);
#define MAX 65536
#define LMT 256
ULL flag[MAX/64];
ULL prime[MAX/10];
ULL primelen;
void seive();
#define ifC(n) (flag[n>>6]&(1<<((n>>1)&31)))
#define isC(n) (flag[n>>6]|=(1<<((n>>1)&31)))
void seive() {
	unsigned i, j, k;
	for(i = 3; i < LMT; i += 2)
		if( !ifC(i) )
			for(j = i*i, k = (i<<1); j < MAX; j += k)
				isC(j);
	for(i = 3, j = 0; i<MAX; i += 2)
		if( !ifC(i) )
			prime[j++] = i;
	primelen = j;
}
int main(){
    seive();
    ULL t,n,i;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        if(n<5){
            if(n==3) printf("2\n");
            if(n==4 || n==5) printf("3\n");
        }
        if(n&1) n-=2;
        else n-=1;
        if(n>5){
            if(n<MAX){
                while(1){
                    if(!ifC(n))
                        break;
                    n-=2;
                }
            }
            else{
                if( n > 4294967291 ) {
                    printf("4294967291\n");
                    continue;
                }
                else
               {
                    while(1){

                        if(isprime(n)) break;
                        n=n-2;;
                    }
                }
            }
            printf("%lld\n",n);
        }
    }
    return 0;
}
bool isprime(ULL n){
    ULL i=0;
    for(i=0;i<primelen && prime[i]*prime[i]<=n;i++){
        if(n%prime[i]==0)
            return false;
    }
    return true;
}/*
void seive(){
    ULL i,j,m;
    for(i=3;i<65538;i+=2)
        arr[i]=true;
    arr[0]=false;arr[1]=false;
    arr[2]=true;
	for(i=3;i<=257;i+=2){
		if(arr[i]==true){
            for(j=i*i;j<65538;j=j+2*i){
				arr[j]=false;
            }
		}
	}
	prime[0]=2;
	j=1;
	for(i=3;i<65538;i+=2){
        if(arr[i]==true)
            prime[j++]=i;
	}
	primelen=j;
}

*/
