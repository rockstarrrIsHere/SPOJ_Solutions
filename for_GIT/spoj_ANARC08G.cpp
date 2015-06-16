#include<bits/stdc++.h>
using namespace std;
int arr[1005][1005];
int cnt;
int main(){
    int i=1,n,j,k,d,e,pe;
    while(scanf("%d",&n) && n){
        cnt=0;pe=0;
        for(j=0;j<n;j++)
            for(k=0;k<n;k++){
                scanf("%d",&arr[j][k]);
                if(arr[j][k]!=0)
                    pe+=arr[j][k];
            }
        for(j=0;j<n;j++){
            d=0;e=0;
            for(k=0;k<n;k++){
               d+=arr[j][k];
               e+=arr[k][j];
            }
            d=d-e;
            if(d>0)
                cnt+=d;
        }
        printf("%d. %d %d\n",i,pe,cnt);
        i++;
    }
    return 0;
}









