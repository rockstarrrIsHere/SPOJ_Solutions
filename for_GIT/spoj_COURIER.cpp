#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(i=a;i<b;i++)
#define MAX (1<<28)
#define pii pair<int,int>
#define pb(c,d) push_back(pii(c,d))
#define MAXX 102
int N,M,B;
vector<pii> v;
int arr[MAXX][MAXX];
long long int dp[MAXX][(1<<13)];
long long int TSP(int node,int bitmask){
	if(dp[node][bitmask]!=-1)	return dp[node][bitmask];
	long long int d=(MAX);
	int i;int r=0;
	REP(i,0,v.size())
		if( !(bitmask & (1<<i)) ){
			r=1;
			d=min(d,arr[node][v[i].first]+arr[v[i].first][v[i].second]+TSP(v[i].second,bitmask|(1<<i)));
		}
	if(!r) return dp[node][bitmask]=arr[node][B];
	return dp[node][bitmask]=d;
}
int main() {
	// your code goes here
	int t,i,j,k;
	scanf("%d",&t);
	while(t--){
		memset(dp,-1,sizeof(dp));
		v.clear();
		scanf("%d%d%d",&N,&M,&B);--B;
		REP(i,0,N) REP(j,0,N) arr[i][j]=(MAX);
		REP(i,0,N) arr[i][i]=0;
		int a,b,c;
		while(M--){
			scanf("%d%d%d",&a,&b,&c);--a;--b;
			arr[a][b]=min(arr[a][b],c);
			arr[b][a]=min(arr[b][a],c);
		}
		int Z;scanf("%d",&Z);
		while(Z--){
				scanf("%d%d%d",&a,&b,&c);--a;--b;
				REP(i,0,c) v.pb(a,b);
		}
		REP(k,0,N) REP(i,0,N) REP(j,0,N) arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
		printf("%d\n",TSP(B,0));
	}
	return 0;
}