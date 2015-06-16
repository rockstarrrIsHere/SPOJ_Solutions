#include <bits/stdc++.h>
using namespace std;
int dp[1010][1010][3];
int arr[1010];
int main() {
	int x,n,i,j,k=1,sum;
	while(1){
		memset(dp,0,sizeof(dp));
		memset(arr,0,sizeof(arr));
		cin>>n;
		if(n==0)
			break;
		i=1;
		for(i=1;i<=n;i++)
			cin>>arr[i];
		for(i=1;i<=n;i++){
			for(j=0;j<=1;j++){
            	if(!j) {dp[i][i+j][0]=dp[i][i+j][1]=dp[i][i+j][2]=arr[i];}
            	else{
            		dp[i][i+j][0]=arr[i];
            		dp[i][i+j][1]=arr[i+j];
            		dp[i][i+j][2]=max(arr[i],arr[i+j]);
            	}
        	}
		}
		/*
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++)
				cout<<dp[i][j][0]<<','<<dp[i][j][1]<<','<<dp[i][j][2]<<' ';
			cout<<endl;
		}*/

		for(i=n-2;i>=1;i--){
			for(j=2+i;j<=n;j++){
            	dp[i][j][0]=arr[i];
            	if(arr[i+1]>=arr[j]) dp[i][j][0]+=dp[i+2][j][2];
            	else dp[i][j][0]+=dp[i+1][j-1][2];
            	dp[i][j][1]=arr[j];
            	if(arr[i]>=arr[j-1]) dp[i][j][1]+=dp[i+1][j-1][2];
            	else dp[i][j][1]+=dp[i][j-2][2];
        		dp[i][j][2]=max(dp[i][j][0],dp[i][j][1]);
        	}
		}

		/*for(i=1;i<=n;i++){
			for(j=1;j<=n;j++)
				cout<<dp[i][j][0]<<','<<dp[i][j][1]<<','<<dp[i][j][2]<<' ';
			cout<<endl;
		}*/


		sum=0;
		for(i=1;i<=n;i++)
			sum+=arr[i];
		x=0;
		i=1;
		j=n;
		while(i<=j){
			if(arr[i]>=arr[j]){
				x+=arr[i];
				if(arr[i+1]>=arr[j])
					i+=2;
				else{
					i++;j--;
				}

			}
			else{
				x+=arr[j];
				if(arr[i]>=arr[j-1]){
					i++;j--;
				}
				else{
					j-=2;
				}
			}
		}
		//cout<<2*x-sum<<endl;
		x=max(2*x-sum,2*dp[1][n][2]-sum);
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n",k,2*dp[1][n][2]-sum);
		//cout<<<<endl;
		k++;
	}
	return 0;
}

