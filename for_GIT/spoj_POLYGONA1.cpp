#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include<math.h>
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
    int t,n,i;
    scanf("%d",&t);
    while(t--){
        vector<pair<int,int> > v;
        queue<pair<int,int> > q;
        pair<int,int> o,x,y;
        int x1,x2,y1,y2;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d %d",&x1,&x2);
            v.push_back(make_pair(x1,x2));
        }
        sort(v.begin(),v.end());
        /*for(i=0;i<n;i++){
        	printf("%d %d\n",v[i].first,v[i].second);
        }*/
        arr[0][0]=v[0].first;
        arr[0][1]=v[0].second;
        for(i=1;i<n;i++){
            q.push(v[i]);
        }
        /*
        printf("%d %d\n",q.front().first,q.front().second);
        printf("%d\n",q.size());*/
        o=make_pair(arr[0][0],arr[0][1]);
        int k=1;
        while(1){
            if(q.size()>=2){
            	//printf("1\n");
                x=q.front();q.pop();
                y=q.front();
                x1=y.first-x.first;
                y1=y.second-x.second;
                x2=o.first-x.first;
                y2=o.second-x.second;
                if((x1*y2)<(x2*y1)){
                    q.push(x);
                }
                else{

                    arr[k][0]=x.first;
                    arr[k][1]=x.second;
                    k++;
                    o=x;

                	//printf("%d\n",q.size());
                	//printf("%d %d\n",q.front().first,q.front().second);
                }

            }

        	else{
        		arr[k][0]=q.front().first;
        		arr[k][1]=q.front().second;
        		q.pop();k++;
        		break;
        	}
        }


        arr[n][0]=arr[0][0];
        arr[n][1]=arr[0][1];

        /*for(i=0;i<n;i++){
        	printf("%d %d\n",arr[i][0],arr[i][1]);
        }*/


        double sum=0;
        for(i=0;i<n;i++){
            sum+=(arr[i][0]*arr[i+1][1]-arr[i+1][0]*arr[i][1]);

        }
        sum=0.5*abs(sum);
        printf("%0.1f\n",sum);
    }
    return 0;
}

