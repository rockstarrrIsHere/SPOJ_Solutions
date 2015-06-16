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
    while(1){
        scanf("%lld",&n);
        if(n==-1)
            break;
        sum=0;
        for(i=1;i<=n;i++){
            scanf("%lld",&arr[i]);
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
                    if(arr[i]>x){
                       carry=1;
                       if(i==1){
                          if(arr[i+1]<arr[i] && arr[i+1]>x){
                            arr[i]--;arr[i+1]++;
                          }
                       }
                       if(i==n){
                          if(arr[i-1]<arr[i] && arr[i-1]>x){
                            arr[i]--;arr[i-1]++;
                          }
                       }
                       continue;
                    }
                    if(i==1){
                        if(arr[1]<x){
                            carry=1;
                            if(arr[i]<arr[i+1]){
                                arr[i]++;arr[i+1]--;
                            }
                        }
                    }
                    if(i==n){
                        if(arr[i]<x){
                            carry=1;
                            if(arr[i]<arr[i-1]){
                                arr[i]++;arr[i-1]--;
                            }
                        }
                    }
                }
                else{
                    if(arr[i]>x){
                        carry=1;
                        if((arr[i-1]>x && arr[i-1]<arr[i])&& (arr[i+1]>x) && arr[i-1]<arr[i] ){
                            if(arr[i-1]==arr[i+1]){
                                arr[i+1]++;arr[i]--;
                                if(arr[i-1]<arr[i]){
                                    arr[i-1]++;arr[i]--;
                                }
                            }
                            else{
                                if(arr[i-1]<arr[i+1]){
                                    arr[i-1]++;arr[i]--;
                                    if(arr[i+1]<arr[i]){
                                        arr[i+1]++;arr[i]--;
                                    }
                                }
                                else{
                                    if(arr[i+1]<arr[i-1]){
                                        arr[i+1]++;arr[i]--;
                                        if(arr[i-1]<arr[i]){
                                            arr[i-1]++;arr[i]--;
                                        }
                                    }
                                }
                            }
                        }
                        else{
                            if((arr[i-1]>x && arr[i-1]<arr[i]) && ((arr[i+1]<x) || arr[i+1]>x && arr[i+1]>=arr[i] ){
                                arr[i-1]++;arr[i]--;
                            }
                            else{
                                if((arr[i+1]>x && arr[i+1]<arr[i]) && ((arr[i-1]<x) || arr[i-1]>x && arr[i-1]>=arr[i] ){
                                    arr[i+1]++;arr[i]--;
                                }
                            }
                        }
                        continue;
                    }
                    else{
                        if(arr[i]<x){
                            carry=1;
							if(arr[i]<arr[i-1] && arr[i]<arr[i+1]){
                                if(arr[i+1]>arr[i-1]){
                                    arr[i+1]--;arr[i]++;
                                    if(arr[i]==x)
                                        continue;
                                    if(arr[i-1]>arr[i]){
                                        arr[i-1]--;arr[i]++;
                                    }
                                }
                                else{
                                    arr[i-1]--;arr[i]++;
                                    if(arr[i]==x)
                                        continue;
                                    if(arr[i+1]>arr[i]){
                                        arr[i+1]--;arr[i]++;
                                    }
                                }
                            }
                            else{
                                if(arr[i]<arr[i+1] && arr[i]>=arr[i-1]){
                                    arr[i]++;arr[i+1]--;
                                }
                                else{
                                    if(arr[i]<arr[i-1] && arr[i]>=arr[i+1]){
                                        arr[i]++;arr[i-1]--;
                                    }
                                }
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
        }
    }
    return 0;
}
