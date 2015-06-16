#include<iostream>
#include<string>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<algorithm>
#include<stack>
#include<vector>
#include<list>
#include<string.h>
#define ULL unsigned long long int
using namespace std;
int main()
{
    ULL arr[35];
    queue<ULL> q;
    ULL n,l,k,t,i,sum=0,m,h;
    scanf("%lld",&t);
    while(t--){
        sum=0;
        scanf("%lld %lld %lld",&n,&l,&k);
        for(i=0;i<n;i++){
            q.push(i);
            sum+=i;
        }
        m=pow(10,k);
        if(l>=n-1){
            for(i=n;i<=l;i++){
                h=q.front();
                q.pop();
                q.push(sum);
                sum=2*sum-h;
            }
            l=q.back();
            while(!q.empty()){
                q.pop();
            }
            printf("%llu\n",l%m);
        }
        else{
            printf("%llu\n",l%m);
        }
    }
    return 0;
}

