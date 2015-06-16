#include<bits/stdc++.h>
using namespace std;
int dp[105][105][2];
int x(int n,int k,int a);
int main(){
    int t;
    scanf("%d",&t);
    int i,n,k;
    while(t--){
        scanf("%d %d %d",&i,&n,&k);
        memset(dp,-1,sizeof(dp));
        printf("%d %d\n",i,x(n-2,k,0)+x(n-2,k,1));
    }
    return 0;
}
int x(int n,int k,int a){
    int i,j;
    if(n<0){
    	if(k==0)	return 1;
    	return 0;
    }
    if(k<0)
    	return 0;

    if(dp[n][k][a]!=-1)
    	return dp[n][k][a];
    int ans=0;

    if(a==0){
    	ans+=x(n-1,k,1)+x(n-1,k,0);
    }
    if(a==1){
    	ans+=x(n-1,k,0)+x(n-1,k-1,1);
    }
    return dp[n][k][a]=ans;
}
