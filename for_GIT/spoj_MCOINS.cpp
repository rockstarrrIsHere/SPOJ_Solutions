#include <bits/stdc++.h>
using namespace std;
// do not ude memoization, as stack overflow might occur during recursion.

int k,l;
int dp[1000005];
int x(int n);
int main() {
	// your code goes here
	int m;
	scanf("%d %d %d",&k,&l,&m);
	int i,n;
	memset(dp,0,sizeof(dp));
	for(i=1;i<=1000000;i++){
		if(i>=1 && (dp[i-1]==0) || (i>=l && dp[i-l]==0) || (i>=k && dp[i-k]==0) )
			dp[i]=1;
	}
	for(i=0;i<m;i++){
		scanf("%d",&n);
		char c=dp[n]==1?'A':'B';
		printf("%c",c);
	}
	printf("\n");
	return 0;
}
/*
int x(int n){
	if(n==0){

		return 0;
	}
	if(n==1){
		return dp[1]=1;
	}
	if(dp[n]!=-1)
		return dp[n];
	dp[n]=0;


	//dp[n]=~(x(n-1) & x(n-l) & x(n-k));
	return dp[n];
}
*/
