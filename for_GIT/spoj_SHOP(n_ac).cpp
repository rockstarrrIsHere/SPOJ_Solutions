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
#include <utility>
using namespace std;
int main(){
    int w,h;
    char arr[30][30];
    int t;
    while(scanf("%d %d",&w,&h)==2 && w && h){
        for(i=1;i<=h;i++){
            for(j=1;j<=w;j++){
                scanf("%c",&arr[i][j]);
                if(char[i][j]=='S'){
                    d=make_pair(i,j);
                }
                if(char[i][j]=='D'){
                    dd=make_pair(i,j);
                }
            }
        }


    }
    return 0;
}
