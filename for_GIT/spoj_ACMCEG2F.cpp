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
using namespace std;
bool comp(const pair <long long int,long long int>& itr1,const pair <long long int,long long int>& itr2);
bool comp(const pair <long long int,long long int>& itr1,const pair <long long int,long long int>& itr2){
    if(itr1.first > itr2.first)
        return false;
    if((itr1.first==itr2.first) && (itr1.second < itr2.second))
        return false;
    return true;
}
int main()
{
    vector<pair<long long int,long long int> > v;
    int t;
    vector<pair<long long int,long long int> >::iterator itr;
    long long int n,c1,c2;
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        while(n--){
            scanf("%lld %lld",&c1,&c2);
            v.push_back(make_pair(c1,c2));
        }
        sort(v.begin(),v.end(),comp);
        for(itr=v.begin();itr!=v.end();itr++){
            printf("%lld %lld\n",itr->first,itr->second);
        }
        v.resize(0);

    }
    return 0;
}
