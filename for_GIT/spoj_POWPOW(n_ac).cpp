#include <iostream>
#include<stdio.h>
using namespace std;
#define MOD 1000000007
unsigned long long int power(unsigned long long int b,unsigned long long int n);
unsigned long long int powera(unsigned long long int b,unsigned long long int n);
//nsigned long long int arr[100005];
int main() {
	unsigned long long int i,j,a,b,t,n,ans=1,res,tes;
	scanf("%llu",&t);
	while(t--){
       ans=1;
       scanf("%llu %llu %llu",&a,&b,&n);
       if(n==0)
        ans=1;
       else{
        for(i=0;i<n;i++){
            ans*=(2*n-i);
            ans/=(i+1);
        }
       }
       //ans=ans%(MOD-1);
       res=power(b,ans);
       tes=powera(res,a);
       printf("%llu\n",tes);
	}
	return 0;
}
unsigned long long int power(unsigned long long int b,unsigned long long int n){
    unsigned long long int t,m;
    if(n==0)
        return 0;
    if(b==0)
        return 1;
    if(b==1)
        return n%(MOD-1);
    t=power(b/2,n);
    return b%2==0?(t*t)%(MOD-1):(((t*t)%(MOD-1))*(n%(MOD-1)))%(MOD-1);
}
unsigned long long int powera(unsigned long long int b,unsigned long long int n){
    unsigned long long int t,m;
    if(n==0)
        return 0;
    if(b==0)
        return 1;
    if(b==1)
        return n%(MOD);
    t=power(b/2,n);
    return b%2==0?(t*t)%(MOD):(((t*t)%MOD)*(n%MOD))%(MOD);
}
