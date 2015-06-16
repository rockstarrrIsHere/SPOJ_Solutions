#include<iostream>
#include<stdio.h>
#include<map>
#include<vector>
using namespace std;
map<long long int,long long int> m;
map<long long int,long long int>::iterator itr;
int t;
//long long int arr[1000000];
long long int n,x,y,i,mm;
int main() {
	scanf("%d",&t);
	while(t--){
		m.clear();
		scanf("%lld",&n);
		x=n/2+1;
		while(n--){
			scanf("%lld",&y);
			if(!m.empty() && m.find(y)!=m.end())
				m[y]++;
			else
				m.insert(pair<long long int,long long int>(y,1));
		}
		for(itr=m.begin();itr!=m.end();itr++){
			if(itr->second>=x){
				printf("YES %lld\n",itr->first);
				break;
			}
		}
		if(itr==m.end())
			printf("NO\n");
	}
	return 0;
}
