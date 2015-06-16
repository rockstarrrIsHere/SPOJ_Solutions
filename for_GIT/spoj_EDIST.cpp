#include <bits/stdc++.h>
using namespace std;
char arr[2001],brr[2001];
short LCS(int n,int m);
int main() {
	// your code goes here
	int t;
	short d;
	scanf("%d",&t);
	while(t--){
		scanf("%s",arr);
		scanf("%s",brr);
		d=LCS(strlen(arr),strlen(brr));
		printf("%d\n",d);
	}
	return 0;
}
short LCS(int n,int m){
	short dp[n+1][m+1],temp1,temp2,val;
	int i,j;
	dp[0][0]=0;
	for(i=1;i<=n;i++)
		dp[i][0]=i;
	for(j=1;j<=m;j++)
		dp[0][j]=j;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			{
				val=arr[i-1]==brr[j-1]?0:1;
				temp1=dp[i-1][j-1]+val;
				temp2=min(dp[i-1][j]+1,dp[i][j-1]+1);
				dp[i][j]=min(temp1,temp2);
			}
		}
	}
	return dp[n][m];
}
