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
    int t,n,x;
    queue<int> q;
    char s[15];
    map< int,string > m;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        while(n--){
            scanf("%s",s);
            m[n]=s;
            q.push(n);
        }
        while(1){
            if(q.size()==1){
                n=q.front();
                q.pop();
                break;
            }
            q.pop();
            x=q.front();
            q.pop();
            q.push(x);
        }
        cout<<m[n]<<endl;
    }
    return 0;
}
