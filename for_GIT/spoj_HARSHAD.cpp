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
#include<set>
#define ULL unsigned long long int
using namespace std;
#define MOD 1000000007
bool isprime(ULL n);
#define MAX 1000064
#define LMT 1009
ULL flag[MAX/64];
ULL prime[MAX/10];
ULL primelen;
void seive();
void make_all();
set<ULL> st;
ULL search_for_index(ULL i,ULL x,ULL j);
#define ifC(n) (flag[n>>6]&(1<<((n>>1)&31)))
#define isC(n) (flag[n>>6]|=(1<<((n>>1)&31)))
int main(){
    ULL t,a,b,count=0,x,i;
    seive();
    make_all();
    scanf("%llu",&t);
    while(t--){
        count=0;
        scanf("%llu %llu",&a,&b);
        if(a<=2) a=3;
        if(b<=2){
            printf("0\n");
            continue;
        }
        x=a%2==0?a+1:a;
        i=search_for_index(0,x,primelen-1);
        while(prime[i]<=b){
            if(st.find(prime[i])!=st.end())
              count++;
            i++;
        }
        printf("%llu\n",count);
    }
    return 0;
}
void make_all(){
    ULL i,sum=0,x;
    st.insert(1);
    st.insert(3);
    st.insert(5);
    st.insert(7);

    for(i=9;i<=1000000;i+=11)
        st.insert(i);


}
ULL search_for_index(ULL i,ULL x,ULL j){
    ULL mid,t,m;
    mid=(i+j)/2;
    if(i==j)
         return mid;
    else{
        if(prime[mid]==x)
            return mid;
        if(prime[mid]<x)
            t=search_for_index(mid+1,x,j);
        if(prime[mid]>x)
            t=search_for_index(i,x,mid);
    }
    return t;
}
void seive() {
	unsigned i, j, k;
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
}
*/

