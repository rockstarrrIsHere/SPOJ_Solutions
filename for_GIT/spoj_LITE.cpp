#include<bits/stdc++.h>
using namespace std;
#define ULL unsigned long long int
int arr[100005];
//ULL seg[400020];
ULL lazy[400020];
ULL sum_query(int i,int j,int qi,int qj,int index);
void update(int i,int j,int qi,int qj,int index);
ULL construct_segtree(int i,int j,int index);
struct node{
	ULL tot;
	int len;
};
struct node seg[400020];
void update(int i,int j,int qi,int qj,int index){
	if(lazy[index]){
		seg[index].tot=seg[index].len-seg[index].tot;
		if(i!=j){
			lazy[2*index+1]=!lazy[2*index+1];
			lazy[2*index+2]=!lazy[2*index+2];
		}
		lazy[index]=0;
	}
	if(i>qj || j<qi || i>j)
		return ;
	if(qi<=i && j<=qj){
		seg[index].tot=seg[index].len-seg[index].tot;
		if(i!=j){
			lazy[2*index+1]=!lazy[2*index+1];
			lazy[2*index+2]=!lazy[2*index+2];
		}
		return ;
	}
	int mid=(i+j)>>1;
	update(i,mid,qi,qj,2*index+1);
	update(mid+1,j,qi,qj,2*index+2);
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
		seg[index].tot=seg[index].len-seg[index].tot;
		if(i!=j){
			lazy[2*index+1]=!lazy[2*index+1];
			lazy[2*index+2]=!lazy[2*index+2];
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
	int t=1;
	//cin>>t;
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		//cin>>n>>m;
		memset(lazy,0,sizeof(lazy));
		memset(arr,0,sizeof(arr));
		//memset(seg,0,sizeof(seg));
		construct_segtree(0,n-1,0);
		int a,p,q;
		//ULL v;
		while(m--){
			scanf("%d",&a);
			//cin>>a;
			scanf("%d%d",&p,&q);
			if(a){
				//cin>>p>>q;
				--p;--q;
				printf("%llu\n",sum_query(0,n-1,p,q,0));
				//cout<<sum_query(0,n-1,p,q,0)<<'\n';
			}
			else{
				//cin>>p>>q;
				--p;--q;
				update(0,n-1,p,q,0);
			}
		}
	}

	return 0;
}
