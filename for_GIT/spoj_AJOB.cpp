#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long int
ULL MOD;
ULL p;
ULL int_mod(ULL a){
	return (a+MOD)%MOD;
}
ULL mod_inv(ULL a,ULL b){
	ULL t;
	if(b==0)
		return 1;
	if(b==1)
		return int_mod(a);
	t=mod_inv(a,b/2);
	return b%2==0?int_mod(t*t):int_mod(int_mod(t*t)*a);
}
ULL factmod(ULL n){
	ULL k=0;
	while(n>=p){
		k+=n/p;
		n/=p;
	}
	return k;
}
ULL fact(ULL n){
	ULL ans=1,i,m;
	while(n>0){
		for(i=2,m=n%p;i<=m;i++)
			ans=(ans*i)%MOD;
		n/=MOD;
		if(n%2==1)
			ans=MOD-ans;
	}
	return ans;
}
ULL nCr(ULL n,ULL r){
	if(factmod(n)>factmod(r)+factmod(n-r))
		return 0;
	return int_mod(fact(n)*int_mod(mod_inv(fact(r),p-2)*mod_inv(fact(n-r),p-2)));

}
int main() {
	ULL t,n,k,ans;
	scanf("%llu",&t);
	while(t--){
		ans=0;
		scanf("%llu %llu %llu",&n,&k,&p);
		MOD=p;
		if(k>n){
			printf("0\n");
			continue;
		}
		ans+=nCr(n,n-k);
		if(n==k){
			printf("%llu\n",ans);
			continue;
		}
		ans=int_mod(ans+nCr(n,n-k-1));
		printf("%llu\n",ans);
	}
	return 0;
}
