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
#include<bitset>
#include<string.h>
using namespace std;
#define MOD 1000000007
#define ULL long long int
ULL arr[1000005];
int main()
{
    ULL t,i,j;
    scanf("%llu",&t);
    for(i=1;i<=t;i++){
        ULL n,ans=0;
        scanf("%llu",&n);
        for(j=1;j<=n;j++)
            scanf("%llu",&arr[j]);
        ULL sum=0;
        for(j=1;j<=n;j++){
            sum+=arr[j];
           // printf("%llu\n",sum);
            if(sum<=0){
                ans+=-1*(sum)+1;
                sum=1;
            }
        }
        if(ans==0)
            ans=1;
        printf("Scenario #%llu: %llu\n",i,ans);
    }
    return 0;
}
