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
#include<string.h>
using namespace std;


int main()
{
    int t;int i=0;
    int d;
    char arr[20];
    scanf("%d",&t);
    while(t--){
        scanf("%s",arr);
        scanf("%d",&i);
        d=strlen(arr);--i;
        while(next_permutation(arr,arr+d)){
            if(i==0)
                break;
            i--;
    }
    printf("%s\n",arr);

    }
    return 0;
}
