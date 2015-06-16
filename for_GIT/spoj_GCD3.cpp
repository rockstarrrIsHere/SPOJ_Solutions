#include<stdio.h>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int my_gcd(char s[],int a);
int main(){
    char s1[270];
    int k,x,i;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %s",&k,s1);
        for(i=k;i>=2;i--){
            if(!my_gcd(s1,i)){
               printf("%d\n",i);
               break;
            }
        }
        if(i<2){
            printf("1\n");
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

