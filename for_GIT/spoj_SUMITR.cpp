#include<bits/stdc++.h>
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std;
main(){
    int t,i,j,n,arr[105][105],dp[105][105],d;
    cin>>t;
    while(t--){
        d=0;
        cin>>n;
        FOR(i,n);
            FOR(j,i+1)
                scanf("%d",&arr[i][j]);
        dp[0][0]=arr[0][0];
    FOR(i,n)
        if(i!=0)
        FOR(j,i+1){
            if(j==0)
                dp[i][j]=dp[i-1][j]+arr[i][j];
            else if(j==i)
                dp[i][j]=dp[i-1][i-1]+arr[i][j];
            else
                dp[i][j]=max(dp[i-1][j-1]+arr[i][j],dp[i-1][j]+arr[i][j]);
        }
    for(j=0;j<n;j++)
        d=max(d,dp[n-1][j]);
        cout<<d;
    }
}








