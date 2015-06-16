#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ULL unsigned long long int
ULL dp[2000005];
void precomp();
ULL int_mod(ULL a);
ULL mod_inv(ULL a,ULL b);
ULL mod_inv(ULL a,ULL b){
	//precomp();
	ULL t;
	if(b==0)
		return 1;
	if(b==1)
		return int_mod(a);
	t=mod_inv(a,b/2);
	return b%2==0?int_mod(t*t):int_mod(int_mod(t*t)*a);
}
void precomp(){
	int i;
	dp[1]=dp[0]=1;
	for(i=2;i<=2000000;i++)
		dp[i]=int_mod(dp[i-1]*i);
}
ULL int_mod(ULL a){
	return (a+MOD)%MOD;
}
int main() {
	// your code goes here
	precomp();
	ULL t,n;ULL x,ans;
	scanf("%llu",&t);
	while(t--){
		scanf("%llu",&n);
		if(n==0){
			cout<<0<<endl;
			continue;
		}
		ans=int_mod(n*int_mod(int_mod(mod_inv(dp[n-1],MOD-2)*mod_inv(dp[n],MOD-2))*dp[2*n-1]));
		printf("%llu\n",ans);
	}
	return 0;
}

