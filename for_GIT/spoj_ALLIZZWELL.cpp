#include<bits/stdc++.h>
using namespace std;
char arr[105][105];
char s[]={"ALLIZZWELL"};
int q[]={-1,1,-1,0,1,-1,0,1};
int p[]={0,0,-1,-1,-1,1,1,1};
int n1,n2,visited[105][105];
int DFS(int j,int k,int i);
int main(){
    int i=1,n,j,k,d,e,pe;
    scanf("%d",&i);
    while(i--){
    scanf("%d %d",&n1,&n2);
    for(j=0;j<n1;j++){
        char ss[n2+1];
        scanf("%s",ss);
        for(k=0;k<n2;k++)
            arr[j][k]=ss[k];
    }
    /*for(j=0;j<n1;j++)
    	for(k=0;k<n2;k++)
    		printf("%c",arr[j][k]);*/
    memset(visited,0,sizeof(visited));
    d=0;
    for(j=0;j<n1;j++){
        for(k=0;k<n2;k++){
            if(arr[j][k]=='A' && DFS(j,k,0)==1){
                d=1;
                printf("YES\n");
                break;
            }
        }
        if(d)
        	break;
    }
    if(!d)
        printf("NO\n");
    }
    return 0;
}
int DFS(int j,int k,int i){
    int m;
    if(i==9){
        //printf("%d %d\n",j,k);
        return 1;
    }
    for(m=0;m<8;m++){
        if(j+p[m]>=0 && j+p[m]<n1 && k+q[m]>=0 && k+q[m]<n2 && !visited[j+p[m]][k+q[m]] && arr[j+p[m]][k+q[m]]==s[i+1]){
            //printf("%d %d\n",j+p[m],k+q[m]);
            visited[j][k]=visited[j+p[m]][k+q[m]]=1;
            if(DFS(j+p[m],k+q[m],i+1)==1)
                return 1;
            visited[j][k]=visited[j+p[m]][k+q[m]]=0;
        }
    }
    return 0;
}









