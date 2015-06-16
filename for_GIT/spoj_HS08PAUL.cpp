#include <bits/stdc++.h>
using namespace std;
bitset<10000000> arr;
//int prime[1000000];
int dp[10000000];
int dpp[3163][3163];
int power[3163];
int power2[57];
#define eps 0.0000001
int main() {
	// your code goes here
	int i,j,k,n;
	set<pair<int,int> > s;
	for(i=3;i<10000000;i+=2){
		arr[i]=true;
		arr[i-1]=false;
	}
	arr[2]=true;
	arr[0]=false;arr[1]=false;
	for(i=3;i<3163;i+=2){
		if(arr[i]){
			for(j=i*i;j<10000000;j+=2*i)
				arr[j]=false;
		}
	}
	int x;
	memset(dp,0,sizeof(dp));
	memset(dpp,0,sizeof(dpp));
	for(i=1;i<3163;i++)
		power[i]=i*i;
	for(i=1;i<57;i++)
		power2[i]=i*i*i*i;
	/*
	for(i=1;i<3163;i++){
		for(j=1;j<57;j++){
			if(power[i]==power2[j]){
				dpp[j][i]=dpp[i][j]=1;
			}
		}
	}*/
	for(i=1;i<57;i++){
		for(j=1;j<3163;j++){
			x=power2[i]+power[j];
			if(x>=10000000)
				break;
			if(arr[x]){
				/*if(dpp[i][j]==1 && dpp[j][i]==1){
					dp[x]++;
			     	dpp[i][j]=2;
					dpp[j][i]=2;
				}
				if(dpp[i][j]==0 && dpp[j][i]==0)
					dp[x]++;*/
				if(s.find(make_pair(power2[i],power[j]))==s.end() && s.find(make_pair(power[j],power2[i]))==s.end()){
					dp[x]++;
					s.insert(make_pair(power2[i],power[j]));
					s.insert(make_pair(power[j],power2[i]));
				}
			}

		}
	}
	for(i=1;i<10000000;i++)
		dp[i]+=dp[i-1];

	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%d\n",dp[n]);
	}
	return 0;
}
