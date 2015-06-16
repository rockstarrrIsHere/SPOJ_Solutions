#include<bits/stdc++.h>
using namespace std;
bool arr[120];
void count(int i,int j);
int main(){
    int n,count,i,j,d;
    float x1,x2,x3,y1,y2,y3,x,y;
    vector<pair<float,float> > v;
    pair<float,float> s;
    pair<float,float> e;
    scanf("%d",&n);
    s.first=INFINITY;
    e.first=-INFINITY;
    for(i=0;i<n;i++){
        scanf("%f %f",&x,&y);
        v.push_back(make_pair(x,y));
        x1=s.first;
        s.first=min(s.first,x);
        if(x1!=s.first){
            s=make_pair(x,y);
            x1=s.first;
        }
        x2=e.first;
        e.first=max(e.first,x);
        if(x2!=e.first){
            e=make_pair(x,y);
            x2=e.first;
        }
    }
    memset(arr,false,sizeof(arr));
    count=1;
    x1=s.first;y1=s.second;
    for(i=0;i<n;i++){
        if(v[i].first==x1 && v[i].second==y1)
            arr[i]=true;
        if(v[i].first==e.first && v[i].second==e.second)
            d=i;
    }

    for(i=0;i<n;i++){
        if(!arr[i]){
            x2=v[i].first;
            y2=v[i].second;
            for(j=0;j<n;j++){
               if(!arr[j] && v[j].first!=x1 && v[j].second!=y1 && v[j].first!=x2 && v[j].second!=y2){
                   x3=v[j].first;
                   y3=v[j].second;
                   if(!arr[d])
                      if(( (x3-x1)*(y3-y2) - (y3-y1)*(x3-x2) ) <0)
                          break;
                   if(arr[d])
                      if(( (x3-x1)*(y3-y2) - (y3-y1)*(x3-x2) ) >0)
                          break;
               }
           }
           if(j==n){
              x1=x2;
              y1=y2;
              count++;
              arr[i]=true;
           }
        }
    }
    printf("%d\n",count);
    return 0;
}





