#include<cstdio>
#include<queue>
#include<stdio.h>
#include<iostream>
#include <string>
#include<stack>
#include<algorithm>
using namespace std;

string s[100];
int arr[100];
queue<int> q[10000];
int main()
{
   int n,m,i,j,d,k,t;
   cin>>n;
   cin>>m;
   for(i=0;i<m;i++){
      cin>>s[i];
      arr[i]=0;
   }
   for(j=0;j<m;j++){
      for(k=0;k<(n-1);k++){
         if(s[j][k]!='A'){
         for(t=(k+1);t<n;t++){
            if(s[j][t]<s[j][k])
               arr[j]++;
         }
        }
      }
      q[arr[j]].push(j);
   }
   sort(arr,arr+m);
   for(i=0;i<m;i++){
     j=q[arr[i]].front();
     q[arr[i]].pop();
     cout<<s[j]<<'\n';
    }
    return 0;
}



