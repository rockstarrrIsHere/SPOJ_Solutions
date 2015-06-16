#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[75];
    unsigned long long int m,a,b,cnt,i,j;
    int ele;
    arr[2]=arr[3]=arr[5]=arr[7]=arr[11]=arr[13]=arr[17]=arr[19]=arr[23]=arr[29]=arr[31]=arr[37]=arr[41]=arr[43]=arr[47]=arr[53]=arr[59]=arr[61]=arr[67]=arr[71]=1;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%llu %llu",&a,&b);
        ele=0;cnt=0;
        m=1<<64;
        for(i=a;i<=b;i++){
            ele=0;
            for(j=0;j<m;j++){
                if((1<<j)>i )
                    break;
                if(i&(1<<j))
                    ele++;
            }
            if(arr[ele]==1)
                cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}


