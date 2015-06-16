#include<bits/stdc++.h>
using namespace std;
int n;
int arr[30];
int sumdp[30][30];
int dp[30][30];
void DFS(int i,int j);
void getsumdp();
int main(){
    int k=1;
    int i,j,sum,m;
    char s[30];
    int ans;
    while(1){
        ans=0;
        scanf("%s",s);
        if(strcmp(s,"bye")==0)
        	break;
        n=strlen(s);
        sum=0;
        for(i=0;i<n;i++){
            sum+=(s[i]-'0');
            arr[i+1]=sum;
        }
        /*for(i=1;i<=n;i++)
        printf("%d ",arr[i]);*/
        memset(sumdp,-1,sizeof(sumdp));
        memset(dp,-1,sizeof(dp));
        getsumdp();
        for(m=1;m<=n;m++){
            if(dp[1][m]==-1)
                DFS(1,m);
        }
        for(m=1;m<=n;m++){
            if(dp[1][m]!=-1 && dp[1][m]!=-2)
                ans+=dp[1][m];
        }
        printf("%d. %d\n",k,ans);
    	k++;
    }
    return 0;
}
void DFS(int i,int j){
    int m;
    dp[i][j]=0;
    if(j==n){
        dp[i][j]=1;
        return ;
    }
    for(m=j+1;m<=n;m++){
        if(sumdp[j+1][m]>=sumdp[i][j] && dp[j+1][m]!=-2){
            if(dp[j+1][m]!=-1){
                dp[i][j]+=dp[j+1][m];
            }
            else{
                DFS(j+1,m);
                if(dp[j+1][m]!=-2 && dp[j+1][m]!=-1)
                    dp[i][j]+=dp[j+1][m];
            }
        }
    }
}
void getsumdp(){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){
            sumdp[i][j]=arr[j]-arr[i-1];
        }
    }
}
