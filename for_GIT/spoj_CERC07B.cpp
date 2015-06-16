#include <bits/stdc++.h>
using namespace std;
int r,c;
int arr[18][18];
int solve(vector<int> v);
int main() {
    int i,j,m,ans;
	while(1){
        scanf("%d %d",&r,&c);
        if(r==0 && c==0)
            break;
        memset(arr,0,sizeof(arr));
        for(i=0;i<r;i++){
            char s[20];
            scanf("%s",s);
            for(j=0;j<c;j++){
                if(s[j]=='X')
                    arr[i][j]=1;
            }
        }
        ans=INT_MAX;
        m=1<<c;
        for(i=0;i<m;i++){
            vector<int> v;
            for(j=0;j<c;j++)
                if(i&(1<<j))
                    v.push_back(j);
            ans=min(ans,solve(v));
        	/*int k=v.size();
        	for()*/
        }
        if(ans<INT_MAX)
            printf("You have to tap %d tiles.\n",ans);
        else
            printf("Damaged billboard.\n");
	}
	return 0;
}
int solve(vector<int> v){
    int i,j,k,ans,flag;
    int temp[r+1][c+1];
    memset(temp,0,sizeof(temp));
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            temp[i][j]=arr[i][j];
    k=v.size();
    ans=0;
    for(i=0;i<k;i++){
        temp[0][v[i]]=!temp[0][v[i]];ans++;
        if(v[i]>=1) temp[0][v[i]-1]=!temp[0][v[i]-1];
        if(v[i]+1<c) temp[0][v[i]+1]=!temp[0][v[i]+1];
        if(r>1) temp[1][v[i]]=!temp[1][v[i]];
    }
    for(i=1;i<r;i++){
        for(j=0;j<c;j++){
            if(temp[i-1][j]==1){
                temp[i][j]=!temp[i][j]; ans++;
                if(i>=1) temp[i-1][j]=0;
                if(j>=1) temp[i][j-1]=!temp[i][j-1];
                if(j+1<c) temp[i][j+1]=!temp[i][j+1];
                if(i+1<r) temp[i+1][j]=!temp[i+1][j];
            }
        }
    }
    flag=0;
    for(i=0;i<r && !flag;i++)
        for(j=0;j<c;j++)
            if(temp[i][j]){
                flag=1;
                break;
            }
    return flag==1?INT_MAX:ans;

}
