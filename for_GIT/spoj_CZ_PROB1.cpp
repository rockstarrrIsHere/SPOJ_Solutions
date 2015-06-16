#include<bits/stdc++.h>
using namespace std;
int dp[8000][3];
int x(int a,int b);
int main(){
    int t;
    bitset<8000> arr;
    int prime[8000],i,j;
    arr[0]=arr[1]=false;
    arr[2]=true;
    for(i=3;i<8000;i+=2){
        arr[i]=true;
        arr[i-1]=false;
    }
    arr[2]=true;prime[0]=2;int k=1;
    for(i=3;i<100;i+=2){
        if(arr[i]==true){
            for(j=i*i;j<8000;j=j+2*i){
                arr[j]=false;
            }
        }
    }
    for(j=3;j<8000;j++){
        if(arr[j]==true)
            prime[k++]=j;
    }
    /*for(i=0;i<k;i++)
        printf("%d ",prime[i]);
    printf("\n\n\n");*/
    int final[505];
    final[0]=0;
    final[1]=2;j=1;
    int flag=0;
    int m=2;
    int i2;
    for(i=2;i<=500 && m<501;i+=2){
        i2=i*i;
        for(j=1;j<=500 && m<501;j+=2){
            if(binary_search(prime,prime+k,i2+j*j)){
                final[m++]=i2+j*j;

            }

        }
    }
    sort(final,final+501);
    memset(dp,0,sizeof(dp));
    scanf("%d",&t);
    int n,sum;
    while(t--){
        scanf("%d %d",&n,&k);
        printf("%d\n",x(final[n],k));
    }
    return 0;
}
int x(int a,int b){
    if(a==0) return dp[a][b]=1;
    if(dp[a][b]) return dp[a][b];
    int i;
    for(i=b;i>0;i--){
        if(a>=i)
            dp[a][b]+=x(a-i,i);
    }
    return dp[a][b];
}
