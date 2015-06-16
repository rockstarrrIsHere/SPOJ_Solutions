#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include<string.h>
#include <map>
#include <set>
#include <utility>
#include <climits>
#include <cfloat>
#include <cassert>
using namespace std;
int visited[20005];
void x(int n);
int my_mod(char s[],int n);
struct node{
    char data[1000];
    int mod;
};
int my_mod(char s[],int n){
    int d=0,i,x;
    char c;
    x=strlen(s);
    if(x>=17){
        for(i=0;i<x;i++)
            d=(10*d+(s[i]-'0'))%n;
        return d;
    }
    return atoll(s)%n;
}
int main(){
    int t,n,i;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            visited[i]=0;
        x(n);
    }
    return 0;
}
void x(int n){
    queue<node> q;
    node t,t1,t2;
    strcpy(t.data,"1");
    t.mod=1%n;
    visited[t.mod]=1;
    q.push(t);
    while(!q.empty()){
        t=q.front();
        if(t.mod==0){
            printf("%s\n",t.data);
            break;
        }
        q.pop();
        strcpy(t1.data,t.data);
        strcat(t.data,"0");
        t.mod=my_mod(t.data,n);
        if(!visited[t.mod]){
            q.push(t);
            visited[t.mod]=1;
        }
        strcpy(t2.data,t1.data);
        strcat(t2.data,"1");
        t2.mod=my_mod(t2.data,n);
        if(!visited[t2.mod]){
            q.push(t2);
            visited[t2.mod]=1;
        }
    }

}

