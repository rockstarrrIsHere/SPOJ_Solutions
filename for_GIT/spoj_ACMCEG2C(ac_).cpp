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
#include<deque>
#include<string.h>
using namespace std;
int main()
{
    int t,n,k,i,m,j;
    deque<int> d(10005);
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++)
            scanf("%d",&d[i]);
        i=0;m=0;
        while(1){
            if((i+k)>n)
                break;
            if(m==0){
                for(j=i;j<i+k;j++)
                    m=max(m,d[j]);
                printf("%d ",m);
                if(m==d[i])
                    m=0;
            }
            else{
                m=max(m,d[i+k-1]);
                printf("%d ",m);
                if(m==d[i])
                    m=0;
            }
            i++;
        }
        printf("\n");
    }
    return 0;
}
