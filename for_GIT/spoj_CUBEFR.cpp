#include<iostream>
#include<string>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<math.h>
#include<algorithm>
using namespace std;
#define ULL int
ULL frr[1000001];
void seive();
int main()
{
    ULL t,n,i;
    seive();
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d",&n);

        if(frr[n]!=-1)
            printf("Case %d: %d\n",i,frr[n]);
        else{
            printf("Case %d:  Not Cube Free\n",i);
        }
    }
    return 0;
}
void seive(){
    ULL i,j,k;
   ULL arr[26]={8,27,125,343,1331,2197,4913,6859,12167,24389,29791,50653,68921,79507,103823,148877,205379,226981,300763,357911,389017,493039,571787,704969,912673,1030301};
   frr[0]=0;frr[1]=1;frr[2]=2;

   for(i=0;i<26;i++){

       for(j=arr[i];j<=1000000;j=j+arr[i]){
            frr[j]=-1;
       }
   }
   k=3;
   for(j=3;j<=1000000;j++){
      if(frr[j]==-1){
         continue;
      }
      frr[j]=k++;
   }
}






