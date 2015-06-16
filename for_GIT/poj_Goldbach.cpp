#include<iostream>
#include<stdio.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include<stack>
#include<queue>
using namespace std;

long int arr[1000000];
long int p[1000000];
int main(){
    long int m,n,j,k,pp;
    int i,t=0;
    long int pi;
    p[0]=2;
    pi=1;
    while(1){
        scanf("%ld",&arr[t]);
        if(arr[t]==0)
            break;
        t++;
    }
    i=0;
    while(i<t){
        n=arr[i];
        pi=1;p[0]=2;
        for(j=3;j<=n;j++){
           for(m=0;m<pi;m++){
              if(j%p[m]==0)
                break;
              }
              if(m==pi){
                p[pi++]=j;
              }
        }
            for(pp=1;pp<(pi-1);pp++){
                for(k=pp+1;k<pi;k++){
                if((p[pp]+p[k])==n){
                  cout<<n<<" = "<<p[pp]<<" + "<<p[k]<<endl;
                  break;
                }
             }
             if(((p[pp]+p[k])==n) && (k<pi) && (pp<(pi-1)))
                    break;
        }
        if(((p[pp]+p[k])==n) && (k<pi) && (pp<(pi-1)))
                    break;


      i++;
    }

    return 0;
}


