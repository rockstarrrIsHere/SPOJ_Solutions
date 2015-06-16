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
#define ULL unsigned long long int
//#define MOD 1000000007
using namespace std;
bool Fermat(ULL p,int itr);
ULL modulo(ULL a,ULL n,ULL MOD);
int main(){
    ULL t,n,itr=1,i;
    bool b;
    scanf("%llu",&t);
    while(t--){
        itr=2;
        scanf("%llu",&n);
        if(n==3) printf("2\n");
        if(n==4 || n==5) printf("3\n");
        if(n>5){
        n=n%2==0?n+1:n;
        n=n-2;
        while(1){
            b=Fermat(n,itr);
            if(b)
                break;
            n=n-2;;
        }
        printf("%llu\n",n);
        }
    }
    return 0;
}
bool Fermat(ULL p,int itr){
    int i;ULL d;
    ULL a;
    if(p==1)
        return false;
    for(i=1;i<=itr;i++){
        a=rand()%(p-1)+1; // random number between 1 and p-1.
        d=modulo(a,p-1,p);
        if(d!=true)
           return false;
    }
    return true;
}
ULL modulo(ULL a,ULL n,ULL MOD){
    ULL t;
    if(n==0)
        return 1;
    if(n==1)
        return a%MOD;
    t=modulo(a,n/2,MOD);
    return n%2==0?(t*t)%MOD:(t*t*a)%MOD;
}
void generate_prime(){

}
