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
#include<string.h>
using namespace std;
#define MOD 1000000007
long long int arr[10005];
int main()
{
	unsigned long long int count,d=1,x,n,i,k,j,t;
	scanf("%llu",&t);
	while(t--){
        scanf("%llu",&n);
        count=0;d=1;i=3;
        for(i=3;i<=sqrt(n)+1;i+=2){
            if(n==1)
                break;
            count=0;
            while(n%i==0){
                n=n/i;
                count++;
            }
            if(count!=0)
                d=d*(2*count+1);
        }
        if(n>1)
            d=d*3;
        printf("%llu\n",d/2);
	}
    return 0;
}


