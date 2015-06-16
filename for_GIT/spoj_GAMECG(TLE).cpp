#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long int
#define MOD 1300031
int dp[1000001];
ULL modInverse[1000001];
void precomp();
int int_mod(ULL a);
void mod_inv();
int intn_mod(long long int a);
void mod_inv(){
	memset(modInverse,0,sizeof(modInverse));
	modInverse[1]=1;
	int i;
	for(i=2;i<=1000000;i++)
		modInverse[i]=(intn_mod(-((MOD/i)*modInverse[MOD%i])))+MOD;

}
int intn_mod(long long int a){
	return (a+MOD)%MOD;
}
void precomp(){
	int i;
	dp[1]=dp[0]=1;//int j;ULL x;
	for(i=2;i<=1000000;i++){
		dp[i]=int_mod(dp[i-1]*i);
	}
	mod_inv();
}
int int_mod(ULL a){
	return (a+MOD)%MOD;
}
int main() {
	precomp();
	int n,r,ans;int ttt,x;//ULL ans;
	while(scanf("%d %d",&n,&r)!=EOF){
		ttt=0;
		if(n==0){
			cout<<0<<endl;
			continue;
		}
		ans=((modInverse[dp[n-r]]*modInverse[dp[r]])%MOD*dp[n])%MOD;
		printf("%d\n",ans);
		x=min(r,n-r);
		if( (n>=1613 && (x>=2)) ||  (n>=200 && (x>=3)) || (n>=77 && (x>=4)) || (n>=46 && (x>=5)) || (n>=34 && (x>=6)) || (n>=29 && (x>=7)) || (n>=26 && (x>=8)) || (n>=24 && (x>=9)) || (n>=23 && (x>=11)))
			ttt=1;
		if(ttt)
		printf("Exceeds\n");
		else
		printf("Does not exceed\n");

	}
	return 0;
}
















#include <bits/stdc++.h>
using namespace std;
#define ULL long long int
#define MOD 1300031
int dp[1000001];
int modInverse[1000001];
void precomp();
int int_mod(ULL a);
void mod_inv();
int intn_mod(long long int a);
int modmul(ULL a,ULL b);
void mod_inv(){
	memset(modInverse,0,sizeof(modInverse));
	modInverse[1]=1;
	int i;
	for(i=2;i<=1000000;i++)
		modInverse[i]=modmul(-(MOD/i),modInverse[MOD%i])+MOD;
}
int intn_mod(long long int a){
	return (a+MOD)%MOD;
}
void precomp(){
	int i;
	dp[1]=dp[0]=1;//int j;ULL x;
	for(i=2;i<=1000000;i++){
		dp[i]=modmul(dp[i-1],i);
	}
	mod_inv();
}
int modmul(ULL a,ULL b){
	if(b==0)
		return 0;
	if(b==1)
		return a;
	return b&1?int_mod(a+modmul(a,b-1)):(modmul(int_mod(2*a),b/2));
}
int int_mod(ULL a){
	return (a+MOD)%MOD;
}
int main() {
	precomp();
	int i,n,r,ans;int ttt,x;//ULL ans;
	/*for(i=2;i<=1000000;i++)
		cout<<modInverse[i]<<endl;
	*/
	while(scanf("%d %d",&n,&r)!=EOF){
		ttt=0;
		if(n==0){
			cout<<0<<endl;
			continue;
		}
		ans=modmul(modmul(modInverse[dp[n-r]],modInverse[dp[r]]),dp[n]);
		printf("%d\n",ans);
		x=min(r,n-r);
		if( (n>=1613 && (x>=2)) ||  (n>=200 && (x>=3)) || (n>=77 && (x>=4)) || (n>=46 && (x>=5)) || (n>=34 && (x>=6)) || (n>=29 && (x>=7)) || (n>=26 && (x>=8)) || (n>=24 && (x>=9)) || (n>=23 && (x>=11)))
			ttt=1;
		if(ttt)
		printf("Exceeds\n");
		else
		printf("Does not exceed\n");

	}
	return 0;
}






#include <bits/stdc++.h>
using namespace std;
#define ULL long long int
#define MOD 1300031
int dp[1000001];
int modInverse[1000001];
void precomp();
//int int_mod(ULL a);
void mod_inv();
//int intn_mod(long long int a);
//int modmul(ULL a,ULL b);
void mod_inv(){
	memset(modInverse,0,sizeof(modInverse));
	modInverse[1]=1;
	ULL i;
	for(i=2;i<=1000000;i++)
		modInverse[i]=(-(MOD/i)*modInverse[MOD%i])%MOD+MOD;
}
/*
int intn_mod(long long int a){
	return (a+MOD)%MOD;
}*/
void precomp(){
	ULL i,x;
	dp[1]=dp[0]=1;//int j;ULL x;
	for(i=2;i<=1000000;i++){
		x=dp[i-1];
		dp[i]=(x*i)%MOD;
	}
	mod_inv();
}
/*
int modmul(int a,int b){
	if(b==0)
		return 0;
	int ans=1;
	while( )
	if(b==1)
		return a;
	return b&1?int_mod(a+modmul(a,b-1)):(modmul(int_mod(2*a),b/2));
}
int int_mod(int a){
	return (a+MOD)%MOD;
}*/
int main() {
	precomp();
	int i,n,r,ans;int ttt,x;//ULL ans;
	/*for(i=2;i<=1000000;i++)
		cout<<dp[i]<<endl;
	*/
	ULL xx,y,z,w;
	while(scanf("%d %d",&n,&r)!=EOF){
		ttt=0;
		if(n==0){
			cout<<0<<endl;
			continue;
		}
		xx=modInverse[dp[n-r]];
		y=modInverse[dp[r]];
		z=dp[n];
		w=(xx*y)%MOD;
		ans=(w*z)%MOD;
		printf("%d\n",ans);
		x=min(r,n-r);
		if( (n>=1613 && (x>=2)) ||  (n>=200 && (x>=3)) || (n>=77 && (x>=4)) || (n>=46 && (x>=5)) || (n>=34 && (x>=6)) || (n>=29 && (x>=7)) || (n>=26 && (x>=8)) || (n>=24 && (x>=9)) || (n>=23 && (x>=11)))
			ttt=1;
		if(ttt)
		printf("Exceeds\n");
		else
		printf("Does not exceed\n");

	}
	return 0;
}
