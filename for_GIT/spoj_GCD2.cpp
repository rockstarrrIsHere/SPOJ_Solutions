#include<stdio.h>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int my_gcd(char s[],int a);
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main(){
    char s1[270];
    int k,x,i,d;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %s",&k,s1);
        if(k==0)
            printf("%s\n",s1);
        else{
            d=my_gcd(s1,k);
            printf("%d\n",gcd(d,k));
        }

    }
    return 0;
}
int my_gcd(char s[],int a){
    int x,i,d=0;
    x=strlen(s);
    for(i=0;i<x;i++){
        d=(10*d+s[i]-'0')%a;
    }
    return d;
}

