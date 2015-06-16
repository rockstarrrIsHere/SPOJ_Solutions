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
#define MOD 1000000007
#define ULL long long int
ULL arr[1000005];
int main()
{
    ULL t,n,count=0,i,j,sum,x,k,y;
    scanf("%lld",&t);
    while(t--){
        count=0;
        vector<vector<pair<ULL,ULL> > > v;
        for(i=0;i<10;i++)
            v.push_back(vector<pair<ULL,ULL> >());
        scanf("%lld",&n);
        sum=0;
        for(i=0;i<n;i++){
            scanf("%lld",&y);
            sum+=y;
            arr[i]=sum;
            x=arr[i]%10;
            v[x].push_back(make_pair(arr[i],i));
        }count=0;
        /*
        for(i=0;i<10;i++){
            k=v[i].size();
            printf("%lld  ",k);
            for(j=0;j<k;j++)
                printf("%lld,%lld \n",v[i][j].first,v[i][j].second);
            printf("\n");
        }*/
        for(j=0;j<n;j++){
            x=(arr[j]+47)%10;
            if(v[x].size()!=0){
                k=v[x].size();
                for(i=0;i<k;i++){
                    if(v[x][i].first==(arr[j]+47) && v[x][i].second>j)
                        count++;
                }
            }
        }
        printf("%lld\n",count);

    }

    return 0;
}

