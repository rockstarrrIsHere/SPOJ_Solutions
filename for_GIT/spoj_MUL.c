#include <iostream>
#include<cstdio>
#include<queue>
#include<stdio.h>
#include <string>
#include<algorithm>
#include<math.h>
#include<vector>
#include<stack>
#include<stdio.h>
using namespace std;
#define ULL unsigned long long int;
ULL karatsuba(ULL num1,ULL num2);
#define MOD 1000000007
int main(){
    ULL t,num1,num2,ans;
    scanf("%llu",&t);
    while(t--){
        scanf("%llu %llu",&num1,&num2);
        ans=karatsuba(num1,num2);
        printf("%llu\n",ans);
    }
    return 0;
}
ULL karatsuba(ULL num1,ULL num2){
    ULL n1,n2,c1=0,c2=0,m,high1,high2,low1,low2,z0,z1,z2,x,y;
    if((num1<10) || (num2<=10))
        return num1*num2;
    n1=num1;n2=num2;
    while(n1!=0){
        n1=n1/10;
        c1++;
    }
    while(n2!=0){
        n2=n2/10;
        c2++;
    }
    m=max(c1,c2);
    m/=2;
    x=pow(10,m);
    low1=num1%x;high1=num1/x;
    low2=num2%x;high2=num2/x;
    z0=karatsuba(low1,low2);
    z1=karatsuba((low1+high1),(low2+high2));
    z2=karatsuba(high1,high2);
    y=pow(10,(2*m));
    x=pow(10,m);
    return ((z2*y)+((z1-z2-z0)*x)+(z0));
}
