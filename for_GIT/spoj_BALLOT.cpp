#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;
map<double,int> m;
int main() {
	while(1){
		int n,count,i;
		double x,y,z;
		scanf("%d %d",&n,&count);
		if(n==-1 && count==-1)
			break;
		for(i=1;i<=n;i++){
            scanf("%f",&x);
            m.insert(make_pair(x,1));
            --count;
		}
		while(1){
			map<double,int>::reverse_iterator itr;
			itr=m.rbegin();
            if(count==0){
                cout<<itr->first<<endl;
                break;
            }
			x=itr->first;
            y=itr->second;
            m.erase(itr);
            z=(double)x*y;
            x=(double)(z/(double)(y+1));--count;
            m.insert(make_pair(x,y+1));

		}
	}

	return 0;
}
