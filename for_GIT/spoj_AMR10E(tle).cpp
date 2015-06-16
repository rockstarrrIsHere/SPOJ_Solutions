#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
#include<map>
#define MOD 1000000007
#define ULL unsigned long long int
ULL arr[30];ULL a[30];
int main() {
    ULL t,n,r,k,ans,i,index=0,sum,j,x,p;
    scanf("%llu",&t);
    while(t--){
        arr[0]=0;
        index=0;sum=0;
        scanf("%llu %llu %llu",&n,&r,&k);
        for(i=1;i<=r;i++)
            scanf("%llu",&arr[i]);
        for(i=1;i<=r;i++)
            scanf("%llu",&a[i]);
		i=r+1;
        while(i<=8){
            sum=0;p=1;
            for(j=i-r;j<i;j++)
                sum=(sum+a[p++]*arr[j])%MOD;
            arr[i]=sum;
            i++;
        }

      /*  for(i=1;i<=8;i++)
        	printf("%d " ,arr[i]);
        	printf("\n");
        */
        index=k;ans=0;
        while(n--){
        	if(index>=9){
                for(i=9;i<17;i++){
                    sum=0;p=1;
                    for(j=i-r;j<i;j++)
                        sum=(sum+a[p++]*arr[j])%MOD;
                    arr[i]=sum;
                }
                for(i=1;i<=8;i++)
                   arr[i]=arr[i+8];
                index-=8;
            }
            ans=(ans+arr[index])%MOD;
            index+=k;
        }
        printf("%llu\n",ans);
    }
    return 0;
}

