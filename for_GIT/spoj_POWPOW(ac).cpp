#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define N 500000003
#define ULL unsigned long long int
int dp[100005];
ULL int_mod(ULL a,ULL b){
	return (a+b)%b;
}
ULL power_expo(ULL a,ULL b){
	ULL t;
	if(b==0)
		return 1;
	if(b==1)
		return a;
	t=power_expo(a,b/2);
	return b%2==0?int_mod(t*t,N):int_mod(int_mod(t*t,N)*a,N);
}
ULL power_expoo(ULL a,ULL b){
	ULL t;
	if(b==0)
		return 1;
	if(b==1)
		return int_mod(a,2*N);
	t=power_expoo(a,b/2);
	return b%2==0?int_mod(t*t,2*N):int_mod(int_mod(t*t,2*N)*a,2*N);
}
ULL power_expooo(ULL a,ULL b){
	ULL t;
	if(b==0)
		return 1;
	if(b==1)
		return a;
	t=power_expoo(a,b/2);
	return b%2==0?int_mod(t*t,MOD):int_mod(int_mod(t*t,MOD)*a,MOD);
}
int main() {
	ULL n,i,j,x,r;
	ULL a,b;
	dp[0]=1;
	for(i=1;i<=100000;i++)
		dp[i]=int_mod(dp[i-1]*power_expo(i,N-2),N);
	int t;
	cin>>t;
	while(t--){
		cin>>a>>b>>n;
		if(n==0){
			x=a;
		}
		else{
			x=1;
			for(i=2;i<=2*n-1;i++)
				x=int_mod(x*int_mod(i,N),N);
			r=int_mod(x*int_mod(dp[n]*dp[n-1],N),N);
			x=int_mod(2*r,2*N);
			x=power_expoo(x,b);
			//cout<<x<<endl;
			x=power_expooo(a,x);
		}
		cout<<x<<endl;
	}
	return 0;
}







/*/*  acc */

#include <cstdio>

using namespace std;

#define MOD 1000000007
#define MOD2 1000000006

int pow(long long a, int b, int c){
    long long ret = 1;

    while(b){
        if(b & 1) ret = (ret * a )% c;
        a =( a * a )% c;
        b >>= 1;
    }

    return ret;
}

long long fact[200001];

int main(){
    int p = 2,q = 500000003;
    int invp = 250000002;

    fact[0] = 1;

    for(int i = 1;i <= 200000;++i)
        fact[i] = (fact[i - 1] * i) % q;

    int T,a,b,n;

    scanf("%d",&T);

    while(T--){
        scanf("%d %d %d",&a,&b,&n);

        long long remq = (fact[2 * n] * pow((fact[n] * fact[n] )% q,q - 2,q) )% q;
        long long x = (remq * p * invp )% MOD2;
        x = pow(x,b,MOD2);
        x = pow(a,x,MOD);

        printf("%lld\n",x);
    }

    return 0;
}
