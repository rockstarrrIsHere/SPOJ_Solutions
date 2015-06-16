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
void power(unsigned long long int n,unsigned long long int x[2][2]);
unsigned long long int f(unsigned long long int n);
unsigned long long int arr[2][2]={
                         {1,1},
                         {1,0}
                        };
unsigned long long int xx(unsigned long long int n);
int main()
{
    unsigned long long int t,n,m;
    scanf("%llu",&t);
    while(t--){
        scanf("%llu",&n);
        m=f(n);
        printf("%llu\n",(m));
    }
}
unsigned long long int xx(unsigned long long int n){
    unsigned long long int t,b;
    if(n==0)
        return 1;
    if(n==1)
        return 2;
    t=xx(n/2);
    b=(t*t)%MOD;
    return n%2==0?b:(b*2)%MOD;
}
unsigned long long int f(unsigned long long int n){
    unsigned long long int x[2][2];
    if(n==0)
        return 0;
    power(n,x);
    return x[1][0];
}
void power(unsigned long long int n,unsigned long long int x[2][2]){
    unsigned long long int d[2][2],y[2][2];
    if(n==1){
		x[0][0]=1;
    	x[0][1]=1;
		x[1][0]=1;
		x[1][1]=0;
    	return ;
    }
    power(n/2,d);
    y[0][0]=((d[0][0]*d[0][0]) + (d[0][1]*d[1][0]));
    y[0][1]=((d[0][0]*d[0][1]) + (d[0][1]*d[1][1]));
    y[1][0]=((d[1][0]*d[0][0]) + (d[1][1]*d[1][0]));
    y[1][1]=((d[1][0]*d[0][1]) + (d[1][1]*d[1][1]));
    if(n%2==0){
    	x[0][0]=y[0][0];
    	x[0][1]=y[0][1];
		x[1][0]=y[1][0];
		x[1][1]=y[1][1];
    	return ;
    }
    else{
        x[0][0]=(y[0][0]+y[0][1]);
        x[0][1]=y[0][0];
        x[1][0]=(y[1][0]+y[1][1]);
        x[1][1]=y[1][0];
    	return ;
    }
}
