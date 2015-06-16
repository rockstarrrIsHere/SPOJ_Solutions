#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
#include<map>
#define ULL unsigned long long int
map<ULL,ULL> m;
map<ULL,ULL>::iterator itr;
ULL x(ULL n);
int main() {
    ULL n,ans;
    while(scanf("%llu",&n)!=-1){
        m[0]=0;
        ans=x(n);
        printf("%llu\n",ans);
    }
}
ULL x(ULL n){
    ULL t;
    if(n==0)
        return 0;
    /*if(n%12==0){
        ULL count=0,x=n;
        while(x%12==0){
            count++;
            x/=12;
        }
        return (n+count);
    }*/
    if(1){
        itr=m.find(n);
        if(itr!=m.end())
            return itr->second;
    }
    t=max(n,(x(n/2)+x(n/3)+x(n/4)));
    m[n]=t;
    return t;
}
