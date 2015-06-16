#include<cstdio>
#include<queue>
#include<stdio.h>
#include <string>
#include<iostream>
#include<algorithm>
int max(long int d,long int d1);
using namespace std;
int main()
{
   int t,n,i,j;
   long int d1,d;
   long int arrin[101],arrout[101];
   scanf("%d",&t);
   while(t--){
      scanf("%d",&n);
      for(i=0;i<n;i++){
        scanf("%ld",&arrin[i]);
        scanf("%ld",&arrout[i]);
      }
      sort(arrin,arrin+n);
      sort(arrout,arrout+n);
      i=0;j=0;d1=0;d=0;
      while(i<=n-1){
        while((arrin[i]<arrout[j]) && (i<n)){
            i++;d1++;
        }
        j++;
        d=max(d,d1);
        --d1;
      }
      printf("%ld\n",d);
   }
   return 0;
}
int max(long int d,long int d1){
    if(d>=d1)
        return d;
    else
        return d1;
    return 0;
}
