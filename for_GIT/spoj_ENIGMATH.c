#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
long long int gcd(long long int x,long long int y);
int main()
{
    long long int a,b,c,x,y;
    int t;
    scanf("%d",&t);
    while(t--){
      scanf("%lld %lld",&a,&b);
      x=a;
      y=b;
      c=gcd(a,b);
      printf("%lld %lld\n",y/c,x/c);

    }
    return 0;
}
long long int gcd(long long int x,long long int y){
    long long int a;
    if(x==y)
        return x;
    if(x==0 && y!=0)
        return y;
    if(x!=0 && y==0)
        return x;
    if(x%2==0 && y%2==0)
        a=2*gcd(x/2,y/2);
    if(x%2==0 && y%2==1)
        a=gcd(x/2,y);
    if(x%2==1 && y%2==0)
        a=gcd(x,y/2);
    if(x%2==1 && y%2==1){
        if((abs((y-x)/2))<=x)
           a=gcd((abs((y-x)/2)),x);
        if((abs((y-x)/2))>x)
           a=gcd(x,(abs((y-x)/2)));
    }
    return a;
}
