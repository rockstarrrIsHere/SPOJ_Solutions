#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define scani(x) scanf("%d",&x)
#define INF 1e9
int arr[205][205];

int main() {
	// your code goes here
	int i,j,t,m,k,n,x,y;
	scani(t);
	while(t--){
		scani(m);scani(k);scani(n);
		rep(i,0,m) rep(j,0,m) arr[i][j]=(i==j);
		rep(i,0,k) {scani(x);scani(y);arr[x-1][y-1]=arr[y-1][x-1]=1;}
		rep(k,0,m) rep(i,0,m) rep(j,0,m) arr[i][j]|=(arr[i][k]&arr[k][j]);
		int dp[2][205];
		rep(j,0,m) dp[0][j]=INF;
		dp[0][0]=0;
		//memset(dp,-1,sizeof(dp));dp[0][0]=0;
		int prev=0,curr=1;
		rep(i,0,n){
			scani(x);--x;
			y=INF;
			rep(j,0,m){
				y=min(y,dp[prev][j]);
				if(arr[x][j]) dp[curr][j]=y+(j!=x);
				else dp[curr][j]=INF;
			}
			rep(j,0,m) dp[prev][j]=dp[curr][j];

		}
		int ans=INF;
		rep(j,0,m) ans=min(ans,dp[prev][j]);
		ans>=INF?printf("-1\n"):printf("%d\n",ans);
	}

	return 0;
}
