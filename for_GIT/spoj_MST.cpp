#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define pc(x) putchar_unlocked(x);
#define LL long long int
priority_queue<pair<long long int,pair<int,int> > , vector< pair<long long int,pair<int,int> > > , greater< pair<long long int,pair<int,int> > > > pq;
LL cost[10005];
vector<pair<int,LL> > v[100005];
void scanint(int &x);
inline void writell (LL n);
void scanLL(LL &x);
int n,m;
int xx(int a);
int brr[10005];
bool arr[10005];
void scanint(int &x){
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
inline void writell (LL n){
    LL N = n, rev, count = 0;
    rev = N;
    if (N == 0) { pc('0'); pc('\n'); return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
    while (count--) pc('0');
}
void scanll(LL &x){
    register LL c = gc();
    x = 0;
    LL neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
int main() {
	int i;
	//scanf("%d %d",&n,&m);
	scanint(n);scanint(m);
	int a,b;LL c;
	//memset(cost,0,sizeof(cost));
	//memset(arr,false,sizeof(arr));
	for(i=0;i<n;i++)
		brr[i]=i;
	while(m--){
		scanint(a);scanint(b);scanll(c);
		//scanf("%d %d %lld",&a,&b,&c);
		--a;--b;
		//cost[a]+=c;
		//cost[b]+=c;
		pq.push(make_pair(c,make_pair(a,b)));
	}
	//for(i=0;i<n;i++)
		//pq.push(make_pair(cost[i],i));
	int x=1;LL sum=0;
	//set<int> s;
	while(x<=n-1 && !pq.empty()){
		a=xx(pq.top().second.first);
		b=xx(pq.top().second.second);
		//cout<<pq.top().second.first<<' '<<a<<endl;
		//cout<<pq.top().second.second<<' '<<b<<endl;
		if(a!=b){//!arr[pq.top().second.first] || !arr[pq.top().second.second]){// || s.find(pq.top().second.first)==s.end() || s.find(pq.top().second.second)==s.end()){
			//writeInt(pq.top().second);printf(" ");//;writeInt(' ');
			//printf("%d ",pq.top().second);
			//arr[pq.top().second.second]=true;
			//arr[pq.top().second.first]=true;
			//s.insert(pq.top().second.second);
			//s.insert(pq.top().second.first);
			brr[b]=a;
			sum+=pq.top().first;
			//if(!arr[pq.top().second.first] && !arr[pq.top().second.second])
			//	x-=2;
			//else
				x++;

			//printf("%lld %d %d\n",pq.top().first,pq.top().second.first,pq.top().second.second);
		}
		//printf("%lld %d %d\n",pq.top().first,pq.top().second.first,pq.top().second.second);
		pq.pop();
	}
	writell(sum);
	printf("\n");
	return 0;
}
int xx(int a){
	if(brr[a]==a)
		return a;
	return brr[a]=xx(brr[a]);
}
