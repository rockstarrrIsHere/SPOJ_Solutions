#include <bits/stdc++.h>
using namespace std;
#define MAX 16
int n;
int dp[MAX][(1<<MAX)];
int peri[MAX][(1<<MAX)];
int arr[MAX];
int solve(int index,int mask){
    if(mask==(1<<n)-1){
        peri[index][mask]=1;
        return arr[index];
    }
    if(dp[index][mask]!=-1) return dp[index][mask];
    dp[index][mask]=0;
    int i;
    int cnt,val=0;
    for(i=0;i<n;i++){
        if(!(mask&(1<<i))){
            val=solve(i,mask | (1<<i))+abs(arr[i]-arr[index]);
            if(val>dp[index][mask]){
                dp[index][mask]=val;
                peri[index][mask]=0;
            }
            if(val==dp[index][mask]) peri[index][mask]+=peri[i][mask|(1<<i)];
        }
    }
    return dp[index][mask];
}
int main() {
    int i,val,maxval;
    int cnt;
    while(1){
        val=0;maxval=0;
        scanf("%d",&n);
        if(!n)
            break;
        for(i=0;i<n;i++) scanf("%d",&arr[i]);
        memset(dp,-1,sizeof(dp));
        memset(peri,0,sizeof(peri));
        for(i=0;i<n;i++){
            val=solve(i,(1<<i))+arr[i];
            if(val>maxval){
                maxval=val;
                cnt=0;
            }
            if(val==maxval)
                cnt+=peri[i][(1<<i)];
        }
        maxval+=(n<<1);
        printf("%d %d\n",maxval,cnt);
    }
	return 0;
}
