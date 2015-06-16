#include<iostream>
#include<string>
#include<stdio.h>
#include<math.h>
#include<queue>
#include<algorithm>
#include<stack>
#include<vector>
#include<list>
#include<string.h>
using namespace std;
int main()
{
    vector<pair<int,pair<int,int> > > v;
    int a,b,c;
    int i,t=2;
    while(t--){
    for(i=0;i<=1;i++){
        scanf("%d %d %d",&a,&b,&c);
        v.push_back(make_pair(a,make_pair(b,c)));
    }
    sort(v.begin(),v.end());
    //cout<<v[0].second.second;
    for(i=0;i<=1;i++)
        cout<<v[i].second.first<<' '<<v[i].second.second<<endl;

    v.resize(0);
    }
    return 0;
}
