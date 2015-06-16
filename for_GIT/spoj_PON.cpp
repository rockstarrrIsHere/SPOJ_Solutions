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

unsigned long long int gcd(unsigned long long int a, unsigned long long int b);
unsigned long long int mulmod(unsigned long long int a,unsigned long long int b,unsigned long long int c);

unsigned long long int gcd(unsigned long long int a, unsigned long long int b){return b==0?a:gcd(b,a%b);}
unsigned long long int n;
unsigned long long int power(unsigned long long int a,unsigned long long int b);
int main()
{
	unsigned long long int t,i,j,x,d=1,k,count=0;
	scanf("%llu",&t);
	while(t--){
        scanf("%llu",&n);
        if(n%2==0 || n%3==0 || n==1){
            if(n==2 || n==3)
                printf("YES\n");
            else
                printf("NO\n");
        }
        else{
            count=0;
            while(count!=15){
                j=rand()%n;
                if(j!=0 && j!=1){

               // printf("%lld\n",j);
                if(gcd(j,n)==1){
                    d=power(j,n-1);
                    //printf(" %lld\n",d);
                    if(d!=1){
                       printf("NO\n");
                       break;
                    }
                    count++;
                }
                else{
                   printf("NO\n");
                   break;
                }
            }
            }
            if(count==15)
                printf("YES\n");
        }
	}
    return 0;
}
unsigned long long int power(unsigned long long int a,unsigned long long int b){
    unsigned long long int d,p;
    if(b==1)
        return a%n;
    if(b==0)
        return 1;
    d=power(a,b/2);
    p=mulmod(d%n,d%n,n);
    return b%2==0?p:(mulmod(p,a,n));
}
unsigned long long int mulmod(unsigned long long int a,unsigned long long int b,unsigned long long int c){
    unsigned long long int x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}
