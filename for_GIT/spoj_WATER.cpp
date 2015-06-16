#include<bits/stdc++.h>
using namespace std;
void DFS(int i,int j,int d);
int r,c;
int p[]={-1,0,0,1};
int q[]={0,-1,1,0};
int MAX=10001;
int visited[105][105];
int arr[105][105],water[105][105];
int main(){
    int t,i,j;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&r,&c);
        memset(water,0,sizeof(water));
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                water[i][j]=MAX;
                scanf("%d",&arr[i][j]);
            }
        }
        memset(visited,0,sizeof(visited));
        for(i=0;i<r;i++){
            if(!visited[i][0])
                DFS(i,0,arr[i][0]);
            if(!visited[i][c-1])
                DFS(i,c-1,arr[i][c-1]);
        }
        for(j=0;j<c;j++){
            if(!visited[0][j])
                DFS(0,j,arr[0][j]);
            if(!visited[r-1][j])
                DFS(r-1,j,arr[r-1][j]);
        }
        while(1){
            bool chk=false;
            for(i=0;i<r;i++){
                for(j=0;j<c;j++){
                    int x,y,m,mm=MAX;
                    if(!visited[i][j]){
                        for(m=0;m<4;m++){
                            x=i+p[m];
                            y=j+q[m];
                            if(x>=0 && y>=0 && x<r && y<c)
                                mm=min(mm,max(water[x][y],arr[x][y]));
                        }
                        if(mm<water[i][j]){
                            //visited[i][j]=1;
                            water[i][j]=mm;
                            chk=true;
                        }
                    }
                }
            }
            if(!chk)
                break;
        }
        int ans=0;
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                if(water[i][j]>arr[i][j])
                    ans+=water[i][j]-arr[i][j];
            }
        }
        printf("%d\n",ans);
    }
}
void DFS(int i,int j,int d){
    visited[i][j]=1;
    water[i][j]=arr[i][j];
    int m;
    for(m=0;m<4;m++){
        int x=i+p[m];
        int y=j+q[m];
        if(x>=0 && y>=0 && x<r && y<c && !visited[x][y] && arr[x][y]>=d){
            visited[x][y]=1;
            DFS(x,y,arr[x][y]);
        }
    }
}






