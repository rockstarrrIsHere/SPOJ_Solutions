#include<bits/stdc++.h>
using namespace std;
int x1,x2,yy1,y2,r,c;
int DFS(int i,int j,int n);
int visited[25][25];
int already[25][25];
char arr[25][25];
int p[]={-1,0,0,1};
int q[]={0,-1,1,0};
int main(){
    int t,i,j;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&r,&c);
        for(i=0;i<r;i++){
            scanf("%s",arr[i]);
        }
        /*for(i=0;i<r;i++){
        	for(j=0;j<c;j++){
        		printf("%d",arr[i][j]);
        	}
    		printf("\n");
    	}*/
    	memset(already,0,sizeof(already));
        int m=0;
        for(j=0;j<c;j++){
            if(arr[0][j]=='.' && !already[0][j]){
            	m++;
            	already[0][j]=1;
            }
            if(arr[r-1][j]=='.' && !already[r-1][j]){
            	already[r-1][j]=1;
            	m++;
            }
        }
        for(i=1;i<r-1;i++){
            if(arr[i][0]=='.' && !already[i][0]){
            	already[i][0]=1;
            	m++;
            }
            if(arr[i][c-1]=='.' && !already[i][c-1]){
            	already[i][c-1]=1;
            	m++;
            }
        }
        if(m==2){
        	int m=0;
            for(i=0;i<r;i++){
            	for(j=0;j<c;j++){
            		if(already[i][j] && m==0){
            			x1=i;yy1=j;
            			m++;
            		}
            		if(already[i][j] && m==1){
            			x2=i;y2=j;
            		}
            	}
            }
            memset(visited,0,sizeof(visited));
            if(DFS(x1,yy1,0))
                printf("valid\n");
            else{
                memset(visited,0,sizeof(visited));
                if(DFS(x2,y2,1))
                    printf("valid\n");
                else
                    printf("invalid\n");
            }
        }
        else
            printf("invalid\n");
    }

    return 0;
}
int DFS(int i,int j,int n){
    int m;
    if(n==1 && i==x1 && j==yy1){
        return 1;
    }
    if(n==0 && i==x2 && j==y2)
        return 1;
    visited[i][j]=1;
    for(m=0;m<4;m++){
        int x=i+p[m];
        int y=j+q[m];
        if(x>=0 && y>=0 && x<r && y<c && !visited[x][y] && arr[x][y]=='.'){
            if(DFS(x,y,n))
                return 1;
        }
    }
    return 0;
}






