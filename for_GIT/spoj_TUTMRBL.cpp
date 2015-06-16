#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <utility>
#define EPS 0.0000001
using namespace std;
int primelen;
bitset<10001> arr;
int prime[10000];
void seive();
int main(){
    int n,x,j,i,xx;
    seive();
    while(1){
    	scanf("%d",&n);
    	if(n==0)
    		break;
    	vector<pair<int,int> > v;
    	x=binary_search(prime,prime+primelen,n);
    	if(x==1){
    		printf("%d = %d\n",n,n);
    		printf("With %d marbles, 1 different rectangles can be constructed.\n",n);
    	}
    	else{
    		x=n;
    		for(j=0;prime[j]*prime[j]<=x;j++){
    			if(x%prime[j]==0){
    				int count=0;
    				while(x%prime[j]==0){
    					count++;
    					x/=prime[j];
    				}
    				//printf("%d %d  ",prime[j],count);
    				v.push_back(make_pair(prime[j],count));
    			}
    		}
    		if(x>1){
    			v.push_back(make_pair(x,1));
    		}
    		x=v.size();long long int sum=0,ans=1;
    		//printf("%d\n",x);
    		int flag=0;
    		for(i=0;i<x;i++){
    			ans*=(v[i].second+1);
    			if(v[i].second%2==1)
    				flag=1;
    		}
    		ans/=2;
    		if(flag==0)
    			ans+=1;
    		printf("%d = ",n);
    		printf("%d",v[0].first);
    		v[0].second--;
    		for(i=0;i<x;i++){
    			xx=v[i].second;
    			for(j=1;j<=xx;j++){
    				printf(" * %d",v[i].first);
    			}
    		}
    		printf("\n");
    		printf("With %d marbles, %lld different rectangles can be constructed.\n",n,ans);
    	}
    }

    return 0;
}
void seive(){
	int i,j,k;
	for(i=3;i<=3163;i+=2)
		arr[i]=true;
	arr[0]=arr[1]=false;
	arr[2]=true;
	for(i=3;i<=100;i+=2){
		if(arr[i]==true){
			for(j=i*i;j<=10000;j=j+2*i)
				arr[j]=false;
		}
	}
	prime[0]=2;k=1;
	for(j=3;j<=10000;j+=2){
		if(arr[j]==true){
			prime[k++]=j;
		}
	}
	primelen=j;
}
