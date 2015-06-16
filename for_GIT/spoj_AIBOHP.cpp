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
char arr[6105],brr[6105];
short dp[6105][6105];
int dpin(int n);
int main(){
    int t,x,d,j,i;
    scanf("%d",&t);
    while(t--){
        scanf("%s",arr);
        x=strlen(arr);j=0;
        for(i=x-1;i>=0;i--){
            brr[j++]=arr[i];
        }
       // printf("%s %s",arr,brr);
        d=dpin(x);
        printf("%d\n",x-d);
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
