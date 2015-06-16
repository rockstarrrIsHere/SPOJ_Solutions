#include <bits/stdc++.h>
using namespace std;
#define MOD 1300031
#define ULL unsigned long long int
ULL dp[1000005];
void precomp();
ULL calc_power(ULL a,ULL b);
ULL factmod(ULL n,ULL p);
int NN=0;
int tt=0;
ULL ff;
ULL int_mod(ULL a);
ULL mod_inv(ULL a,ULL b);
//bool arr(1000001);
int prime[1000001];
int primeformul[1000001];
vector<int> pp;
void prii();
void prii(){
	//memset(arr,tr,sizeof(bool));
	bitset<1000001> arr;
	ULL i,j,k;
	for(i=0;i<1000001;i++)
		arr[i]=true;
	arr[0]=arr[1]=false;
	arr[2]=true;
	for(i=3;i<1000001;i+=2){
		if(arr[i]){
			for(j=i*i;j<1000001;j=j+2*i)
				arr[i]=false;
		}
	}
	//memset(prime,0,sizeof(prime));
	for(i=0;i<1000001;i++){
		if(arr[i]==true){
			pp.push_back(i);
			//prime[i]=1;
		}
	}
}
ULL factmod(ULL n,ULL p){
	ULL k=0;
	while(n>=p){
		k+=n/p;
		n/=p;
	}
	return k;
}
ULL mod_inv(ULL a,ULL b){
	//precomp();
	ULL t;
	if(b==0)
		return 1;
	if(b==1){
		if(a>MOD)
		{
			NN=1;
			a=int_mod(a);
		}
		return int_mod(a);
	}
	t=mod_inv(a,b/2);
	if(b%2==0 && t*t>MOD)
		NN=1;
	if(b%2==1 && t*t*a>MOD)
		NN=1;
	return b%2==0?int_mod(t*t):int_mod(int_mod(t*t)*a);
}
void precomp(){
	int i;
	dp[1]=dp[0]=1;int j=0;
	for(i=2;i<=1000000;i++){
		if(dp[i-1]*i>MOD){
			dp[i]=int_mod(dp[i-1]*i);
			if(!j){
				ff=i;
				j++;
			}
		}
		else
			dp[i]=dp[i-1]*i;
	}
}
ULL int_mod(ULL a){
	return (a+MOD)%MOD;
}
int main() {
	// your code goes here
	precomp();
	int ttt;
	prii();
	ULL t,n;ULL x,ans,r,p,k,i,j,mm;
	//scanf("%llu",&t);
	cout<<ff<<endl;
	while(scanf("%llu %llu",&n,&r)!=EOF){
		ttt=0;
		if(n==0){
			cout<<0<<endl;
			continue;
		}
		ans=int_mod(int_mod(mod_inv(dp[n-r],MOD-2)*mod_inv(dp[r],MOD-2))*dp[n]);
		printf("%llu\n",ans);
		k=pp.size();
		memset(prime,0,sizeof(prime));
		for(i=0;i<k;i++){
			p=pp[i];
			mm=(factmod(n,p)-factmod(r,p)-factmod(n-r,p));
			if(mm>0)
				prime[p]=mm;
		}
		tt=1;ttt=0;
		for(i=0;i<k;i++){
			p=pp[i];
			if(prime[p]){
				ans=calc_power(p,prime[p]);
				if(ans>MOD || ans*tt>MOD){
					ttt=1;
					break;
				}
				tt*=ans;
			}
		}
		if(ttt)
		printf("Exceeds\n");
		else
		printf("Does not exceed\n");
	}
	return 0;
}
ULL calc_power(ULL a,ULL b){
	ULL t;
	if(b==0)
		return 1;
	if(b==1)
		return a;
	t=calc_power(a,b/2);
	if(t==-1)
		return -1;
	if(b%2==0 && t*t>MOD)
		return -1;
	if(b%2==1 && t*t*a>MOD)
		return -1;
	return b%2==0?t*t:t*t*a;
}
