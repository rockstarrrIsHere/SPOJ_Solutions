#include<stdio.h>
#include<math.h>
#include<string.h>
#include<bitset>
#include<iostream>
using namespace std;

int main()
{
    int t;
    long long int n,m,i,j;
    bitset<true> c;
    for(i=2;i<=1000000000;i++){
        if(c[i]==true){
            for(j=i*i;j<=1000000000;){
                c[j]=false;
                j=j+i;
            }
        }
    }
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld",&m,&n);
        for(i=m;i<=n;i++){
            if(c[i]==true)
                printf("%lld\n",i);
        }
        printf("\n");
	}
    return 0;
}
