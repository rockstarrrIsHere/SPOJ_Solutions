#include <iostream>
#include<bits/stdc++.h>
using namespace std;
unsigned long long int f(unsigned long long int n);
int main() {
    int t;
    unsigned long long int n;
    scanf("%d",&t);
    while(t--){
        scanf("%llu",&n);
        printf("%llu\n",f(n));
    }
	return 0;
}
unsigned long long int f(unsigned long long int n){
    if(n==2 || n==3)
        return 1;
    unsigned long long int no=0,sum=0,i;
    if(n%2==0){
         sum=2;no=1;
         while(n%2==0)
            n>>=1;
    }
    for(i=3;i*i<=n;i+=2){
        if(n%i==0){
           sum+=i;no++;
           while(n%i==0)
              n/=i;
        }
    }
    if(n>1){
        sum+=n;no++;
    }
    if(no==1 && sum==n)
        return 1;
    return f(sum)+no;

}
