#include <bits/stdc++.h>
using namespace std;
#define IIN -1000000007
#define LL long long int
struct node mergenode(struct node a,struct node b);
struct node{
    LL prefix;
    LL suffix;
    LL sum;
    LL maxsum;
};
struct node construct_segtree(int i,int j,int index);
void replace(int i,int j,int ii,int nnew,int index);
struct node sum_query(int i,int j,int qi,int qj,int index);
long long int maxx(long long int a,long long int b,long long int c);
struct node seg[150015];
struct node getit();
int check(struct node p);
int arr[50005];
int main() {
	int n,m,x,xx,xxx,i,y,z;
	long long int ans;
	int t=1;
	struct node p;
	//while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		construct_segtree(0,n-1,0);
		//cout<<seg[0].maxsum<<' '<<seg[1].maxsum<<' '<<seg[2].maxsum<<' '<<seg[3].maxsum<<' '<<seg[4].maxsum<<' '<<seg[5].maxsum<<' '<<seg[6].maxsum<<endl;
		//cout<<sum_query(0,n-1,0,2,0).maxsum;
		scanf("%d",&m);
		while(m--){
			scanf("%d %d %d",&x,&y,&z);
			if(!x){
				--y;
				replace(0,n-1,y,z,0);
				//cout<<sum_query(0,n-1,x,x,0)<<endl;
			}
			else{
				p=sum_query(0,n-1,y-1,z-1,0);
				printf("%lld\n",p.maxsum);
			}
		}
	//}
	return 0;
}
struct node mergenode(struct node a,struct node b){
    struct node nnew;
    nnew.sum=a.sum+b.sum;
    nnew.prefix=max(a.prefix,a.sum+b.prefix);
    nnew.suffix=max(b.suffix,a.suffix+b.sum);
    nnew.maxsum=max(max(a.maxsum,b.maxsum),a.suffix+b.prefix);
    return nnew;
}
struct node construct_segtree(int i,int j,int index){
	if(i==j){
		seg[index].sum=seg[index].suffix=seg[index].prefix=seg[index].maxsum=arr[i];
		return seg[index];
	}
	int mid=(i+j)/2;
	return seg[index]=mergenode(construct_segtree(i,mid,2*index+1),construct_segtree(mid+1,j,2*index+2));
}
void replace(int i,int j,int ii,int nnew,int index){
	if(ii>j || ii<i || i>j)
		return ;
	if(j==ii && i==ii){
		seg[index].sum=seg[index].maxsum=seg[index].prefix=seg[index].suffix=nnew;
		return ;
	}
	int mid=(i+j)/2;
	replace(i,mid,ii,nnew,2*index+1);
	replace(mid+1,j,ii,nnew,2*index+2);
	seg[index]=mergenode(seg[2*index+1],seg[2*index+2]);
    return ;
}
struct node getit(){
	struct node p;
	p.maxsum=p.sum=p.prefix=p.suffix=IIN;
	return p;
}
int check(struct node p){
	if(p.maxsum==IIN && p.sum==IIN && p.prefix==IIN && p.suffix==IIN)
		return 1;
	return 0;
}
struct node sum_query(int i,int j,int qi,int qj,int index){
	if(j<qi || i>qj)
		return getit();
	if(i>=qi && j<=qj)
		return seg[index];
	int mid=(i+j)/2;
	struct node p,q;
	p=sum_query(i,mid,qi,qj,2*index+1);
	q=sum_query(mid+1,j,qi,qj,2*index+2);
	if(!check(p) && !check(q))
		return mergenode(p,q);
	else if(!check(p))
		return p;
	else
		return q;
}
long long int maxx(long long int a,long long int b,long long int c){
	if(a<=b){
		return b<=c?c:b;
	}
	return c>=a?c:a;
}















#include <iostream>
using namespace std;
void construct_segtree(int i,int j,int index);
struct node{
	long long int pre,suff,all,all_max;
} seg[30015];
int arr[10005];
void construct_segtree(int i,int j,int index){
	if(i==j){
		seg[index].pre=seg[index].suff=seg[index].all=seg[index].all_max=arr[i];
		return ;
	}
	int mid=(i+j)>>1;
	construct_segtree(i,mid,2*index+1);construct_segtree(mid+1,j,2*index+2);
	seg[index].all=seg[2*index+1].all+seg[2*index+2].all;
	seg[index].pre=max(seg[2*index+1].all+seg[2*index+2].pre,seg[2*index+1].pre);
	seg[index].suff=max(seg[2*index+1].suff+seg[2*index+2].all,seg[2*index+2].suff);
	seg[index].all_max=max(max(seg[index].all,seg[2*index+1].suff+seg[2*index+2].pre),max(seg[2*index+1].all_max,seg[2*index+2].all_max));
}
int check(){

}
struct node getit(){
	struct node a;
	a.suff=a.pre=a.all=a.all_max=-1000000007;
	return a;
}
struct node sum_query(int i,int j,int qi,int qj,int index){
	if(qi<=i && j<=qj)
		return seg[index];
	int mid=(i+j)>>1;
	if(mid<qi)
		return sum_query();
}
int main() {
	// your code goes here

	return 0;
}
