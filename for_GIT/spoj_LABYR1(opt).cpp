#include<bits/stdc++.h>
using namespace std;
int visited[1002][1002];
char arr[1002][1002];
void DFS(int i,int j,int n);
int p[]={-1,1,0,0};
int q[]={0,0,-1,1};
int c,r;
int mm;
pair<int,int> x;
int main(){
    int t,i,j;
    scanf("%d",&t);
    while(t--){
        int ma=0;
        scanf("%d %d",&c,&r);
        for(i=0;i<r;i++){
            char s[c+2];
            scanf("%s",arr[i]);

        }
        x=make_pair(0,0);
        //memset(visited,0,sizeof(visited));
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
            	if(arr[i][j]=='.'){
            		    x=make_pair(i,j);
            		    break;
            	}
        	}
        	if(j<c)
        		break;
        }
        memset(visited,0,sizeof(visited));
        if(arr[x.first][x.second]!='#'){

        while(1){

        	mm=0;
        	DFS(x.first,x.second,0);
        	if(ma<mm){
        		ma=mm;
        	}
        	else
        		break;

        }
        }

        printf("Maximum rope length is %d.\n",ma);
    }
	return 0;
}
void DFS(int i,int j,int n){
    int m;
    if(n>mm){
    	mm=n;
    	x.first=i;
    	x.second=j;
    }
    visited[i][j]=1;
    for(m=0;m<4;m++){
        if(i+p[m]>=0 && i+p[m]<r && j+q[m]>=0 && j+q[m]<c && !visited[i+p[m]][j+q[m]] && arr[i+p[m]][j+q[m]]!='#'){
            visited[i+p[m]][j+q[m]]=1;
            DFS(i+p[m],j+q[m],n+1);

    	}
    }
    visited[i][j]=0;
}






