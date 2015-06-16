#include<bits/stdc++.h>
using namespace std;
int dp[25][80];
int arr[1005][3];
int n;
int main(){
    int t;
    scanf("%d",&t);
    int a,b;
    int x,y,z;
    while(t--){
        scanf("%d %d",&a,&b);
        scanf("%d",&n);
        memset(dp,-1,sizeof(dp));
        for(i=0;i<n;i++){
            scanf("%d %d %d",x,y,z);
            dp[x][y]=z;
            arr[i][0]=x;
            arr[i][1]=y;
            arr[i][2]=z;
        }
        printf("%d\n",x(a,b));
    }
    return 0;
}
int x(int a,int b){

    if(dp[a][b]!=-1)
        return dp[a][b];
    dp[a][b]=0;
    int d=0;
    for(i=0;i<n;i++){
        if()
    }
    return dp[a][b]=d;
}
