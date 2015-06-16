#include<cstdio>
#include<queue>
#include<stdio.h>
#include <string>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int HCF(int a,int b);
int main()
{
   int t,d,i,m,a,b,j,x;
   char s[15];
   scanf("%d",&t);
   while(t--){
      scanf("%s",s);
      i=0;
      x=strlen(s);
      for(i=x-1;i>=0;i--){
         if(s[i]=='.'){
            b=1;a=0;
            for(j=i+1;j<x;j++){
               a=(10*a+(s[j]-48));
               b=b*10;
            }
            break;
         }
      }
      if(i==(-1) || a==0)
        printf("%d\n",1);
      else{
        m=HCF(a,b);
        if(m==0)
          printf("%d\n",1);
        else
          printf("%d\n",b/m);
      }
   }
   return 0;
}
int HCF(int a,int b){
   while(a!=b)
    {
       if(a>b)
        a=a-b;
        else
        b=b-a;
    }
    return a;
}
