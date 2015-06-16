#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long int
#define LL long long int
#define B 137
#define MOD 1000000007
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int lcm(int a,int b){return (a*(b/gcd(a,b)));}
int int_mod(int a){return (a+MOD)%MOD;}
int int_modd(int a,int b){return (a+b)%b;}
int power_expo_mod(ULL a,ULL b){
    if(b==0)
        return 1;
    if(b==1)
        return a;
    int t;
    t=power_expo_mod(a,b/2);
    return b%2==0?int_mod(t*t):int_mod(t*t*a);
}
int power_expo(int a,int b){
    if(b==0)
        return 1;
    if(b==1)
        return a;
    int t;
    t=power_expo(a,b/2);
    return b%2==0?t*t:t*t*a;
}
int string_modd(char s[],int a){
    if(a==0)
        return 0;
    int i,d;
    int x;
    x=strlen(s);
    i=0;d=0;
    while(i<x){
        d=int_modd(d*10+(s[i]-'0'),a);
        i++;
    }
    return d;
}
int arr[35][3];
int dp[100];
int main() {
    int n,i,j;
    while(scanf("%d",&n) && n>0){
        vector<pair<pair<int,int>,int> > v;
        for(i=0;i<n;i++){
            for(j=0;j<3;j++)
                scanf("%d",&arr[i][j]);
        }
        memset(dp,0,sizeof(dp));
        int a,b,c;
        for(i=0;i<n;i++){
            for(j=0;j<3;j++){
                a=arr[i][j];
                b=arr[i][(j+1)%3];
                c=arr[i][(j+2)%3];
                if(c>b) swap(b,c);
                v.push_back(make_pair(make_pair(b,c),a));
            }
        }
        int aa,bb;
        int ans=0;
        sort(v.begin(),v.end());
        dp[0]=v[0].second;
        for(i=1;i<3*n;i++){
            a=v[i].first.first;
            b=v[i].first.second;
            for(j=i-1;j>=0;j--){
                aa=v[j].first.first;
                bb=v[j].first.second;
                if(aa<a && bb<b) dp[i]=max(dp[i],dp[j]);
            }
            dp[i]+=v[i].second;
            ans=max(ans,dp[i]);
        }
        printf("%d\n",ans);
    }
	return 0;
}
