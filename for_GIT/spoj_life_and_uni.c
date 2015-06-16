#include<stdio.h>
#define N 1000000
int arr[N];
int main()
{
    int i;
    long long int n;
    i=0;
    scanf("%d",&n);
    while(i<n)
    {
        scanf("%d",&arr[i]);
        i++;
    }
    i=0;
    while(i<n)
    {
        if(arr[i]!=42)
            printf("%d",arr[i]);
        else
            break;
        i++;
    }
}
