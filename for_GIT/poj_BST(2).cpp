#include"iostream"
using namespace std;
int main(){
    int T,n,d;
    scanf("%d",&T);
    while(T--){
       scanf("%d",&n);
       d=n&-n;
       printf("%d %d\n",n-d+1,n+d-1);
    }
    return 0;
}


#include<cstdio>
#include<queue>
#include<stdio.h>
#include <string>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
   long long int x,n,i;
   cin>>n;
   while(n--){
    cin>>x;
    long long int x1=x;long long int d=0;
    long long int x2=x1;
    while(1){
        d++;
        x1=(x1/2);
        if(x1%2!=0)
            break;
    }
    if(x1==1)
        cout<<1<<' '<<(x*2-1)<<endl;
    else{
      x=x-2*(d-1)-1;
      cout<<x<<' '<<x2+(x2-x)<<endl;
    }
   }
   return 0;
}


