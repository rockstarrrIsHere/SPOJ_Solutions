#include<cstdio>
#include<queue>
#include<stdio.h>
#include<iostream>
using namespace std;
int s[20000];
int arr[1000000];
int main()
{
    int t,n,i=0,j,m;
    queue<int> q;
   // cin>>t;
    for(i=1;i<=100;i++)
        q.push(i);
    //i=0;
    //while(i<t){
        //n=arr[i];
       // for(j=1;j<=n;j++)
         //   q.push(j);
        //m=1;
        while(!q.empty()){
            if(q.size()==1){
                m=q.front();
                break;
            }
            int val=q.front();
            q.push(val);
            q.pop();
            if(q.size()!=1)
                q.pop();
        }

        cout<<m;


    return 0;
}
