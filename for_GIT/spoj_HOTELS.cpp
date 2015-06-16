#include<iostream>
#include<string>
#include<stdio.h>
#include<math.h>
#include<queue>
#include<algorithm>
#include<stack>
#include<string.h>
using namespace std;
long long int arr[300001];
int main()
{
    long long int i,n,m,d,j,sum;
    scanf("%lld %lld",&n,&m);
    j=0;sum=0;d=0;
    for(i=0;i<n;i++){
        scanf("%lld",&arr[i]);
        if(d<m){
          sum=sum+arr[i];
          if(sum>m){
             while(sum>m){
                sum=sum-arr[j];
                j++;
             }
          }
          d=max(d,sum);
        }
    }
    printf("%lld\n",d);
    return 0;
}



