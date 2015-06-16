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
#define ULL unsigned long long int
using namespace std;
#define MOD 1000000007
int x(int year,ULL i);
void expo();
ULL dp[52];
int main(){
    ULL i;
    string s;
    dp[0]=1;dp[1]=2;
    expo();
    int year,d;
    scanf("%d",&year);
    scanf("%llu",&i);
    d=x(year,i);
    if(d==1) s="red";
    else s="blue";
    cout<<s<<endl;
    return 0;
}
int x(int year,ULL i){
    int d;ULL xx,x1;
    if(year==0)
        return 1;
    xx=dp[year];
    x1=xx/2;
    if(0<=i<x1){
        d=x((year-1),i);
        if(d==0)
            d=1;
        else
            d=0;
    }
    else
        d=x(year-1,i-x1);
    return d;
}
void expo(){
    int i;
    for(i=2;i<=51;i++)
        dp[i]=dp[i-1]*2;
}
