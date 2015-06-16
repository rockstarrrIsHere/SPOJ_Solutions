#include <bits/stdc++.h>
using namespace std;
int dp[2005][2005];
int s,n;
int main() {
    int i,j,siz,value;
	memset(dp,0,sizeof(dp));
	cin>>s>>n;
	for(i=1;i<=n;i++){
		cin>>siz>>value;
        for(j=1;j<=s;j++){
            if(siz>j) dp[i][j]=dp[i-1][j];
            else dp[i][j]+=max(dp[i-1][j],dp[i-1][j-siz]+value);
        }
	}
	cout<<dp[n][s]<<endl;
	return 0;
}

