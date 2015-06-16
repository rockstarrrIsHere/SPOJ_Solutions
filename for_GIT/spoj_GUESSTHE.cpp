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
unsigned long long int lcm(int a,int b);
unsigned long long int gcd(int a,int b);
int main()
{
    bool arr[25];char c[25];
    int i=1,j,n;
    unsigned long long int d=1,xx;
    while(1){
        d=1;xx=1;
        scanf("%s",c);
        if(c[0]=='*')
            break;
        n=strlen(c);
        for(i=0;i<n;i++){
            if(c[i]=='Y')
                arr[i+1]=true;
            else
                arr[i+1]=false;
        }
        if(arr[1]==true){
            for(i=1;i<=n;i++){
                if(arr[i]==true)
					d=lcm(d,i);
        	}
        	for(i=1;i<=n;i++){
        		if(arr[i]==false){
        			if(d%i==0){
        				printf("-1\n");
        				break;
        			}
        		}
        	}
        	if(i==n+1)
                printf("%lld\n",d);
    	}
        else
            printf("-1\n");
	}
    return 0;
}
unsigned long long int gcd(int a,int b){return (b==0?a:gcd(b,a%b));}
unsigned long long int lcm(int a,int b){return (a*(b/gcd(a,b)));}


