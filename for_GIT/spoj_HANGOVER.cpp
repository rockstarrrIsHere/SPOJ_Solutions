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
#define MOD 1000000007
#define ULL long long int
int main()
{
    float sum,c,k;
    int i;
    while(1){
        scanf("%f",&c);
        if(c==0.00)
        	break;
        i=1;sum=0;
        while(1){
        	k=float(1/(float)(i+1));
        //	printf("%f\n",k);
        	sum+=k;
        	if(sum>=c)
        		break;
        	i++;
        }
        cout<<i<<' '<<"card(s)"<<endl;
    }
    return 0;
}
