#include<bits/stdc++.h>
using namespace std;
#define chkf(x,y) flag[x][y]==0
#define setf(x,y) flag[x][y]=flag[y][x]=1
#define clrf(x,y) flag[x][y]=flag[y][x]=0
int tot;
int arr[10][10];
int flag[10][10];
int mark[10][10];
void count(int i,int j);
int main(){
    int t,i,j;
    scanf("%d",&t);
    while(t--){
        for(i=0;i<7;i++)
            for(j=0;j<8;j++)
                scanf("%d",&arr[i][j]);
        tot=0;
        memset(flag,0,sizeof(flag));
        memset(mark,0,sizeof(mark));
        count(0,0);
        printf("%d\n",tot);
    }
    return 0;
}
void count(int i,int j){
    if(j>=8){
         j=0;
         i++;
    }
    if(i>=7){
        tot++;
        return ;
    }
    if(mark[i][j]) count(i,j+1);
    else{
        if(i+1<7 && chkf(arr[i][j],arr[i+1][j]) && !mark[i+1][j] && !mark[i][j]){
            setf(arr[i][j],arr[i+1][j]);
            mark[i][j]=mark[i+1][j]=1;
            count(i,j+1);
            clrf(arr[i][j],arr[i+1][j]);
            mark[i][j]=mark[i+1][j]=0;
        }
        if(i-1>-1 && chkf(arr[i][j],arr[i-1][j]) && !mark[i-1][j] && !mark[i][j]){
            setf(arr[i][j],arr[i-1][j]);
            mark[i][j]=mark[i-1][j]=1;
            count(i,j+1);
            clrf(arr[i][j],arr[i-1][j]);
            mark[i][j]=mark[i-1][j]=0;
        }
        if(j+1<8 && chkf(arr[i][j],arr[i][j+1]) && !mark[i][j+1] && !mark[i][j]){
            setf(arr[i][j],arr[i][j+1]);
            mark[i][j]=mark[i][j+1]=1;
            count(i,j+2);
            clrf(arr[i][j],arr[i][j+1]);
            mark[i][j]=mark[i][j+1]=0;
        }
        if(j-1>-1 && chkf(arr[i][j],arr[i][j-1]) && !mark[i][j-1] && !mark[i][j]){
            setf(arr[i][j],arr[i][j-1]);
            mark[i][j]=mark[i][j-1]=1;
            count(i,j+1);
            clrf(arr[i][j],arr[i][j-1]);
            mark[i][j]=mark[i][j-1]=0;
        }
    }
}




