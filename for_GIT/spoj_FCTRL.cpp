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
long int arr[10000000];
int main()
{
    long int sumo,d,n,i,t,m,sum=0;
    int x;float l=5.0;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>arr[i];
    }
    for(i=0;i<t;i++){
        n=arr[i];
        sum=n/5;x=1;
        sumo=sum;
        while(1){
           if(sumo>=(long int )pow(5.0f,x)){
            sum=(sum+(sumo/(long int )pow(5.0f,x)));
           }
           if(sumo<(long int )pow(5.0f,x))
            break;
           x++;
        }


        cout<<sum<<endl;
    }
    return 0;
}
