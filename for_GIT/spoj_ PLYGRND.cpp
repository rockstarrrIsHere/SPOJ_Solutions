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
#define EPS 0.0000001
using namespace std;
int main(){
    int k,i;
    while(1){
        float arr[25],x;
        set<float> st;
    	set<float>::iterator itr;
        scanf("%d",&k);
        if(k==0)
        	break;
        scanf("%f",&x);
        st.insert(x);
        int flag=0;
        for(i=0;i<k-1;i++){
            scanf("%f",&x);
            if(!flag){
                if(st.find(x)!=st.end()){
                    flag=1;
                }
                if(!flag){
                    st.insert(x);
                }
            }
        }
        if(flag==1){
            printf("YES\n");
        }
        else{
            if(k==1 || k==2)
                printf("NO\n");
            else{
                int d=0;long double sum=0;
                for(itr=st.begin();itr!=st.end();itr++){
                    arr[d++]=*itr;
                   // printf("%f ",*itr);

                    sum+=*itr;
                }
                sum-=arr[d-1];
                i=d-2;
                while(i>=1){
                    if((arr[i+1]<=sum) ){
                       break;
                    }
                    sum-=arr[i];
                    i--;
                }
                if(i<1)
                    printf("NO\n");
                else
                    printf("YES\n");
            }
        }


    }
    return 0;
}
