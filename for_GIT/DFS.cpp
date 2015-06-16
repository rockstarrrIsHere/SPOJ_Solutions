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
stack<int> s;
int n;
bool arr[10002][10002]={false};
int brr[10002]={0};
int DFS(int i);
int main()
{
    int x,j,i,a,b,d;
    scanf("%d",&n);
    for(i=1;i<n;i++){
    	scanf("%d %d",&a,&b);
    	arr[a][b]=true;
    	arr[b][a]=true;
    }
    d=0;
   // for(i=1;i<=n;i++){
    	for(j=1;j<=n;j++)
    		brr[j]=0;
    	d=max(d,DFS(i));
    }
    printf("%d\n",d);
    return 0;
}
int DFS(int i){
	int x=0,flag=0,j;
	brr[i]=1;
	for(j=1;j<=n;j++){
		if(arr[i][j]==true && brr[j]==0){
			brr[j]=1;
			x=max(x,DFS(j)+1);
			flag=1;
		}
	}
	if(flag==0){
		return 0;
	}
	return x;
}
