#include<cstdio>
#include<queue>
#include<stdio.h>
#include <string>
#include<iostream>
#include<algorithm>
using namespace std;
long int arr[100000];
int main()
{
   long int m,sum=0,n,i,x,d=0;;
   scanf("%ld",&m);
   scanf("%ld",&n);
   for(i=0;i<n;i++)
     scanf("%ld",&arr[i]);
   sort(arr,arr+n);
   x=n/2;
   while(1){
     for(i=n-1;i>=x;i--){
        if(m==0)
            break;
        if(arr[i]!=0){
            if(m>=(arr[i]-arr[x])){
                m=(m-(arr[i]-arr[x]));
                arr[i]=arr[x];
            }
            else{
                arr[i]=(arr[i]-m);
                m=0;
            }
        }
     }
     if(m==0)
        break;
     if(x==0)
        break;
     x=(x/2);
   }
   d=0;
   if(m>=n){
   while(1){
      if(m>=n){
        m=m-n;
        d++;
      }
      else{
        for(i=n-1;i>=0;i--){
           if((arr[i]!=0) && (arr[i]>=d)){
              arr[i]=arr[i]-d;
           }
        }
        break;
      }

    }
   }
   i=n-1;
   while(m!=0){
      arr[i]=(arr[i]-1);
      i--;m--;
   }

   sum=0;
   for(i=0;i<n;i++)
      sum=(sum+arr[i]*arr[i]);
   printf("%ld\n",sum);
   return 0;
}

