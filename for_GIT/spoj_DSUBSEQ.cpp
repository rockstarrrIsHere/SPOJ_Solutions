#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int int_mod(unsigned long long int a){
	return (a+MOD)%MOD;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
		char s[100005];
		cin>>s;
		unsigned long long int dp[100005];
		int last[100005];
		memset(dp,0,sizeof(dp));
		memset(last,-1,sizeof(last));
		int i;
		dp[0]=1;int k=strlen(s);
		for(i=1;i<=k;i++){
			dp[i]=int_mod(2*dp[i-1]);
			if(last[s[i-1]]!=-1){
				dp[i]=int_mod(dp[i]-dp[last[s[i-1]] -1 ]);
			}
			last[s[i-1]]=i;
		}
		cout<<dp[k]<<endl;
	}
	return 0;
}
