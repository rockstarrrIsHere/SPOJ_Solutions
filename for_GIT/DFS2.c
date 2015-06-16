#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<algorithm>
#include<stack>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<string.h>
using namespace std;
int n;
bool arr[10002][10002]={false};
bool brr[10002]={false};
pair<int,int> DFS(int i);
int main()
{
    int x,j,i,a,b,d;
    pair<int,int> pi;
    scanf("%d",&n);
    for(i=1;i<n;i++){
    	scanf("%d %d",&a,&b);
    	arr[a][b]=true;
    	arr[b][a]=true;
    }
    d=0;
   	pi=DFS(1);
   	for(j=1;j<=n;j++)
   		brr[j]=false;
   	d=DFS(pi.first).second;
	printf("%d\n",d);
    return 0;
}
pair<int,int> DFS(int i){
	pair<int,int> p,q;
	int mm,x=0,flag=0,j,y,k,xx;
	brr[i]=true;
	for(j=1;j<=n;j++){
		if(arr[i][j]==true && brr[j]==false){
			brr[j]=true;q=DFS(j);
			mm=q.first;
			y=q.second;
			if((y+1)>x){
				p.first=mm;
				p.second=y+1;
				x=y+1;
			}
			flag=1;
		}
	}
	if(flag==0){
		return make_pair(i,0);
	}
	return p;
}
