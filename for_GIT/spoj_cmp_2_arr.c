#include<stdio.h>
#include<math.h>
#include<string.h>
#include<malloc.h>


int main(){
    int arr1[100];
    int arr2[100];
    int i,j,n,m;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr1[i]);
    scanf("%d",&m);
    for(i=0;i<m;i++)
        scanf("%d",&arr2[i]);
    j=0;
    for(i=0;i<n;i++){
        if(j<m){
        while(1){
            if(j==m)
                break;
            if(arr1[i]==arr2[j])
                printf("%d ",arr1[i]);
            if(arr2[j]>arr1[i]){

                break;
            }
            j++;
        }
        }


    }
    return 0;
}

