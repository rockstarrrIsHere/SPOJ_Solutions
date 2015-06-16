#include<bits/stdc++.h>                                    //  AC solution..
using namespace std;
#define ULL unsigned long long int
int arr[100005];
//ULL seg[400020];
ULL lazy[400020];
ULL sum_query(int i,int j,int qi,int qj,int index);
void update(int i,int j,int qi,int qj,ULL value,int index);
ULL construct_segtree(int i,int j,int index);
struct node{
	ULL tot;
	int len;
};
struct node seg[400020];
void update(int i,int j,int qi,int qj,ULL value,int index){
	if(lazy[index]){
		seg[index].tot+=(seg[index].len)*lazy[index];
		if(i!=j){
			lazy[2*index+1]+=lazy[index];
			lazy[2*index+2]+=lazy[index];
		}
		lazy[index]=0;
	}
	if(i>qj || j<qi || i>j)
		return ;
	if(qi<=i && j<=qj){
		seg[index].tot+=(seg[index].len)*value;
		if(i!=j){
			lazy[2*index+1]+=value;
			lazy[2*index+2]+=value;
		}
		return ;
	}
	int mid=(i+j)>>1;
	update(i,mid,qi,qj,value,2*index+1);
	update(mid+1,j,qi,qj,value,2*index+2);
	seg[index].tot=seg[2*index+1].tot+seg[2*index+2].tot;
}
ULL construct_segtree(int i,int j,int index){
	if(i==j){
		seg[index].len=1;
		seg[index].tot=arr[i];
		return seg[index].tot;
	}
	int mid;
	mid=(i+j)>>1;
	construct_segtree(i,mid,2*index+1);
	construct_segtree(mid+1,j,2*index+2);
	seg[index].len=j-i+1;
	seg[index].tot=seg[2*index+1].tot+seg[2*index+2].tot;
	return seg[index].tot;
}
ULL sum_query(int i,int j,int qi,int qj,int index){
	if(i>qj || j<qi || i>j)
		return 0;
	if(lazy[index]){
		seg[index].tot+=(seg[index].len)*lazy[index];
		if(i!=j){
			lazy[2*index+1]+=lazy[index];
			lazy[2*index+2]+=lazy[index];
		}
		lazy[index]=0;
	}
	if(qi<=i && j<=qj)
		return seg[index].tot;
	int mid=(i+j)>>1;
	return sum_query(i,mid,qi,qj,2*index+1)+sum_query(mid+1,j,qi,qj,2*index+2);
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		memset(lazy,0,sizeof(lazy));
		memset(arr,0,sizeof(arr));
		memset(seg,0,sizeof(seg));
		construct_segtree(0,n-1,0);
		int a,p,q;
		ULL v;
		while(m--){
			cin>>a;
			if(a){
				cin>>p>>q;
				--p;--q;
				cout<<sum_query(0,n-1,p,q,0)<<'\n';
			}
			else{
				cin>>p>>q>>v;
				--p;--q;
				update(0,n-1,p,q,v,0);
			}
		}
	}

	return 0;
}








#include <cstdio>                           //  Using BIT..
#include <cstring>

using namespace std;

long long bit1[100002],bit2[100002];

void update(long long bit[], int idx, long long val){
    for(int x = idx;x <= 100001;x += x & -x)
        bit[x] += val;
}

long long query(long long bit[], int idx){
    long long ret = 0;

    for(int x = idx;x > 0;x -= x & -x)
        ret += bit[x];

    return ret;
}

int main(){
    int T,N,Q;

    scanf("%d",&T);

    while(T--){
        scanf("%d %d",&N,&Q);

        memset(bit1,0,sizeof bit1);
        memset(bit2,0,sizeof bit2);

        for(int i = 0,op,l,r,v;i < Q;++i){
            scanf("%d %d %d",&op,&l,&r);

            if(op == 0){
                scanf("%d",&v);

                update(bit1,l,v); update(bit1,r + 1,-v);
                update(bit2,l,-(long long)v * (l - 1)); update(bit2,r + 1,(long long)v * r);
            }else{
                printf("%lld\n",query(bit1,r) * r + query(bit2,r) - query(bit1,l - 1) * (l - 1) - query(bit2,l - 1));
            }
        }
    }

    return 0;
}
















#include <iostream>                        // NOT AC
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
long long int segment_tree(long long int i,long long int j,long long int si);
long long int segment_Q(long long int i,long long int j,long long int qi,long long int qj,long long int si);
long long int update_q0(long long int i,long long int j,long long int qi,long long int qj,long long int x,long long int si);
long long int arr[100005];
long long int seg[400020];
int main(){
    int t,i,o;
    long long int qi,qj,j,x;
    long long int n,q;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        //printf("Case %d:\n",i);
        scanf("%lld %lld",&n,&q);
        segment_tree(0,n-1,0);
        while(q--){
            scanf("%d",&o);
            if(o==1){
                scanf("%lld %lld",&qi,&qj);
                printf("%llu\n",segment_Q(0,n-1,qi-1,qj-1,0));
            }
            if(o==0){
                scanf("%lld %lld %lld",&qi,&qj,&x);
                update_q0(0,n-1,qi-1,qj-1,x,0);
            	//printf("%d ",segment_Q(0,n-1,7,7,0));
            }
        }

    }
    return 0;
}
long long int segment_tree(long long int i,long long int j,long long int si){
    if(i==j){
        seg[si]=0;
        return seg[si];
    }
    long long int mid;
    mid=(i+j)/2;
    seg[si]=(segment_tree(i,mid,2*si+1)+segment_tree(mid+1,j,2*si+2));
    return seg[si];
}
long long int segment_Q(long long int i,long long int j,long long int qi,long long int qj,long long int si){
    if(qi<=i && qj>=j)
        return seg[si];
    if(j<qi || i>qj)
        return 0;
    long long int mid;
    unsigned long long int d;
    mid=(i+j)/2;
    d=(segment_Q(i,mid,qi,qj,2*si+1)+segment_Q(mid+1,j,qi,qj,2*si+2));
    return d;
}
long long int update_q0(long long int i,long long int j,long long int qi,long long int qj,long long int x,long long int si){
    if(j<qi || i>qj){
        return seg[si];
    }
    if(qi<=i && j<=qj){
        seg[si]=(seg[si]+(j-i+1)*x);
    	if(i==j)
    		return seg[si];
    }
    long long int mid;
    mid=(i+j)/2;
    seg[si]=update_q0(i,mid,qi,qj,x,2*si+1)+update_q0(mid+1,j,qi,qj,x,2*si+2);
	return seg[si];
}





