#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <climits>
#include <cfloat>
#include <cassert>
using namespace std;
long long int segment_tree(int i,int j,int si);
long long int segment_Q(int i,int j,int qi,int qj,int si);
void update_q0(int i,int j,int qi,int x,int si);
void update_q1(int i,int j,int qi,int x,int si);
long long int arr[1000005];
long long int seg[4000020];
int main(){
    int t,i,o,qi,qj,j,x;
    long long int n,q;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        printf("Case %d:\n",i);
        scanf("%lld %lld",&n,&q);
        for(j=0;j<n;j++)
            scanf("%lld",&arr[j]);
        segment_tree(0,n-1,0);
        while(q--){
            scanf("%d",&o);
            if(o==2){
                scanf("%d %d",&qi,&qj);
                printf("%lld\n",segment_Q(0,n-1,qi-1,qj-1,0));
            }
            if(o==1){
                scanf("%d %d %d",&qi,&qj,&x);
                //printf("%d",segment_Q(0,3,0,3,0));

                for(j=qi;j<=qj;j++)
                    update_q1(0,n-1,j-1,x,0);
            	for(j=qi;j<=qj;j++){
                	arr[j-1]+=x;
                }
            }
            if(o==0){
                scanf("%d %d %d",&qi,&qj,&x);
                for(j=qi;j<=qj;j++)
                    update_q0(0,n-1,j-1,x,0);
            	for(j=qi;j<=qj;j++){
                	arr[j-1]=x;
                }
            	//printf("%d ",segment_Q(0,n-1,0,0,0));
            }
        }
    	//printf("%d ",segment_Q(0,n-1,3,3,0));
    }
    return 0;
}
long long int segment_tree(int i,int j,int si){
    int mid;
    mid=(i+j)/2;
    if(i==j){
        seg[si]=(arr[i]*arr[i]);
        return seg[si];
    }
    seg[si]=(segment_tree(i,mid,2*si+1)+segment_tree(mid+1,j,2*si+2));
    return seg[si];
}
long long int segment_Q(int i,int j,int qi,int qj,int si){
    int mid;
    long long int d;
    if(qi<=i && qj>=j)
        return seg[si];
    if(j<qi || i>qj)
        return 0;
    mid=(i+j)/2;
    d=(segment_Q(i,mid,qi,qj,2*si+1)+segment_Q(mid+1,j,qi,qj,2*si+2));
    return d;
}
void update_q0(int i,int j,int qi,int x,int si){
    int mid;
    mid=(i+j)/2;
    if(qi<i || qi>j){
        return ;
    }
    if(qi>=i && qi<=j){
        seg[si]=(seg[si]-(arr[qi]*arr[qi])+x*x);
    }


    if(i!=j){
    	update_q0(i,mid,qi,x,2*si+1);
		update_q0(mid+1,j,qi,x,2*si+2);

    }
    return ;
}
void update_q1(int i,int j,int qi,int x,int si){
    int mid,k;
    if(qi<i || qi>j){
        return ;
    }
    if(i<=qi && qi<=j){
        seg[si]=(seg[si]-(arr[qi]*arr[qi])+((arr[qi]+1)*(arr[qi]+1)));
    }
    mid=(i+j)/2;
    if(i!=j){
        update_q1(i,mid,qi,x,2*si+1);
        update_q1(mid+1,j,qi,x,2*si+2);
    }
    return ;
}
