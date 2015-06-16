#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include<math.h>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <climits>
#include <cfloat>
#include <cassert>
using namespace std;
bool arr[1000001];
int main(){
    int t,x,y,n,i,j;long long int bad,xy;
    char s[100];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        bad=0;
        memset(arr,0,sizeof(arr)+1);
        for(i=1;i<=n;i++){
            scanf("%s %d",s,x);
            if(arr[x]==1){
                i=j=x;
                while(arr[i]==1 && arr[j]==1){
                    i++;j--;
                    if(i>n)
                        i=1;
                    if(j<1)
                        j=n;
                }
                xy=min(abs(i-x),abs(x-j));
                if(abs(i-x)<=abs(x-j))
                    arr[i]=1;
                else
                    arr[j]=1;
                bad+=xy;
            }
            else{
                arr[x]=1;
            }
        }
    }
    return 0;
}

