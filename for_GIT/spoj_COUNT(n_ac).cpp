#include<cstdio>
#include<queue>
#include<stdio.h>
#include <string>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
   long long int n,k,i,j,count;
   while(1){
     scanf("%lld %lld",&n,&k);
     if((n==0) && (k==0))
        break;
     n=n-k;
     if(n==0)
        printf("%d\n",1);
     else{
        j=min(k,n);
        count=0;
        for(i=1;i<=j;i++){
            if(i==1)
                count+=1;
            else{
                if(i==2)
                    count+=n/2;
                else{
                    if(n==i)
                        count+=1;
                    else
                        count+=n-i;
                }
            }
        }
        printf("%lld\n",count%1988);
     }
   }
   return 0;
}


