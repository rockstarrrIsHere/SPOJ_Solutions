#include<bits/stdc++.h>
using namespace std;
int trap[1005][1005];
void floodfill(int i,int j);
int r,c,cnt,last;
int arr[1005][1005];
int main(){
    int n,m,i,j;
    scanf("%d %d",&r,&c);
    cnt=0;last=0;
    for(i=0;i<r;i++){
        char s[1005];
        scanf("%s",s);
        for(j=0;j<c;j++){
            if(s[j]=='N') arr[i][j]=8;
            if(s[j]=='S') arr[i][j]=2;
            if(s[j]=='W') arr[i][j]=4;
            if(s[j]=='E') arr[i][j]=6;
        }
    }
    memset(trap,0,sizeof(trap));
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(!trap[i][j]){
				cnt=last+1;
				floodfill(i,j);
				if(cnt>last) last++;
			}
		}
	}

	printf("%d\n",last);
	return 0;
}
void floodfill(int i,int j){
	if(i>=0 && j>=0 && i<r && j<c){

	if(trap[i][j]){
		cnt=trap[i][j];
		return ;
	}
	trap[i][j]=cnt;
	if(arr[i][j]==4) floodfill(i,j-1);
	if(arr[i][j]==6) floodfill(i,j+1);
	if(arr[i][j]==8) floodfill(i-1,j);
	if(arr[i][j]==2) floodfill(i+1,j);
	trap[i][j]=cnt;
	}
}







