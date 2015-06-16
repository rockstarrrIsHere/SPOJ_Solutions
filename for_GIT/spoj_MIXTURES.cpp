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
#define ULL unsigned long long int
#define MOD 100
using namespace std;
ULL arr[105],t[105][105];
void insertme(ULL i,ULL j);
int main()
{
    ULL n,ans,i,k,count;
    while(scanf("%llu",&n)!=-1){
        for(i=0;i<n;i++)
           scanf("%llu",&arr[i]);
        for(i=0;i<n;i++)
            t[i][i]=0;
        count=1;
        while(count!=n){
            for(i=0;i<n-count;i++)
                insertme(i,i+count);
            count++;
        }
        printf("%llu\n",t[0][n-1]);
    }
    return 0;
}
void insertme(ULL i,ULL j){
    ULL k,m,m1,m2,d;
    for(k=i;k<j;k++){
       m1=0;m2=0;
       for(m=i;m<=k;m++)
          m1+=arr[m];
       for(m=k+1;m<=j;m++)
          m2+=arr[m];
       m1%=MOD;m2%=MOD;
       if(k==i)
          d=(t[i][k]+t[k+1][j]+m1*m2);
       else
          d=min(d,(t[i][k]+t[k+1][j]+m1*m2));
    }
    t[i][j]=d;
}


