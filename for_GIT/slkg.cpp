#include<bits/stdc++.h>
using namespace std;
int arr[10];
void mergesort(int i,int j);
int main(){
    int i;
    int n;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>arr[i];
    mergesort(0,n-1);
    cout<<endl<<endl;
    for(i=0;i<n;i++)
        cout<<arr[i]<<endl;
}
void mergesort(int i, int j){
    int mid=(i+j)/2;
    int temp[10];
    if(i>=j)
        return ;

    mergesort(i,mid);
    mergesort(mid+1,j);
    int m,n,k;
    m=i;n=mid+1;k=0;
    while(m<=mid && n<=j){
        if(arr[m]<=arr[n]){
            temp[k++]=arr[m++];
        }
        else
            temp[k++]=arr[n++];
    }
    while(m<=mid)
        temp[k++]=arr[m++];
    while(n<=j)
        temp[k++]=arr[n++];
    k=0;
    for(m=i;m<=j;m++)
        arr[m]=temp[k++];
}
