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
#include<bitset>
#include<string.h>
using namespace std;
#define MOD 1000000007
#define ULL long long int
int main()
{
    ULL n,i,j,hetero=0,homo=0,x,d;
    map<long long int ,long long int> m;
    map<long long int ,long long int>::iterator itr;
    char s[15];
    char ins[15]="insert";
    scanf("%lld",&n);
    for(j=1;j<=n;j++){
        scanf("%s %lld",s,&d);
        if(s[0]=='i'){
            itr=m.find(d);
            if(itr==m.end()){
                m.insert(make_pair(d,1));
                hetero++;
            }
            else{
                itr->second++;
                if(itr->second==2)
                    homo++;
            }

        }
        else{
        	itr=m.find(d);
            if(itr!=m.end()){
                itr->second--;
            	if(itr->second==0){
                	 m.erase(itr->first);
                	 hetero--;
            	}
            	if(itr->second!=0){
                	if(itr->second==1)
                	homo--;
            	}
            }

        }
        if(homo>=1){
               if(hetero>=2)
                   printf("both\n");
               else
                   printf("homo\n");
        }
        else
        {
                if(hetero>=2)
                   printf("hetero\n");
               else
                   printf("neither\n");
        }

    }

    return 0;
}

