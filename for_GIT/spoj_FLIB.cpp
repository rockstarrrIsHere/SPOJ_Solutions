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
void power(long long int n,long long int x[2][2]);
long long int arr[2][2]={
                         {1,1},
                         {1,0}
                        };
long long int g(long long int n);
pair<long long int,long long int> f(long long int n);
int main()
{
    int t;long long int n;
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        printf("%lld\n",g(n));
    }
    return 0;
}
long long int g(long long int n){
    pair<long long int,long long int> d;
    if(n==0)
        return 0;
    d=f(2*n+1);
    return (d.first*d.second)%MOD;
}
pair<long long int,long long int> f(long long int n){
    long long int x[2][2];
    if(n==1)
        return pair<long long int,long long int>(1,0);
    power(n,x);
    return pair<long long int,long long int>(x[1][0],x[1][1]);
}
void power(long long int n,long long int x[2][2]){
    long long int d[2][2],y[2][2];
    if(n==1){
		x[0][0]=1;
    	x[0][1]=1;
		x[1][0]=1;
		x[1][1]=0;
    	return ;
    }
    power(n/2,d);
    y[0][0]=((d[0][0]*d[0][0])%MOD + (d[0][1]*d[1][0])%MOD)%MOD;
    y[0][1]=((d[0][0]*d[0][1])%MOD + (d[0][1]*d[1][1])%MOD)%MOD;
    y[1][0]=((d[1][0]*d[0][0])%MOD + (d[1][1]*d[1][0])%MOD)%MOD;
    y[1][1]=((d[1][0]*d[0][1])%MOD + (d[1][1]*d[1][1])%MOD)%MOD;
    if(n%2==0){
    	x[0][0]=y[0][0];
    	x[0][1]=y[0][1];
		x[1][0]=y[1][0];
		x[1][1]=y[1][1];
    	return ;
    }
    else{
        x[0][0]=(y[0][0]+y[0][1])%MOD;
        x[0][1]=y[0][0];
        x[1][0]=(y[1][0]+y[1][1])%MOD;
        x[1][1]=y[1][0];
    	return ;
    }
}

