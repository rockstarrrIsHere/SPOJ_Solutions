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
float arr[100000][2];
int main()
{
    long int sc,i;
    float R,n,r;
    cin>>sc;
    for(i=0;i<sc;i++)
    {
        cin>>arr[i][0];
        cin>>arr[i][1];
    }
    i=0;
    while(i<sc){
        R=arr[i][0];
        n=arr[i][1];
        r=((R*sin(M_PI/n))/(1+sin(M_PI/n)));

        cout<<"Scenario #"<<(i+1)<<":"<<endl;
        cout.setf(ios::fixed,ios::floatfield);
        cout.precision(3);
        cout<<r<<endl<<'\n';
        i++;
    }
    return 0;
}
