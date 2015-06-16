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
long int arr[1002];
int findd(long long int a);
int main()
{
    long long int m,a,b,c,i,t,p,n,x,sum=0,m1,m2;
    vector<pair<long long int, pair <long long int,long long int> > > v;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&p);
        scanf("%lld",&n);
        scanf("%lld",&m);
        for(i=0;i<=n;i++)
            arr[i]=0;
        for(i=0;i<m;i++){
            scanf("%lld %lld %lld",&a,&b,&c);
            v.push_back(make_pair(c,make_pair(a,b)));
        }
        sort(v.begin(),v.end());
        i=0;sum=0;x=0;
        while(i<m){
            if(x==n-1)
                break;
            a=v[i].second.first;
            b=v[i].second.second;
            if(arr[a]==0 && arr[b]==0){
                arr[a]=b;
                arr[b]=b;
                sum=sum+v[i].first;
                x++;
            }
            if(arr[a]!=0 && arr[b]!=0){
                m1=findd(a);
                m2=findd(b);
                if(m1!=m2){
                    arr[m1]=m2;
                    sum=sum+v[i].first;
                    x++;
                }
            }
            if(arr[a]!=0  && arr[b]==0){
                m1=findd(a);
                arr[b]=m1;
                sum=sum+v[i].first;
                x++;
            }
            if(arr[b]!=0 && arr[a]==0){
                m1=findd(b);
                arr[a]=m1;
                sum=sum+v[i].first;
                x++;
            }
            i++;
        }
        v.resize(0);
        printf("%lld\n",sum*p);
    }
    return 0;
}
int findd(long long int a){
    long long int x;
    if(a==arr[a])
        return arr[a];
    x=findd(arr[a]);
    return x;
}
