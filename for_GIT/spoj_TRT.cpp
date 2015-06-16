#include <bits/stdc++.h>
using namespace std;
int dp[2010][2010];
int arr[2010];
int x(int i,int j,int a);
int x(int i,int j,int a){
	if(i>j)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	int d=0;
	d=max(a*arr[i]+x(i+1,j,a+1),x(i,j-1,a+1)+a*arr[j]);
	return dp[i][j]=d;
}
int main() {
	int n,i,j,k=1,sum;
		memset(dp,-1,sizeof(dp));
		memset(arr,0,sizeof(arr));
		cin>>n;
		for(i=1;i<=n;i++)
			cin>>arr[i];
		/*for(i=1;i<=n;i++){
			dp[i][i][0]=dp[i][i][1]=dp[i][i][2]=arr[i];
		}
		int a=n+1;
		for(i=n-1;i>=1;i--){
			for(j=1+i;j<=n;j++){
				dp[i][j][0]=(n-j+i+1)*arr[i]+dp[i+1][j][2];
				dp[i][j][1]=(n-j+i+1)*arr[j]+dp[i][j-1][2];
				dp[i][j][2]=max(dp[i][j][0],dp[i][j][1]);
				//a++;
			}

		}*/
		cout<<x(1,n,1)<<endl;
	return 0;
}

