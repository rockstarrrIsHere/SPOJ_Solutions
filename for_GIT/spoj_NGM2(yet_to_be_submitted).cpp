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
#include<map>
#include<bitset>
#include<string.h>
using namespace std;
#define MOD 1000000007
#define ULL long long int
ULL gcd(ULL a,ULL b){return b==0?a:gcd(b,a%b);}
ULL lcm(ULL a,ULL b){return (a*(b/gcd(a,b)));}
ULL arr[16];
int main()
{
    ULL n,k,ele,prolcm,i,j,m,d;
    scanf("%lld %lld",&n,&k);
    for(i=0;i<k;i++)
        scanf("%lld",&arr[i]);
    m=1<<k;d=n;
    for(i=1;i<m;i++){
        ele=0;prolcm=1;
        for(j=0;j<k;j++){
            if(i&(1<<j)){
               ele++;
               prolcm=lcm(prolcm,arr[j]);
               if(prolcm>d)
                    break;
            }
        }
        if(ele&1) n-=d/prolcm;
        else    n+=d/prolcm;
    }
    printf("%lld\n",n);
    return 0;
}

