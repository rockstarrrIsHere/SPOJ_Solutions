#include<bits/stdc++.h>
using namespace std;
int dp[2][205][205];
int arr[205][205];
int m,n;
int x();
int main(){
    int t,i,j;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&m,&n);
        for(i=1;i<=m;i++){
            char s[205];
            scanf("%s",s);
            for(j=0;j<n;j++){
                if(s[j]=='T') arr[i][j+1]=2;
                if(s[j]=='#') arr[i][j+1]=0;
                if(s[j]=='0') arr[i][j+1]=1;
            }
        }
        memset(dp,0,sizeof(dp));
        printf("%d\n",x());
    }
    return 0;
}
int x(){
    int i,j;
    for(i=m;i>=1;i--){
        for(j=n;j>=1;j--)
            if(arr[i][j])
                dp[0][i][j]=max(dp[0][i][j+1],(dp[1][i+1][j]))+arr[i][j]-1;
        for(j=1;j<=n;j++)
            if(arr[i][j])
                dp[1][i][j]=max(dp[1][i][j-1],dp[0][i+1][j])+arr[i][j]-1;
    }
    return dp[0][1][1];
}
