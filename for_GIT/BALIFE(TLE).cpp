#include<iostream>
#include<string>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<algorithm>
#include<stack>
#include<vector>
#include<list>
#include<map>
#include<bitset>
#include<string.h>
using namespace std;
#define MOD 1000000007
#define ULL long long int
int main()
{
    ULL n,arr[9005],carry,sum=0,i,par,jyada,kam,mmval,count,x;
    ULL brr[9005][4];
    while(1){
        scanf("%lld",&n);
        if(n==-1)
            break;
        sum=0;
        for(i=1;i<=n;i++){
            scanf("%lld",&arr[i]);
            brr[i][0]=0;
            brr[i][1]=0;
            brr[i][2]=0;
            brr[i][3]=0;
            sum+=arr[i];
        }
        if(sum%n!=0){
            printf("-1\n");
            continue;
        }
        if(n==1){
            printf("0\n");
            continue;
        }
        x=sum/n;
        carry=0;count=0;
        while(1){
            carry=0;
            for(i=1;i<=n;i++){
                if(i==1 || i==n){
                    if(i==1){
                        if(arr[i]<x){
                            carry=1;
                            if(arr[i+1]>0){
                                if(brr[i][1]!=1 && brr[i+1][2]!=1){
                                    arr[1]++;arr[2]--;
                                    brr[i][1]=1;brr[i+1][2]=1;
                                }
                            }
                        }
                        else{
                            if(arr[i]==x){
                               continue;
                            }
                            else{
                                carry=1;
                              //  if(arr[i+1]>arr[i]){
                                    if(brr[i][3]!=1 && brr[i+1][0]!=1){
                                        arr[i+1]++;arr[i]--;
                                        brr[i+1][0]=1;brr[i][3]=1;
                                    }
                                //}
                            }
                        }
                    }
                    else{
                        if(arr[i]<x){
                            if(arr[i-1]>0){
                                carry=1;
                                if(brr[i][0]!=1 && brr[i-1][3]!=1){
                                    arr[i]++;arr[i-1]--;
                                    brr[i][0]=1;brr[i-1][3]=1;
                                }
                            }
                        }
                        else{
                            if(arr[i]==x){
                                continue;
                            }
                            else{
                                carry=1;
                               // if(arr[i-1]>arr[i]){
                                    if(brr[i][2]!=1 && brr[i-1][1]!=1){
                                        arr[i]--;arr[i-1]++;
                                        brr[i][2]=1;brr[i-1][1]=1;
                                    }
                              //  }
                            }
                        }
                    }
                }
                else{
                    if(arr[i]<x){
                        carry=1;
                        if(arr[i+1]>0 && arr[i-1]>0){
                            if(arr[i+1]>arr[i-1]){
                                if(brr[i][1]!=1 && brr[i+1][2]!=1){
                                    arr[i+1]--;arr[i]++;
                                    brr[i+1][2]=1;brr[i][1]=1;
                                }
                                if(arr[i]==x)
                                    continue;
                                if(brr[i][0]!=1 && brr[i-1][3]!=1){
                                    arr[i-1]--;arr[i]++;
                                    brr[i-1][3]=1;brr[i][0]=1;
                                }
                            }
                            else{
                                if(brr[i-1][3]!=1 && brr[i][0]!=1){
                                    arr[i-1]--;arr[i]++;
                                    brr[i-1][3]=1;brr[i][0]=1;
                                }
                                if(arr[i]==x)
                                    continue;
                                if(brr[i+1][2]!=1 && brr[i][1]!=1){
                                    arr[i+1]--;arr[i]++;
                                    brr[i+1][2]=1;brr[i][1]=1;
                                }
                            }
                        }
                        else{
                            if(arr[i+1]>0){
                                if(brr[i+1][2]!=1 && brr[i][1]!=1){
                                    arr[i+1]--;arr[i]++;
                                    brr[i+1][2]=1;brr[i][1]=1;
                                }
                            }
                            else{
                                if(brr[i-1][3]!=1 && brr[i][0]!=1){
                                    arr[i-1]--;arr[i]++;
                                    brr[i-1][3]=1;brr[i][0]=1;
                                }
                            }
                        }
                    }
                    else{
                        if(arr[i]==x)
                            continue;
                        else{
                            carry=1;
                            if(arr[i+1]>arr[i-1]){
                                if(brr[i-1][1]!=1 && brr[i][2]!=1){
                                    arr[i]--;arr[i-1]++;
                                    brr[i-1][1]=1;brr[i][2]=1;
                                }
                                if(arr[i]==x)
                                        continue;
                                //if(arr[i+1]>arr[i]){
                                    if(brr[i+1][0]!=1 && brr[i][3]!=1){
                                        arr[i]--;arr[i+1]++;
                                        brr[i+1][0]=1;brr[i][3]=1;
                                    }
                               // }
                            }
                            else{
                                //if((arr[i+1]>arr[i]) && (arr[i+1]>=arr[i-1])){
                                    if(brr[i+1][0]!=1 && brr[i][3]!=1){
                                        arr[i]--;arr[i+1]++;
                                        brr[i+1][0]=1;brr[i][3]=1;
                                    }
                               // }
                                if(arr[i]==x)
                                    continue;
                              //  if(arr[i-1]>arr[i]){
                                    if(brr[i-1][1]!=1 && brr[i][2]!=1){
                                        arr[i]--;arr[i-1]++;
                                        brr[i-1][1]=1;brr[i][2]=1;
                                    }
                              //  }
                            }
                        }
                    }
                }
            }
            if(carry==0){
                printf("%lld\n",count);
                break;
            }
            count++;
            for(i=1;i<=n;i++){
                brr[i][0]=0;
                brr[i][1]=0;
                brr[i][2]=0;
                brr[i][3]=0;
            }
        }
    }

    return 0;
}

