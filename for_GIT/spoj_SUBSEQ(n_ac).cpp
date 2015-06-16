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
#include<bitset>
#include<string.h>
using namespace std;
#define MOD 1000003
#define LL long long int
LL arr[MOD];
int main()
{
    LL sum,count,t,n,i,x,j,y,k;
    scanf("%lld",&t);
    while(t--){
        vector<pair<LL,LL> >*v=new vector<pair<LL,LL> >[1000003];
        scanf("%lld",&n);
        sum=0;
        for(i=0;i<n;i++){
            scanf("%lld",&y);
            sum+=y;
            arr[i]=sum;
            x=arr[i]%MOD;
            v[x].push_back(make_pair(arr[i],i));
        }count=0;
        for(j=-1;j<n-1;j++){
            if(j==-1){
            	x=47;
                k=v[x].size();
                for(i=0;i<k;i++){
                    if(v[x][i].first==47)
                        count++;
                }
            }
            else{
            	x=(arr[j]+47)%MOD;
                k=v[x].size();
                for(i=0;i<k;i++){
                    if((v[x][i].first==(47+arr[j])) && (v[x][i].second>j))
                        count++;
                }
            }
        }
        printf("%lld\n",count);
    }
	return 0;
}



