#include<bits/stdc++.h>
using namespace std;
long long int MOD=1000000007;
long long int B=137;
long long int int_mod(long long int a);
long long int power_expo(long long int a,long long int b);
long long int int_mod(long long int a){
	return (a%MOD+MOD)%MOD;
}
long long int power_expo(long long int a,long long int b){
	long long int t;
	if(b==0)
		return 1;
	if(b==1)
		return a;
	t=power_expo(a,b/2);
	return b%2==0?int_mod(t*t):int_mod(int_mod(t*t)*a);
}
int main() {
	long long int i,d,h1,h2,j,did;
	long long int x,D;
	long long int k=0;
	did=power_expo(B,MOD-2);
	while(1){
		char s[100005];
		char revers[100005];
		if(scanf("%s",s)==EOF)
			break;
		x=strlen(s);
		//printf("%d\n",x);
		D=power_expo(B,x-1);
		k=0;
		for(i=x-1;i>=0;i--)
			revers[k++]=s[i];
		revers[k]='\0';
		h1=0;
		for(i=0;i<x;i++)
			h1=int_mod(int_mod(h1*B)+(s[i]-'0'));
		h2=0;
		for(i=0;i<x;i++)
			h2=int_mod(int_mod(h2*B)+(revers[i]-'0'));
		i=0;j=x-1;
		while(1){
			if(h1==h2)
				break;
			h1=int_mod(h1-int_mod(D*(s[i]-'0')));
			D=int_mod(D*did);
			h2=int_mod(h2-int_mod((revers[j]-'0')));
			h2=int_mod(h2*did);
			i++;j--;
		}
		printf("%s",s);
		for(j=i-1;j>=0;j--)
			printf("%c",s[j]);
		printf("\n");
	}
	return 0;
}
