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
   cin>>t;
   while(t--){
     cin>>n;
     cin>>e;long int d;
     for(i=0;i<n;i++)
            arr[i]=-1;
     while(e--){
        cin>>a;
        cin>>b;
        if((arr[a]==-1) && (arr[b]==-1)){
            arr[a]=b;
            arr[b]=b;
        }

        if((arr[a]==-1) && (arr[b]==b))
            arr[a]=arr[b];
        if((arr[a]==a) && (arr[b]==-1))
            arr[b]=arr[a];
        if((arr[a]==-1) && ((arr[b]!=b) && (arr[b]!=-1)))
            arr[a]=b;
        if(((arr[a]!=a) && (arr[a]!=-1)) && (arr[b]==-1))
            arr[b]=a;
        if((arr[a]==a) && ((arr[b]==b))){
            arr[a]=b;
        }
        if((arr[a]==a) && ((arr[b]!=b)&& (arr[b]!=-1) )){
            x=b;
            while(x!=arr[x]){
                x=arr[x];
            }
            if(x!=a)
                arr[a]=x;
        }
        if(((arr[a]!=a) && (arr[a]!=-1)) && (arr[b]==b)){
            x=a;
            while(x!=arr[x]){
                x=arr[x];
            }
            if(x!=b)
                arr[b]=x;
        }
        if(((arr[a]!=a) && (arr[a]!=-1)) && ((arr[b]!=b) && (arr[b]!=-1))){
            x=a;
            while(x!=arr[x]){
                x=arr[x];
            }
            y=b;
            while(y!=arr[y]){
                y=arr[y];
            }
            if(x!=y)
                x=y;
        }
    }
     d=0;
     for(i=0;i<n;i++){
        if(arr[i]==-1)
            ++d;
        if(arr[i]==i)
            ++d;
     }
     cout<<d<<endl;
   }
   return 0;
}
