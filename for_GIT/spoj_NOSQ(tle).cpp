#include<iostream>
#include<string>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<math.h>
#include<algorithm>
using namespace std;
#define ULL int

ULL pre[100001][10];
void seive();
int main()
{
    ULL t,i,a,b,d;
    seive();
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d %d %d",&a,&b,&d);
        printf("%d\n",pre[b][d]-pre[a-1][d]);
    }
    return 0;
}

void seive(){
    ULL i,j,x;
   for(i=0;i<=100000;i++){
     for(j=0;j<=9;j++)
        pre[i][j]=0;
   }
   ULL frr[100001];
   ULL arr[66]={4,9,25,49,121,169,289,361,529,841,961,1369,1681,1849,2209,2809,3481,3721,4489,5041,5329,6241,6889,7921,9409,10201,10609,11449,11881,12769,16129,17161,18769,19321,22201,22801,24649,26569,27889,29929,32041,32761,36481,37249,38809,39601,44521,49729,51529,52441,54289,57121,58081,63001,66049,69169,72361,73441,76729,78961,80089,85849,94249,96721,97969,100489};
   frr[0]=0;frr[1]=1;frr[2]=2;

   for(i=0;i<66;i++){

       for(j=arr[i];j<=100000;j=j+arr[i]){
            frr[j]=-1;
       }
   }
   for(j=0;j<=9;j++){
      pre[0][j]=0;
      pre[1][j]=0;
   }
   pre[1][1]=1;
   for(i=0;i<=100000;i++){
      if(frr[i]!=-1){
         x=i;
         while(x!=0){
            pre[i][x%10]=1;
            x/=10;
         }
     }
     for(j=0;j<=9;j++)
        pre[i][j]+=pre[i-1][j];
   }
}






