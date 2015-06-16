#include <bits/stdc++.h>
using namespace std;
int main() {
    int t,r,c,i,j,d;
    cin>>t;
    while(t--){
        cin>>r>>c;
        int dp[105][105];
        memset(dp,0,sizeof(dp));
        for(i=1;i<=r;i++){
            for(j=1;j<=c;j++){
                cin>>dp[i][j];
            }
        }
        for(i=1;i<=r;i++){
            for(j=1;j<=c;j++){
                d=0;
                d=max(max(dp[i-1][j-1],dp[i-1][j+1]),dp[i-1][j]);
                dp[i][j]+=d;
            }
        }
        d=0;
        for(j=1;j<=c;j++)
            d=max(d,dp[r][j]);
        cout<<d<<endl;
    }


	return 0;
}
