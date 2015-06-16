#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long int
ULL dp[100005];
ULL c[100005];
int main() {
    int t,i,j,m,n;
    dp[0]=1;
    dp[1]=0;c[0]=0;
    for(i=2;i<=100004;i++){
       c[i]=dp[i-2]+c[i-2];
       dp[i]=dp[i-2]+2*c[i];
    }
    while(1){
        cin>>n;
        if(n==-1)
            break;
        cout<<dp[n]<<endl;
    }
	return 0;
}
