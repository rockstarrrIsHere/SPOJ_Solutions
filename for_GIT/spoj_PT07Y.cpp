#include<bits/stdc++.h>
using namespace std;
int N;
void DFS(int i);
int visited[10002];
vector<vector<int> > v(10002);
int main(){
    int n,m,i,j,x,y;
    scanf("%d %d",&n,&m);
    N=0;
    for(i=0;i<m;i++){
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    if(m==n-1){
        memset(visited,0,sizeof(visited));
        DFS(1);
        //printf("%d\n",N);
        if(N==n)
            printf("YES\n");
        else
            printf("NO\n");
    }
    else
        printf("NO\n");
	v.resize(0);
	return 0;
}
void DFS(int i){
    int x,m;
    N++;
    x=v[i].size();
    visited[i]=1;
    for(m=0;m<x;m++){
        if(!visited[v[i][m]]){
            DFS(v[i][m]);
        }
    }
}







