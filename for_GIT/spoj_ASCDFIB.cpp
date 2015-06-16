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
#define MOD 100000
void power(long long int n,long long int x[2][2]);
pair<long long int,long long int> f(long long int n);
long long int arr[2][2]={
                         {1,1},
                         {1,0}
                        };
long long int mrr[105];
int main()
{
    long long int t,a,b,j,i,k,n,x,y;
    pair<long long int,long long int> d;
    scanf("%lld",&t);
    for(j=1;j<=t;j++){
        scanf("%llu %llu",&a,&b);
        d=f(a);
        x=d.first;
        y=d.second;
        printf("Case %lld: ",j);
        mrr[0]=y;
        long long int count=1;
        for(i=a+1;i<= (a+b);i++){
            if(count>100)
            	break;
            mrr[count++]=x;
            k=x;
            x=(x+y)%MOD;
            y=k;

        }
        sort(mrr,mrr+count);
        for(i=0;i<count;i++)
        	printf("%lld ",mrr[i]);
        printf("\n");
    }
}
pair<long long int,long long int> f(long long int n){
    long long int x[2][2];

    power(n,x);
    return make_pair(x[1][0],x[1][1]);
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
