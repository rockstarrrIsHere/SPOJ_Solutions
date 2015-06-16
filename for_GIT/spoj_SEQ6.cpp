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

#define ULL long long int
ULL arr[10000000];

int main()
{
    int n;int i,count,sum,x,j,k;
    while(1){
        vector<vector<ULL> > v;
        scanf("%lld",&n);
        count=0;
        if(n==0)
            break;
        for(i=0;i<n;i++)
            v.push_back(vector<long long int>());
        sum=0;
        for(i=0;i<n;i++){
            sum+=i+1;
            arr[i]=sum;
            x=sum%1000000;
            v[x].push_back(sum);
        }
        for(j=0;j<n-1;j++){
            {
                x=(arr[j]+n)%1000000;
                k=v[x].size();
                printf("%lld ",k);
                printf("\n");
                if(k!=0){
                    for(i=0;i<k;i++){
                        if(v[x][i]==(arr[j]+n))
                            count++;
                    }

                }
            }
        }
        printf("%lld\n",count);
    }
    return 0;
}






