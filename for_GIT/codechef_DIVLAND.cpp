#include <bits/stdc++.h>
using namespace std;
#define LL long long int
priority_queue<pair<long long int,int > , vector< pair<long long int,int> > , greater< pair<long long int,int> > > pq;
LL cost[1000005];
vector<pair<int,LL> > v[1000005];
int n,m;
bool arr[1000005];
int main() {
	int i;
	scanf("%d %d",&n,&m);
	int a,b;LL c;
	memset(cost,0,sizeof(cost));
	memset(arr,0,sizeof(arr));
	while(m--){
		scanf("%d %d %lld",&a,&b,&c);
		cost[a]+=c;
		cost[b]+=c;
		//pq.push(make_pair(c,make_pair(a,b)));
	}
	for(i=0;i<n;i++)
		pq.push(make_pair(cost[i],i));
	int x=n/2;
	while(x>0 && !pq.empty()){
		if(!arr[pq.top().second]){
			printf("%d ",pq.top().second);
			arr[pq.top().second]=true;
			x--;
		}
		pq.pop();
	}
	printf("\n");
	return 0;
}












#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define pc(x) putchar_unlocked(x);
#define LL long long int
priority_queue<pair<long long int,int > , vector< pair<long long int,int> > , greater< pair<long long int,int> > > pq;
LL cost[1000005];
vector<pair<int,LL> > v[1000005];
void scanint(int &x);
inline void writeInt(int n);
void scanLL(LL &x);
int n,m;
bool arr[1000005];
void scanint(int &x){
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
inline void writeInt (int n){
    int N = n, rev, count = 0;
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
	memset(arr,0,sizeof(arr));
	while(m--){
		scanint(a);scanint(b);scanll(c);
		//scanf("%d %d %lld",&a,&b,&c);
		cost[a]+=c;
		cost[b]+=c;
		//pq.push(make_pair(c,make_pair(a,b)));
	}
	for(i=0;i<n;i++)
		pq.push(make_pair(cost[i],i));
	int x=n/2;
	while(x>0 && !pq.empty()){
		if(!arr[pq.top().second]){
			writeInt(pq.top().second);printf(" ");//;writeInt(' ');
			//printf("%d ",pq.top().second);
			arr[pq.top().second]=true;
			x--;
		}
		pq.pop();
	}
	printf("\n");
	return 0;
}
