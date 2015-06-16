#include <iostream>
#include<string>
#include<stdio.h>
#include<math.h>
#include<queue>
#include<algorithm>
#include<stack>
#include<string.h>
using namespace std;
int main()
{
    int n,d,x,i=0,m,act;
    queue<int> q;
    stack<int> s;
    int arr[1001];
    while(1){
        scanf("%d",&n);
        if(n==0)
            break;
        for(i=1;i<=n;i++){
            scanf("%d",&x);
            q.push(x);
        }
        m=0;act=1;
        while(1){
          while(!q.empty()){
           if((s.empty()==0) && (s.top()==act)){
                s.pop();
                act++;
           }
           else{
             x=q.front();
             if(x==act){
                q.pop();
                act++;
             }
             else{
                s.push(x);
                q.pop();
             }
           }
          }
        if(s.empty()==0){
           while(!s.empty()){
             x=s.top();
             if(x==act){
                act++;
                s.pop();
             }
             else{
               if((m!=0) && (arr[m-1]==act)){
                 m=m-1;
                 act++;
               }
               else{
                  arr[m++]=x;
                  s.pop();
               }
             }
          }
        }
        break;
     }
     i=0;
     if(m==0){
        printf("yes\n");
     }
     if(m!=0){
        for(i=0;i<m-1;i++){
           if(arr[i]<arr[i+1]){
              printf("no\n");
              break;
           }
        }
        if(i==m-1)
           printf("yes\n");
        }
    }
    return 0;
}
