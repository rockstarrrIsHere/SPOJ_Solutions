#include <bits/stdc++.h>
using namespace std;
int dp[105][505];
int main() {
	// your code goes here
	int best,budg,n,cost,fun,i,j;
	while(scanf("%d%d",&budg,&n)==2){
		if(!budg && !n)	break;
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++){
			scanf("%d%d",&cost,&fun);
			for(j=1;j<=budg;j++){
				if(j<cost) dp[i][j]=dp[i-1][j];
				else dp[i][j]=max(dp[i-1][j],dp[i-1][j-cost]+fun);
			}
		}
		for(j=budg,best=dp[n][j];j;j--)
			if(dp[n][j]<best)
				break;
		printf("%d %d\n",j+1,best);
	}
	return 0;
}
