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
    cin>>t;
    for(i=0;i<t;i++)
        cin>>arr[i];
    i=0;
    while(i<t){
        n=arr[i];
        for(j=1;j<=n;j++)
            q.push(j);
        m=1;
        while(!q.empty()){
            j=1;
            while(j<=m){
                int val=q.front();

                q.push(val);
                q.pop();
                j++;
            }
            s[q.front()-1]=m;
            q.pop();
            m++;
        }
        for(m=0;m<n;m++)
          cout<<s[m]<<" ";
        cout<<'\n';
        i++;
    }
    return 0;
}
