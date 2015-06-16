#include <bits/stdc++.h>
using namespace std;
int seg[150015];
int arr[30005];
int construct_segtree(int i,int j,int index);
void replace(int i,int j,int ii,int old,int new,int index);
int sum_query(int i,int j,int qi,int qj,int index);
int main() {
	// your code goes here
	int n,m,x,xx,xxx;
	long long int ans;
	int t=10;
	while(t--){
		scanf("%d",&n);
		char s[30002];
		scanf("%s",s);
		for(i=0;i<n;i++){
			if(s[i]=='(')
				arr[i]=1;
			else
				arr[i]=-1;
		}
		scanf("%d",&m);
		while(m--){
			scanf("%d",&x);
			if(!x){
				--x;
				xx=sum_query(0,n-1,x,x,0);
				if(xx==1)
					xxx=-1;
				if(xx==-1)
					xxx=1;
				replace(0,n-1,xx,xxx,0);
			}
			else{
				ans=sum_query(0,n-1,0,n-1,0);
				if(!ans)
				printf("YES\n");
				else
				printf("NO\n");
			}
		}
	}
	return 0;
}
int construct_segtree(int i,int j,int index){
	if(i==j)
		return seg[index]=arr[i];
	int mid=(i+j)/2;
	return seg[index]=construct_segtree(i,mid,2*index+1)+construct_segtree(mid+1,j,2*index+2);
}
void replace(int i,int j,int ii,int old,int new,int index){
	if(ii>j || ii<i)
		return;
	if(ii<=j && i>=ii)
		seg[index]=seg[index]-old+new;
	int mid=(i+j)/2;
	replace(i,mid,ii,old,new,2*index+1);
	replace(mid+1,j,ii,old,new,2*index+2);
}
int sum_query(int i,int j,int qi,int qj,int index){
	if(i>qj || j<qi)
		return 0;
	if(i>=qi && j<=qj)
		return seg[index];
	int d;int mid=(i+j)/2;
	d=sum_query(i,mid,qi,qj,2*index+1)+sum_query(mid+1,j,2*index+2);
	return d;
}
