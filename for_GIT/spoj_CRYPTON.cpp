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
#include<map>
#include<bitset>
#include<string.h>
using namespace std;
#define MOD 1000000007
#define ULL long long int
int primelen;
bitset<1000001> arr;
int prime[100001];
void seive();
int my_gcd(char s[],int a);
int gcd(int a,int b);
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main()
{
    char s[150];
    int n,i,j;
    seive();
    while(scanf("%s %d",s,&n)==2 && n){
        for(i=0;((i<primelen)&&(prime[i]<n));i++){
            if(!my_gcd(s,prime[i])){
                break;
            }

        }
        if(prime[i]>=n){
            printf("GOOD\n");
        }
        else{
            printf("BAD %d\n",prime[i]);
        }
    }
    return 0;
}
int my_gcd(char s[],int a){
    int x,i,d;
    x=strlen(s);d=0;
    for(i=0;i<x;i++){
        d=(10*d+s[i]-'0')%a;
    }
    return d;
}
void seive(){
    int i,j,k;
   arr[0]=arr[1]=false;
    arr[2]=true;
    for(i=3;i<=1000000;i+=2){
        arr[i]=true;
        //arr[i-1]=false;
    }
    prime[0]=2;k=1;
    for(i=3;i<=1000;i+=2){
        if(arr[i]==true){
            for(j=i*i;j<1000000;j=j+2*i){
                arr[j]=false;
            }
        }
    }
    for(j=3;j<1000000;j++){
        if(arr[j]==true)
            prime[k++]=j;
    }
    primelen=k;
}






