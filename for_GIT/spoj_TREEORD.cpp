#include<bits/stdc++.h>
using namespace std;
int arr[8002],arr1[8002],arr2[8002],arr3[8002];
void x(int i,int j);
int n;
int main(){
    int i,j;
    scanf("%d",&n);
    for(j=0;j<3;j++)
        for(i=0;i<n;i++){
            if(j==0)    scanf("%d",&arr1[i]);
            if(j==1)    scanf("%d",&arr2[i]);
            if(j==2)    scanf("%d",&arr3[i]);
        }
    x(0,n-1);
    for(i=0;i<n;i++)
    	printf("%d ",arr[i]);
    for(i=0;i<n;i++)
        if(arr[i]!=arr2[i])
            break;
    if(i==n)
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}
void x(int i,int j){
    int k;
    if(i<0 || j<0 || i>=n || j>=n || i>j)
        return;
    k=i;
    while(arr3[k]!=arr1[i])
        k++;
    x(i,k-1);
    x(i+1,j);
    for(k=i+1;k<=j;k++)
        arr[k-1]=arr[k];
    arr[j]=arr1[i];
}








