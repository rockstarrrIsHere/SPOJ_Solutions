#include <iostream>
using namespace std;
#define IIN -1000000007
void construct_segtree(int i,int j,int index);
struct node{
	long long int pre,suff,all,all_max;
} seg[40020];
int arr[10005];
void construct_segtree(int i,int j,int index);
int check(struct node a);
struct node getit();
struct node sum_query(int i,int j,int qi,int qj,int index);
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
int check(struct node a){
	if(a.pre==IIN && a.suff==IIN && a.all==IIN && a.all_max==IIN)
		return 1;
	return 0;
}
struct node getit(){
	struct node a;
	a.suff=a.pre=a.all=a.all_max=-1000000007;
	return a;
}
struct node sum_query(int i,int j,int qi,int qj,int index){
	if(qi>j || i>qj)
		return getit();
	if(qi<=i && j<=qj)
		return seg[index];
	int mid=(i+j)>>1;
	struct node a,b,d;
	a=sum_query(i,mid,qi,qj,2*index+1);
	b=sum_query(mid+1,j,qi,qj,2*index+2);
	int aa,bb;
	aa=check(a);bb=check(b);
	if(aa==1 && bb==1)
		return getit();
	if(aa)
		return b;
	if(bb)
		return a;
	d.pre=max(a.pre,a.all+b.pre);
	d.suff=max(b.suff,a.suff+b.all);
	d.all=a.all+b.all;
	d.all_max=max(max(a.suff+b.pre,d.all),max(a.all_max,b.all_max));
	return d;
}
int main() {
	// your code goes here
	int t,i,j;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n;
		for(i=0;i<n;i++)
			cin>>arr[i];
		cin>>m;
		struct node d,e,f;
		//long long int sum=IIN;
		construct_segtree(0,n-1,0);
		while(m--){
			//sum=IIN;
			int x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			x1--;x2--;y1--;y2--;
			if(y1<x2){
				d=sum_query(0,n-1,y1+1,x2-1,0);//.all;
				e=sum_query(0,n-1,x1,y1,0);//.suff;
				f=sum_query(0,n-1,x2,y2,0);//.pre;
				if(check(d)==1 || check(e)==1 || check(f)==1){
					if(check(d)==1){
						if(check(e)==1){
							cout<<f.pre<<'\n';
							continue;
						}
						if(check(f)==1){
							cout<<e.suff<<'\n';
							continue;
						}
						cout<<f.pre+e.suff<<'\n';
						continue;
					}
					if(check(e)==1){
						if(check(d)==1){
							cout<<f.pre<<'\n';
							continue;
						}
						if(check(f)==1){
							cout<<d.all<<'\n';
							continue;
						}
						cout<<f.pre+d.all<<'\n';
						continue;
					}
					if(check(f)==1){
						if(check(d)==1){
							cout<<e.suff<<'\n';
							continue;
						}
						if(check(d)==1){
							cout<<d.all<<'\n';
							continue;
						}
						cout<<e.suff+d.all<<'\n';
						continue;
					}
				}
				else
					cout<<d.all+e.suff+f.pre<<'\n';
			}
			else{
				cout<<max(sum_query(0,n-1,x2,y1,0).all_max,max(sum_query(0,n-1,x1,y1,0).suff+sum_query(0,n-1,y1+1,y2,0).pre,sum_query(0,n-1,x1,x2-1,0).suff+sum_query(0,n-1,x2,y2,0).pre))<<'\n';
				//cout<<1111111111<<'\n';
			}
		}
	}
	return 0;
}
