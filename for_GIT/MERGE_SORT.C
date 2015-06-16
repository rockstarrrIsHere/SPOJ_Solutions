#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int mergesort(int low,int high);
int arr[10];
int main()
{
    int i=0;
    int n;
	for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
	mergesort(0,(n-1));
    for(i=0;i<n;i++)
        printf("%d\n",arr[i]);
    return 0;
}
// int arr[10];
int mergesort(int low,int high)
{
	int mid=0;int i,t,j,m;
	int a[10];
    if(low==high)
	return 0;
	mid=((low+high)/2);
	mergesort(low,mid);
	mergesort(mid+1,high);
    m=low;
	i=low;j=(mid+1);
	while(1){
        while((arr[i]>=arr[j]) && (i<=mid) && (j<=high)){
            a[m++]=arr[j++];
            if(j>high){
                while(i<=mid)
                    a[m++]=arr[i++];
                break;
            }
        }
        while((arr[j]>arr[i]) && (j<=high) && (i<=mid)){
            a[m++]=arr[i++];
            if(i>mid){
                while(j<=high)
                    a[m++]=arr[j++];
                break;
            }
        }
        if(m==(high+1))
            break;
	}
    for(i=low;i<=high;i++)
        arr[i]=a[i];
    return 0;
}

