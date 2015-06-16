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
#define ULL long long int
ULL area(ULL i,ULL j);
ULL arr[100005];
ULL seg[300015];
ULL RMQ(ULL i,ULL j,ULL qi,ULL qj,ULL index);
ULL minval(ULL ii,ULL jj);
ULL segment_tree(ULL i,ULL j,ULL si);
ULL n;
int main()
{
    ULL x,d,y,i;
    while(1){
        scanf("%lld",&n);
        if(n==0)
            break;
        for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);
        segment_tree(0,n-1,0);
        d=area(0,n-1);
        printf("%lld\n",d);
    }
    return 0;
}
ULL area(ULL i,ULL j){
    ULL t,t1,t2,t3,m;
    ULL k;
    if(i>j)
    	return 0;
    if(i==j)
        return arr[i];
    m=RMQ(0,n-1,i,j,0);
    t1=area(i,m-1);
    t2=area(m+1,j);
	t3=arr[m]*(j-i+1);
    t=max(max(t1,t2),t3);
    return t;
}
ULL RMQ(ULL i,ULL j,ULL qi,ULL qj,ULL index){
    ULL mid,d;
    mid=(i+j)/2;
    if(qi<=i && qj>=j)
        return seg[index];
    if(j<qi||i>qj)
    	return -1;
    d=minval(RMQ(i,mid,qi,qj,2*index+1),RMQ(mid+1,j,qi,qj,2*index+2));
    return d;
}
ULL minval(ULL ii,ULL jj){
    if(ii==-1)   return jj;
    if(jj==-1)   return ii;
    return (arr[ii]<arr[jj])?ii:jj;
}
ULL segment_tree(ULL i,ULL j,ULL si){
    ULL mid;
    if(i==j){
        seg[si]=i;
        return i;
    }
    mid=(i+j)/2;
    seg[si]=minval(segment_tree(i,mid,2*si+1),segment_tree(mid+1,j,2*si+2));
    return seg[si];
}
