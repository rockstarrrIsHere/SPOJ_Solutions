#include<cstdio>
#include<queue>
#include<stdio.h>
#include <string>
#include<iostream>
#include<math.h>
#include<algorithm>
//int recure(long int n,long int x);
using namespace std;
int main()
{
   long int t,i,j,d;
  long long int arr[31]={0,	1,
 	2,
 	4,
 	8,
 	16,
 	32,
 	64,
 	128,
 	256,
 	512,
	1024,
	2048,
	4096,
	8192,
	16384,
	32768,
	65536,
	131072,
	262144,
	524288,
	1048576,
	2097152,
	4194304,
	8388608,
	16777216,
	33554432,
	67108864,
	134217728, 268435456,	536870912,};
   char s[31];
   long long int pro;
 /*  for(i=0;i<=5;i++)
    arr[i]=0;
   for(i=1;i<=30;i++){
     j=1;
     for(j=1;j<=i;j++)
        arr[i]=arr[i]+recure(i,j);
   }*/
   /*for(i=1;i<=30;i++)
    printf("%d\n",arr[i]);*/
   scanf("%d",&t);
   while(t--){
     scanf("%s",s);
     i=0;pro=1;
     while(s[i]!='\0'){
        d=s[i];
        j=i;
        while(s[i]==d){
           i++;
           if(s[i]=='\0')
              break;
        }
        pro=(pro*arr[i-j]);
     }
     printf("%lld\n",pro);
   }
   return 0;
}
/*
int recure(long int n,long int x){
    long int d=0,i;
    if(x==1 || x==n)
        return 1;

    for(i=n-1;i>=x-1;i--)
      d=d+recure(i,x-1);


    return d;
}
*/
