#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include<bitset>
#include <utility>
using namespace std;
int main(){
    int t,i,j,n;
    int count=0;
//    seive();
    int prime[5]={3,5,17,257,65537};
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n%2==0){
            while(n%2==0)
                n/=2;
        }
        for(j=0;j<=4;j++){
            if(n%prime[j]==0){
                n/=prime[j];
                if(n%prime[j]==0){
                    printf("No\n");
                    break;
                }
            }
        }
        if(j>4){
            if(n>1)
                printf("No\n");
            else
                printf("Yes\n");
        }

    }
    return 0;
}

