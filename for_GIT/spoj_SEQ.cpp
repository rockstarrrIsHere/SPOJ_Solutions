#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include<stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#include<map>
#define MOD 1000000000
#define ULL unsigned long long int
ULL T[30][30],F[30][30];
ULL t,n,r,k;
void power(ULL n,ULL x[30][30]);
ULL f(ULL n);
// Please note that the size of r<=8.
//Matrix exponentiation with F(n)=a1*f(n-1)+a2*F(n-2)+....+....+..ar*F(n-r);
// arr->T.
int main(){
    ULL i,j,ans,m;
    scanf("%llu",&t);
    while(t--){
        scanf("%llu",&r);
        for(i=0;i<r;i++)
            scanf("%llu",&F[i][0]);
        for(i=1;i<=r;i++)
            scanf("%llu",&T[r-1][r-i]);
		scanf("%llu",&n);
		for(i=0;i<r-1;i++){
            for(j=0;j<r;j++)
                (j==i+1)?T[i][j]=1:T[i][j]=0;
		}
        printf("%llu\n",f(n-1));
    }
    return 0;
}
ULL f(ULL n){
    ULL i,j,p,sum;
    ULL x[30][30],t[30][30];
    if(n==0)
        return F[0][0];
    for(i=0;i<r;i++){
        for(j=0;j<r;j++)
            x[i][j]=0;
    }
    power(n,x);
    for(i=0;i<r;i++){
            sum=0;
            for(j=0;j<r;j++)
                sum=(sum+((x[i][j]*F[j][0])%MOD))%MOD;
            sum%=MOD;
            t[i][0]=sum;
	}
    return t[0][0];
}
void power(ULL n,ULL x[30][30]){
    ULL i,j,p,sum;
    ULL d[30][30],y[30][30];
    for(i=0;i<r;i++){
        for(j=0;j<r;j++)
            d[i][j]=0;
    if(n==1){
        for(i=0;i<r;i++){
            for(j=0;j<r;j++)
                x[i][j]=T[i][j];
        }
     	return ;
    }
    power(n/2,d);
    for(i=0;i<r;i++){
       p=0;
       while(p!=r){
         sum=0;
         for(j=0;j<r;j++)
           sum=(sum+((d[i][j]*d[j][p])%MOD))%MOD;
         sum%=MOD;
         y[i][p]=sum;
         p++;
       }
    }
	if(n%2==0){
        for(i=0;i<r;i++){
            for(j=0;j<r;j++)
                x[i][j]=y[i][j];
        }
    	return ;
    }
    else{
        for(i=0;i<r;i++){
            p=0;
            while(p!=r){
                sum=0;
                for(j=0;j<r;j++)
                    sum=(sum+((y[i][j]*T[j][p])%MOD))%MOD;
                sum%=MOD;
                x[i][p]=sum;
                p++;
            }
         }
    	return ;
    }
   }
}

