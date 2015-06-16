#include<bits/stdc++.h>
using namespace std;
void DFS(int x,int y,int count);
int p[8]={-2,-2,-1,-1,1,1,2,2};
int q[8]={-1,1,-2,2,-2,2,1,-1};
int g[15][15];
int tot;
int main(){
    int total,i,j,n,x,y,cases=0;
    while(scanf("%d",&n) && n){
        cases++;
        tot=1;
        for(i=0;i<=10;i++)
            for(j=0;j<=10;j++)
                g[i][j]=0;
        total=0;
        for(i=0;i<n;i++){
            scanf("%d %d",&x,&y);
            total+=y;
            for(j=0;j<y;j++){
                g[i][x+j]=1;
            }
        }
        x=-1;y=-1;
        for(i=0;i<n;i++)
            for(j=0;j<10;j++)
                if(x==-1 && g[x][y]==1){
                    x=i;y=j;
                }
       g[x][y]=2;
       DFS(x,y,1);
       printf("Case %d, %d ",cases,total-tot);
       (total-tot)==1?printf("square can not be reached.\n"):printf("squares can not be reached.\n");
    }
    return 0;
}
void DFS(int x,int y,int count){
    int i;
    tot=max(tot,count);
    for(i=0;i<8;i++){
        if(x+p[i]>=0 && y+q[i]>=0 && x+p[i]<10 && y+q[i]<10 && g[x+p[i]][y+q[i]]==1){
            g[x+p[i]][y+q[i]]=2;
            DFS(x+p[i],y+q[i],count+1);
            g[x+p[i]][y+q[i]]=1;
        }
    }
}


