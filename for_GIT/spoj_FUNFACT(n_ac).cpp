#include<iostream>
#include<string>
#include<stdio.h>
#include<bitset>
#include<cstring>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<algorithm>
#include<stack>
#include<vector>
#include<list>
#include<string.h>
#include<math.h>
using namespace std;
#define MOD 1000000007
#define ULL unsigned long long int
//bitset<100000005> arr;
//int brr[1000005];
ULL search_for_index(ULL i,ULL x,ULL j);
ULL arr[15000001];
int main()
{
    ULL n,i,digi,t,j,d,x;
    long double ans=0;
    arr[0]=1;arr[1]=1;
    for(j=2;j<=15000000;j++){
        ans+=log10l(j);
        digi=ceil(ans);
        arr[j]=digi;
    }
    scanf("%llu",&t);
    while(t--){
        scanf("%llu",&n);
        if(n<=3){
            if(n==1)
              d=3;
            if(n==2) d=4;
            if(n==3) d=6;
        }
        else
            d=search_for_index(0,n,15000000);
    	printf("%llu\n",d);
    }
	return 0;
}
ULL search_for_index(ULL i,ULL x,ULL j){
    ULL mid,t,m;
    mid=(i+j)/2;
    if(i==j)
         return mid-1;
    else{
    if(arr[mid]<=x)
       t=search_for_index(mid+1,x,j);
    else
       t=search_for_index(i,x,mid);
    }
    return t;
}


