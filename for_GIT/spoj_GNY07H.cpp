#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long int
ULL dp[100005];
ULL c[100005],d[100005];
int main() {
    int t,i,j,m,n;
    dp[0]=1;
    dp[1]=1;
    for(i=2;i<=100004;i++){
       c[i]=dp[i-2]+c[i-1];
       d[i]=dp[i-2]+d[i-2];
       dp[i]=dp[i-1]+dp[i-2]+2*c[i]+d[i];
    }
    cin>>t;
    for(i=1;i<=t;i++){
        cin>>n;
        cout<<i<<' '<<dp[n]<<endl;
    }
	return 0;
}
