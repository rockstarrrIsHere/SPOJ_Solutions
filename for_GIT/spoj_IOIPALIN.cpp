#include <cassert>
#include<string>
#include<string.h>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
char arr[5005],brr[5005];
short dp[5005][5005];
int dpin(int n);
int main(){
    int t,x,d,j,i;
    scanf("%d",&n);
    {
        scanf("%s",arr);
        j=0;
        for(i=n-1;i>=0;i--){
            brr[j++]=arr[i];
        }
       // printf("%s %s",arr,brr);
        d=dpin(n);
        printf("%d\n",n-d);
    }
    return 0;
}
int dpin(int n){

    int i,j;
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(arr[i-1]==brr[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}
