#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ULL unsigned long long int
int main() {
	// your code goes here
	int t;ULL x,ans,n;
	scanf("%d",&t);
	while(t--){
		scanf("%llu",&n);
		if(n==0){
            printf("0 1\n");continue;
		}
		ULL t;
		t=n;ans=1;
		while(t){
            ans*=((t&1)+1);
            t>>=1;
		}
		printf("%llu %llu\n",n+1-ans,ans);
	}
	return 0;
}
