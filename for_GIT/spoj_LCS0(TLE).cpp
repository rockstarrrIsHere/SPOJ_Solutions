#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <climits>
#include <cfloat>
#include <cassert>
using namespace std;
const int SIZE = 50005;
int dp_x[SIZE + 1]; // dp[x]
int dp_xp1[SIZE + 1]; // dp[x + 1]
char a[SIZE + 1], b[SIZE + 1];

int lcs_bottomUp_2row(){
    int strlenA = strlen(a), strlenB = strlen(b);
    for(int y = 0; y <= strlenB; y++)
        dp_x[y] = 0; // assume x == strlenA
    for(int x = strlenA - 1; x >= 0; x--){
        // x has been decreased
        memcpy(dp_xp1, dp_x, sizeof(dp_x)); // dp[x + 1] <- dp[x]

        dp_x[strlenB] = 0;
        for(int y = strlenB - 1; y >= 0 ; y--)
            dp_x[y] = (a[x]==b[y]) ? 1 + dp_xp1[y+1] :
                    max(dp_xp1[y], dp_x[y+1]);
    }
    return dp_x[0]; // assume x == 0
}

int main(){
    while(gets(a) && gets(b)){
        printf("%d\n", lcs_bottomUp_2row());
    }
}
