#include<bits/stdc++.h>
using namespace std;
#define EPS 0.0000001
int main(){
    int k,r;
    float ans;
    int ansf;
    int m,i,j,ii,jj,kk,val,finall,cnt,n,x1,y11,ele;
    int coor[25][2];
    int soli[105][3];
    int visited[105];
    vector<int> v[105];
    int l;
    scanf("%d %d",&k,&r);
    scanf("%d",&m);
    for(i=0;i<m;i++)
        scanf("%d %d",&coor[i][0],&coor[i][1]);
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d %d %d",&soli[i][0],&soli[i][1],&soli[i][2]);
    memset(visited,0,sizeof(visited));
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            x1=(coor[i][0]-soli[j][0])*(coor[i][0]-soli[j][0]);
            y11=(coor[i][1]-soli[j][1])*(coor[i][1]-soli[j][1]);
            ans=sqrt(x1+y11);
            ansf=floor(ans);
            cnt=0;
            if(ansf<=r){
                if(ansf<r)
                    cnt=1;
                else
                  if(ans+EPS>r && ans-EPS<r)
                    cnt=1;
            }
            if(cnt){
                v[i].push_back(j);
            }
        }
    }
    finall=-1;
    jj=1<<(k)-1;ii=0;
    for(j=m-1;j>=m-k;j--)
        ii+=1<<j;
    for(i=jj;i<=ii;i++){
        ele=0;
        for(j=0;j<m;j++){
            if(i&(1<<j))
                ele++;
        }
        memset(visited,0,sizeof(visited));
        if(ele==k){
            val=0;
            for(j=0;j<m;j++){
                if(i&(1<<j)){
                	kk=v[j].size();
                	for(l=0;l<kk;l++){
                    	if(!visited[v[j][l]]){
                    		val+=soli[v[j][l]][2];
                    		visited[v[j][l]]=1;
                    	}
                	}
            	}
            }
        	finall=max(finall,val);
        }
    }
    printf("%d\n",finall);
    return 0;
}


