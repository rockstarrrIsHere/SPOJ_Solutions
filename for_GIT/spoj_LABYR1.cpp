#include<bits/stdc++.h>
using namespace std;
int visited[1002][1002];
char arr[1002][1002];
pair<pair<int,int>,int> DFS(int i,int j);
int p[]={-1,1,0,0};
int q[]={0,0,-1,1};
int c,r;
int main(){
    int t,i,j;
    int ma=0;
    scanf("%d",&t);
    while(t--){
        int ma=0;
        scanf("%d %d",&c,&r);
        for(i=0;i<r;i++){
            char s[c+2];
            scanf("%s",arr[i]);

        }
        pair<pair<int,int>,int> x;
        pair<int,int> d;
        memset(visited,0,sizeof(visited));
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
            	if(arr[i][j]=='.'){
            		    x=DFS(i,j);
            		    ma=(ma,x.second);
            			d=x.first;
            			break;
            	}
           	}
           	if(j<c)
           		break;
        }
        int m;
        while(1){
        	memset(visited,0,sizeof(visited));
        	x=DFS(d.first,d.second);
        	if(ma<x.second){
        		d=x.first;
        		ma=x.second;
        	}
        	else
        		break;

        }

        printf("Maximum rope length is %d.\n",ma);
    }
	return 0;
}
pair<pair<int,int>,int> DFS(int i,int j){
    int d=0,m;
    pair<pair<int,int>,int>x;
    pair<int,int> y=make_pair(i,j);
    visited[i][j]=1;
    for(m=0;m<4;m++){
        if(i+p[m]>=0 && i+p[m]<r && j+q[m]>=0 && j+q[m]<c && !visited[i+p[m]][j+q[m]] && arr[i+p[m]][j+q[m]]!='#'){
            visited[i+p[m]][j+q[m]]=1;
            int e=d;
            x=DFS(i+p[m],j+q[m]);
            d=max(d,x.second+1);
        	if(e!=d){
        		y=x.first;
        	}
        }
    }
    return make_pair(y,d);
}






