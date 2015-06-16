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
#include<bitset>
#include<string.h>
using namespace std;
#define ULL unsigned long long int
#define MOD 1000000007
int main()
{
    int t,i,a,b,c,n;
    scanf("%d",&t);
    while(t--){
        priority_queue<int,vector<int>,less<int> > left;
        priority_queue<int,vector<int>,greater<int> > right;
        scanf("%d %d %d %d",&a,&b,&c,&n);
        ULL ls,rs=0,x;
        ULL sum=1,d,a1,b1;
        left.push(1);
        ls=left.size();
        rs=right.size();
        for(i=2;i<=n;i++){
            x=left.top();
            d=((ULL)a*x+(ULL)b*i+c);
            if(d>=MOD)
            	d%=MOD;
            sum+=d;
            if(d<x){
                left.push(d);
                ls++;
            }
            else{
                right.push(d);
                rs++;
            }
            while(ls>rs+1){
                x=left.top();
                right.push(x);left.pop();
                ls--;rs++;
            }
            while(rs>ls){
                x=right.top();
                left.push(x);right.pop();
                rs--;ls++;
            }

        }
        printf("%llu\n",sum);
    	//left.resize(0);
    	//right.resize(0);
    }
    return 0;
}
