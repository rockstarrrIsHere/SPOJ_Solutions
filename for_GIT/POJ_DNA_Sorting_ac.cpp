#include<cstdio>
#include<queue>
#include<stdio.h>
#include<iostream>
#include <string>
#include<stack>
#include<algorithm>
using namespace std;
struct node{
  int data;
  char *s;
}q[101];
char sr[101][51];
bool cmp(struct node a,struct node b);
bool cmp(struct node a,struct node b)
{
    return a.data<b.data;
}
//int arr[100];
int main()
{
   int n,m,i,j,d,k,t;
   cin>>n;
   cin>>m;
   for(i=0;i<m;i++){
      cin>>sr[i];
      q[i].s=sr[i];
      q[i].data=0;
   }
   for(j=0;j<m;j++){
      for(k=0;k<(n-1);k++){
         if(sr[j][k]!='A'){
         for(t=(k+1);t<n;t++){
            if(sr[j][t]<sr[j][k])
               q[j].data++;
         }
        }
      }
      //q[arr[j]].push(j);
   }
   sort(q,q+m,cmp);
   for(i=0;i<m;i++){
     for(j=0;j<n;j++)
        printf("%c",q[i].s[j]);
     cout<<'\n';
    }
    return 0;
}



