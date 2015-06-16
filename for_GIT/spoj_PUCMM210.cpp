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
#define MOD 1000000003
#define ULL unsigned long long int
void mac();
ULL arr[1000009];
int main()
{
    mac();
    ULL t,n;
    scanf("%llu",&t);
    while(t--){
        ULL sum=0,i;
        scanf("%llu",&n);
        printf("%llu\n",arr[n]);
    }

    return 0;
}
void mac(){
    ULL n,i,k;
    arr[0]=0;
    arr[1]=1;
    for(i=2;i<=1000000;i++){
        k=((i*(i+1))/2)%MOD;
        arr[i]=(arr[i-1]+(k*k)%MOD)%MOD;
    }
}
