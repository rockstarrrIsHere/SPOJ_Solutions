#include<cstdio>
#include<queue>
#include<stdio.h>
#include <string>
#include<iostream>
#include<algorithm>
using namespace std;
long int arr[100001];
int main()
{
   int t;long int n,e,i,a,b,x,y;
   scanf("%d",&t);
   while(t--){
     scanf("%ld",&n);
     scanf("%ld",&e);
     long int d;
     for(i=0;i<n;i++)
            arr[i]=-1;
     while(e--){
        scanf("%ld",&a);
        scanf("%ld",&b);
        if((arr[a]==-1) && (arr[b]==-1)){
            arr[a]=b;
            arr[b]=b;
        }

        if((arr[a]==-1) && (arr[b]==b))
            arr[a]=arr[b];
        if((arr[a]==a) && (arr[b]==-1))
            arr[b]=arr[a];
        if((arr[a]==-1) && (arr[b]!=b)){
            x=b;
            while(x!=arr[x]){
                x=arr[x];
            }
            arr[a]=x;
        }
        if((arr[a]!=a) && (arr[b]==-1))
        {
            x=a;
            while(x!=arr[x]){
                x=arr[x];
            }
            arr[b]=x;
        }
        if((arr[a]==a) && (arr[b]==b)){
            for(i=0;i<n;i++){
                if(arr[i]==a)
                    arr[i]=b;
            }
        }
        if((arr[a]==a) && (arr[b]!=b)){
            x=b;
            while(x!=arr[x]){
                x=arr[x];
            }
            for(i=0;i<n;i++){
                if(arr[i]==a)
                    arr[i]=x;
            }
        }
        if((arr[a]!=a) && (arr[b]==b)){
            x=a;
            while(x!=arr[x]){
                x=arr[x];
            }
            for(i=0;i<n;i++){
                if(arr[i]==b)
                    arr[i]=x;
            }
        }
        if(((arr[a]!=a) && (arr[a]!=-1)) && ((arr[b]!=b) && (arr[b]!=-1))){
            x=a;
            while(x!=arr[x]){
                x=arr[x];
            }
            y=arr[b];
            for(i=0;i<n;i++){
                if(arr[i]==y)
                    arr[i]=x;
            }
        }



     }
     d=0;
     for(i=0;i<n;i++){
        if(arr[i]==-1)
            ++d;
        if(arr[i]==i)
            ++d;
     }
     printf("%ld\n",d);
   }
   return 0;
}
