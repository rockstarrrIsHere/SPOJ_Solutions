#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
#include<map>
#define ULL unsigned long long int
ULL arr[1000005];
int main() {
    ULL t,n,i;
    arr[0]=1;
    arr[1]=5;
    //for(i=2;i<=1000002;i++)
      //  arr[i]=(3*arr[i-1]-3*arr[i-2]+1);
    scanf("%llu",&t);
    while(t--){
        scanf("%llu",&n);
        printf("%llu\n",(n*(n+2)*(2*n+1)/8));
    }
}
