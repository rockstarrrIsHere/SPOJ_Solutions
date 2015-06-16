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
#include<map>
#include<string.h>
using namespace std;
int main()
{
    int n,t,c1,c2,i,j,x,y;
    string s;
    pair<int,int> p;
    vector<pair<int,int> > v ;
    map< pair<int,int> ,string> m;
    map< pair<int,int> ,string>::iterator itr;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&c1,&c2);
        cin>>s;
        p.first=c1;
        p.second=c2;
        v.push_back(p);
        m[make_pair(c1,c2)]=s;
        for(i=0;i<v.size();i++){
           if(v[0].first==c1 && v[0].second==c2)
               break;
        }
        if(i!=v.size()){
           x=v[i].first;
           y=v[i].second;
           if(m[pair<int,int>(x,y)]!=s){
             m[pair<int,int>(x,y)]=s;
           }
        }
        else{
           p.first=c1;
           p.second=c2;
           v.push_back(p);
           m[make_pair(c1,c2)]=s;
        }

    }
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&c1,&c2);
        for(itr=m.begin();itr!=m.end();itr++){
            if(itr->first.first==c1 && itr->first.second==c2)
                cout<<m[pair<int,int>(c1,c2)]<<endl;
        }
    }
    return 0;
}
