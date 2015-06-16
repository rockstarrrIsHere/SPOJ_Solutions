#include<stdio.h>
#include<malloc.h>
#include<math.h>
int IsFibo(long long int x);
long long int given_series[100000];
int main()
{

    long long int i,t;
    scanf("%lld",&t);
    for(i=0;i<t;i++)
    {
        scanf("%lld",&given_series[i]);
    }

    i=0;
    long long int x;
    int boolean;
    while(i<t)
    {
        x=given_series[i];
        boolean=IsFibo(x);
        if(boolean==1)
            printf("IsFibo");
        else
            printf("IsNotFibo");
        i++;
    }
    return 0;
}
int IsFibo(long long int x)
{
    long long int i1=0,i2=1,d;
    while(1)
    {
        d=(i1+i2);
        if(d==x)
            return 1;
        i1=i2;
        i2=d;
        if(d>x)
            return 0;
    }
    return 0;
    /*long long int mid;
    int a=0;
    if(low==high)
    {
        if(fibo_series[low]==x)
        {
            return 1;
        }
        else
            return 0;
    }
    mid=(low+high)/2;
    if(fibo_series[mid]>x)
    {
        a=IsFibo(fibo_series,low,mid-1,x);

    }
    if(fibo_series[mid]<x)
    {
        a=IsFibo(fibo_series,mid+1,high,x);

    }
    if(fibo_series[mid]==x)
    {
        return 1;
    }
    return a;
    */

}
