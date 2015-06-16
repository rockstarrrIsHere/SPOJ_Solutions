#include<bits/stdc++.h>
using namespace std;
int n;
int xx();
int MOD=10039;
int MODx=100390000;
int dp[100005],arr[100005];
int brr[100005];
int main(){
	int i,j;
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int sum=0;
		int x;
		int d;
		vector<pair<int,int> > v[MOD+1];
		for(i=1;i<=n;i++){
			scanf("%d",&arr[i]);
			sum+=arr[i];
			brr[i]=sum;
			x=(brr[i]+MODx)%MOD;
			v[x].push_back(make_pair(brr[i],i));
		}

		d=xx();
		int cnt=0;
		int k;
		for(i=0;i<=n;i++){
			if(i==0){
				x=(d+MODx)%MOD;
				k=v[x].size();
				for(j=0;j<k;j++){
					if(v[x][j].first==d)
						cnt++;
				}
			}
			else{
				x=(d+brr[i]+MODx)%MOD;
				k=v[x].size();
				for(j=0;j<k;j++){
					if(v[x][j].first==(d+brr[i]) && v[x][j].second>i)
						cnt++;
				}
			}
		}
		printf("%d %d\n",d,cnt);

	}
}
int xx(){
	int i;
	dp[1]=arr[1];
	for(i=2;i<=n;i++)
		dp[i]=max(dp[i-1]+arr[i],arr[i]);
	int m=dp[1];
	for(i=2;i<=n;i++)
		m=max(m,dp[i]);
	return m;
}

