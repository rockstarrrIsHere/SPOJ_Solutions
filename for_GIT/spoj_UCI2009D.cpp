#include<bits/stdc++.h>
using namespace std;
#define chkf(x,y) flag[x][y]==0
#define setf(x,y) flag[x][y]=flag[y][x]=1
#define clrf(x,y) flag[x][y]=flag[y][x]=0
int tot,n;
char arr[25][25];
int mark[25][25];
void xx(int r,int c,int count);
int main(){
    int t,i,j;
    scanf("%d",&t);
    while(t--){
        tot=0;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)
                scanf("%c",&arr[i][j]);
        }
        memset(mark,0,sizeof(mark));
        xx(0,0,1);
        printf("%d\n",tot);
    }
    return 0;
}
void xx(int r,int c,int count){
    if(r==n){
        return ;
    }
    if(c>=n){
        c=0;
        r++;
    }
    if(count>=8){
        tot++;
        count=1;
        return ;
    }
    if(!mark[r][c]){
        if(arr[r][c+1]=='X' && !mark[r][c+1]){
            mark[r][c+1]=1;
            xx(r,c+1,count+1);
            mark[r][c+1]=0;
        }
        if(arr[r][c-1]=='X' && !mark[r][c-1]){
            mark[r][c-1]=1;
            xx(r,c-1,count+1);
            mark[r][c-1]=0;
        }
        if(arr[r+1][c]=='X' && !mark[r+1][c]){
            mark[r+1][c]=1;
            xx(r+1,c,count+1);
            mark[r+1][c]=0;
        }
        if(arr[r-1][c]=='X' && !mark[r-1][c]){
            mark[r-1][c]=1;
            xx(r-1,c,count+1);
            mark[r-1][c]=0;
        }
    }
    else{
        xx(r,c+1,1);
    }
}




