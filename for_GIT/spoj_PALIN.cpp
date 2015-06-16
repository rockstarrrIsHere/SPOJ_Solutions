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
int main()
{
    int t;
    char s[1000005];
    int d,i,x,j;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        d=atoi(s)+1;
        while(1){

            snprintf(s,sizeof(s),"%d",d);
            x=strlen(s);
            j=x-1;
            for(i=0;i<x;i++){
                if(s[i]!=s[j])
                    break;
                j--;
            }
            if(i==x)
                break;
            d++;
        }
        printf("%d\n",d);
    }
    return 0;
}
