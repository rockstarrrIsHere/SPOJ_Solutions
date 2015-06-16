#include<bits/stdc++.h>
using namespace std;
int dp[15][15];
int main(){
    int x,y,i,j;
    while(1){
        scanf("%d %d",&x,&y);
        if(x==-1 && y==-1)
            break;
        memset(dp,0,sizeof(dp));
        for(i=0;i<=x;i++){
            for(j=0;j<=y;j++){
                if(i==0 || j==0){
                    dp[i][j]=1;
                }
                else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        if(dp[x][y]==x+y){
            printf("%d+%d=%d\n",x,y,x+y);
        }
        else{
            printf("%d+%d!=%d\n",x,y,x+y);
        }
    }
    return 0;
}

