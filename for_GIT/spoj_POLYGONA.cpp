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
int arr[505][2];
int main(){
    int t,x1,x2,y1,y2,n,i;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d %d",&arr[i][0],&arr[i][1]);
        }
        sort(arr[0])
        double sum=0;
        for(i=1;i<n-1;i++){
            x1=arr[i][0]-arr[0][0];
            y1=arr[i][1]-arr[0][1];
            x2=arr[i+1][0]-arr[0][0];
            y2=arr[i+1][1]-arr[0][1];
            sum+=(x1*y2-x2*y1);
        }
        sum=0.5*abs(sum);
        printf("%0.1f\n",sum);
    }
    return 0;
}

