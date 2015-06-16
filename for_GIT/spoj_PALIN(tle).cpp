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
#include<string.h>
using namespace std;
char s[1000005];
int arr[1000005];
int main()
{
    int t;
    int i,x,j;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        x=strlen(s);
        for(i=0;i<x;i++)
            arr[i]=s[i]-'0';
        if(x==1){
              if(arr[0]<=8)
                    printf("%d\n",arr[0]+1);
              else
                printf("11\n");
        }
        else{
            if(x%2==0){
                i=x/2;j=x/2;
            }
            else{
                i=x/2-1;j=x/2+1;
            }
            ant=0;bka=0;
            while(i>=0 && j<=x-1){
                if(arr[i]>arr[j]){
                    if(ant==0 && bka==0){
                        arr[j]=arr[i];
                        ant=1;bka=1;
                    }
                    if(bka==1){
                        arr[j]=arr[i];
                    }
                    if(ant==1){
                        arr[j]=arr[i];
                    }

                }
                if(arr[i]<arr[j]){
                    if(ant==1){
                        arr[j]=arr[i];
                    }
                    if(bka==0 && ant==0){
                        arr[i]=arr[j];
                        bka=1;ant=1;
                    }
                    if(bka==1){
                        arr[j]=arr[i];
                    }
                }
                i--;j++;
            }
            if(ant==0 && bka==0){
                if(x%2==0){
                    i=x/2;j=x/2;
                }
                else{
                    i=x/2-1;j=x/2+1;
                }
                ant=0;
                while(i>=0 && j<=x-1){
                    if(arr[i]<=8){
                        arr[i]=arr[i]+1;
                        arr[j]=arr[j]+1;
                        ant=1;
                    }
                    i--;j++;
                }
                if(ant==0){

                    printf("\n");
                }
            }
        }
        for(i=0;i<x;i++)
            printf("%d",arr[i]);
        printf("\n");
    }
    return 0;
}
