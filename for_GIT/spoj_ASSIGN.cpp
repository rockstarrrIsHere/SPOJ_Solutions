#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ULL unsigned long long int
ULL dp[1048586];
int arr[25][25];
ULL x(int n);
int main() {
    int t,n,i,j;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&arr[i][j]);
        memset(dp,0,sizeof(dp));
        printf("%llu\n",x(n));
    }
	return 0;
}
unsigned long long int x(int n){
    ULL m,i,j,ele;
    m=1<<n;
    dp[0]=1;    for(i=1;i<m;i++){
        ele=__builtin_popcount(i);
        for(j=0;j<n;j++){
            if(arr[ele-1][j] && (i&(1<<j)))
               dp[i]+=dp[i&~(1<<j)];
        }
    }
    return dp[m-1];
}
