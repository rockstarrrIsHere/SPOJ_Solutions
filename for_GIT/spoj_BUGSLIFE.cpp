#include<bits/stdc++.h>
using namespace std;
int visited[2002];
int dp[2002];
vector<set<int> > v(2002);
int DFS(int n);
int main(){
	int t;
	int i,j,n,m,x,y;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
        scanf("%d %d",&n,&m);
        for(j=0;j<m;j++){
            scanf("%d %d",&x,&y);
            v[x].insert(y);
            v[y].insert(x);
        }
        printf("Scenario #%d:\n",i);
        /*set<int>::iterator itr;
        for(j=1;j<=n;j++){
        	printf("%d->",j);
        	for(itr=v[j].begin();itr!=v[j].end();itr++)
        		printf("%d ",*itr);
        printf("\n");
        }*/
        memset(visited,0,sizeof(visited));
        for(j=0;j<=n;j++)
            dp[j]=-1;
        for(j=1;j<=n;j++){
        	if(!visited[j]){
        		dp[j]=1;
        		if(!DFS(j))
        			break;
        	}
        }
        if(j>n)
            printf("No suspicious bugs found!\n");
        else
            printf("Suspicious bugs found!\n");
        for(j=0;j<=n;j++)
            v[j].clear();
	}
	return 0;
}
int DFS(int n){
    int x,j;
    set<int>::iterator itr;
    visited[n]=1;
    for(itr=v[n].begin();itr!=v[n].end();itr++){
       	if(!visited[*itr]){
       		visited[*itr]=1;
       		if(dp[n]==1) dp[*itr]=0;
       		else dp[*itr]=1;
       		if(!DFS(*itr))
       			break;
      	}
       	else{
       		if(dp[*itr]==dp[n])
            	break;
       	}
    }
    if(itr==v[n].end())
      	return 1;
    return 0;
}
