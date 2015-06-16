#include<stdio.h>
#include<string.h>
long long int arr[1000000];

int main(){
    char *s[10000];
    long long int n,i,count=0;
    int d;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&arr[i]);
        printf(" ");
        gets(s[i]);
    }
    d=0;
    while(d<100){
        for(i=0;i<n;i++){
            if(arr[i]==d){
                count++;
            }
        }
        printf("%lld ",count);
        d++;
    }
    return 0;
}
