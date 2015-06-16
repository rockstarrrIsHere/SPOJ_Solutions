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
#include<string.h>
#define ULL unsigned long long int
using namespace std;
bool comp(const pair<ULL,ULL>& l,const pair<ULL,ULL>& r);
bool comp(const pair<ULL,ULL>& l,const pair<ULL,ULL>& r){
	return l.first>r.first;
}
int main()
{
	vector<pair<ULL,ULL> > v;
	ULL d,i,j,n,t,x,x1,x2;
	scanf("%llu",&t);
	while(t--){
		i=1;
		scanf("%llu",&n);
		for(i=1;i<=n;i++){
			scanf("%llu",&x);
			v.push_back(make_pair(x,i));
		}
		sort(v.begin(),v.end(),comp);
		/*for(i=0;i<n;i++)
			cout<<v[i].first<<endl;*/
		d=0;
		for(i=0;i<n-1;i++){
			x2=v[i].second;
			for(j=i+1;j<n;j++){
				if(v[j].second>x2)
					d++;
			}
		}
		printf("%llu\n",d);
		v.resize(0);
	}
    return 0;
}

