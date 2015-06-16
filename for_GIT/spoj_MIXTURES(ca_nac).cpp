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
    int v[101];
    int n,i,j,m;
    long long int x,d,sum=0;
    while(1){
        scanf("%d",&n);
        if(n==-1)
            break;
        for(i=0;i<n;i++)
           scanf("%d",&v[i]);
        sort(v,v+n);
        sum=0;j=0;
        for(i=1;i<n;i++){
            if(i==1){
                sum=sum+v[i]*v[j];
                m=(v[i]+v[j])%100;
            }
            else{
                sum=sum+m*v[i];
                m=(m+v[i])%100;
            }
        }
        while(next_permutation(v,v+n)){
            d=0;j=0;
            for(i=1;i<n;i++){
                if(i==1){
                    d=d+v[i]*v[j];
                    m=(v[i]+v[j])%100;
                }
                else{
                    d=d+m*v[i];
                    m=(m+v[i])%100;
                }
            }
            sum=min(d,sum);
        }
        printf("%lld\n",sum);
    }
    return 0;
}

