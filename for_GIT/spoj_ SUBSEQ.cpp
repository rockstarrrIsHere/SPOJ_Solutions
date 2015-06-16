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
ULL arr[1000005];
ULL seg[3000015];
ULL segment_tree(ULL i,ULL j,ULL si);
ULL SUM_Q(ULL i,ULL j,ULL qi,ULL qj,ULL index);
int main()
{
    ULL t,n,count=0,i,j;
    scanf("%lld",&t);
    while(t--){
        count=0;
        scanf("%lld",&n);
        for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);
        segment_tree(0,n-1,0);
        for(i=0;i<n;i++){
            for(j=i;j<n;j++){
                if(47==SUM_Q(i,j,0,n-1,0))
                    count++;
            }
        }
        printf("%lld\n",count);
    }

    return 0;
}
ULL segment_tree(ULL i,ULL j,ULL si){
    ULL mid;
    mid=(i+j)/2;
    if(i==j){
        seg[si]=arr[i];
        return arr[i];
    }
    seg[si]=(segment_tree(i,mid,2*si+1)+segment_tree(mid+1,j,2*si+2));
    return seg[si];
}
ULL SUM_Q(ULL i,ULL j,ULL qi,ULL qj,ULL index){
    ULL mid,d;
    if(qi<=i && j<=qj)
        return seg[index];
    if(j<qi || i>qj)
        return 0;
    mid=(i+j)/2;
    d=(SUM_Q(i,mid,qi,qj,2*index+1)+SUM_Q(mid+1,j,qi,qj,2*index+2));
    return d;
}
