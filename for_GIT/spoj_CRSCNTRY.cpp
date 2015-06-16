#include<iostream>
#include<string>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<algorithm>
#include<stack>
#include<vector>
#include<list>
#include<bitset>
#include<string.h>
using namespace std;
//#define MOD 1000000007
#define MAX 1000000
#define LMT 1001
#define ULL int
int dp[2002][2002];
int arr[2002],brr[2002];
int X(int m,int n);
int main()
{
    int t,d,x,j,m,n;
    scanf("%d",&t);
    while(t--){
        d=0;
        x=0;
        while(1){
            scanf("%d",&arr[x++]);
            if(arr[x-1]==0){
                m=x;
                break;
            }
        }x=0;j=0;
        while(1){
            while(1){
                scanf("%d",&brr[x++]);
                if(brr[0]==0){
                    j=1;
                    break;
                }
                if(brr[x]==0 && brr[0]!=0){
                    n=x;
                    break;
                }
            }
            if(j==1)
               break;
            d=max(d,X(m,n));
        }
        printf("%d\n",d);

    }
    return 0;
}
int X(int m,int n){
    int i,j;
    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            if(i==0 || j==0)
                dp[i][j]=0;
            if(arr[i-1]==brr[j-1])
                dp[i][j]=1+dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[m][n];
}
