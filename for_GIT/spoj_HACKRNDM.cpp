#include<iostream>
#include<string>
#include<stdio.h>
#include<math.h>
#include<queue>
#include<algorithm>
#include<stack>
#include<string.h>
using namespace std;
long int arr[100000];
int main()
{
    long int n,k,i,j,count=0;
    scanf("%ld %ld",&n,&k);
    for(i=0;i<n;i++)
        scanf("%ld",&arr[i]);
    sort(arr,arr+n);
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if((arr[j]-arr[i])==k)
               count++;
            if((arr[j]-arr[i])>k)
                break;
        }
    }
    printf("%ld",count);
    return 0;
}
