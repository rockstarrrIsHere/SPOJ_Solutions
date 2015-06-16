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
#define MAX 100000000
#define LMT 10000
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
	seive();
	ULL i;
//	printf("%d",prime[primelen-1]);
	for(i=0;i<primelen;i++)
		printf("%d\n",prime[i]);
/*	for(i=primelen/2+1;i<primelen;i++)
		printf("%\n",prime[i]);*/
	//for(i=2;i<=1000005;i+=2)
      //  arr[i]=false;
	/*for(i=3;i<=1000001;i+=2)
        arr[i]=true;
    arr[0]=false;arr[1]=false;
    arr[2]=true;
	for(i=3;i<=1001;i+=2){
		if(arr[i]==true){
            for(j=i*i;j<=1000001;j=j+2*i){
				arr[j]=false;
            }
		}
	}*/


    return 0;
}
void seive() {
	ULL i, j, k,count;
	for(i = 3; i < LMT; i += 2)
		if( !ifC(i) )
			for(j = i*i, k = (i<<1); j < MAX; j += k)
				isC(j);

	j=2;prime[0]=2;count=1;
	for(i = 3; i<MAX; i += 2)
		if( !ifC(i) ){
			if(j%100==1){
				prime[count++]=i;
			}
			j++;
		}
	primelen = count;
}/*
bool isprime(ULL n){
    ULL i=0;
    for(i=0;i<primelen && prime[i]*prime[i]<=n;i++){
        if(n%prime[i]==0)
            return false;
    }
    return true;
}*/
