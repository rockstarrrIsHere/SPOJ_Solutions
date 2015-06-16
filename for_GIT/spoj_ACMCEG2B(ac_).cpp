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
#include<string.h>
using namespace std;
int main()
{
    int n,t,c1,c2,i,j,x,y;
    char s[25];
    map< pair<int,int> ,string> m;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&c1,&c2);
        scanf("%s",s);
        m[make_pair(c1,c2)]=s;
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&c1,&c2);
        cout<<m[pair<int,int>(c1,c2)]<<endl;
    }
    return 0;
}
