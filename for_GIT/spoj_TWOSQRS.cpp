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
#include<bitset>
#include<string.h>
using namespace std;
int main()
{
	unsigned long long int t,i,n,x,y;
    double m;
    scanf("%llu",&t);
    while(t--){
    	scanf("%llu",&n);
    	x=floor(sqrt(n));
    	for(i=0;i<=x;i++){
    		y=n-i*i;
    		m=sqrt(y);
    		if((m-(unsigned long long int)m)==0)
    		{
    				printf("Yes\n");
    				break;
    		}
    	}
    	if(i>x)
    		printf("No\n");
    }
    return 0;
}
