#include <bits/stdc++.h>
using namespace std;
char s[10000000];
vector<int> v[100001];
map<string,int>::iterator mitr;
set<int>::iterator sitr;
int visited[100001];
pair<int,pair<int,int> > dp[3][100001];
int stt,ftt;
void DFS(int i);
int main() {
	int k,i,j,val,key,flag;
	int a,b,c;
	int test=1;
	int x;
	scanf("%d %d",&stt,&ftt);
	while(1){
        map<string,int> m;
		set<int> st;
		val=1;k=0;
        while(1){
            gets(s);
            if(s[0]<97){
                m.clear();
                st.clear();
                for(j=0;j<100001;j++)
                    v[j].resize(0);
                break;
            }
            i=0;
            x=strlen(s);flag=0;
            while(i<x){
                char ss[1005];
                k=0;
                j=i;
                while(s[j]!=' ' && j<x){
                    ss[k++]=s[j++];
                }
                ss[k]='\0';
                if(m.find(ss)==m.end()){
                    if(!flag){
                        st.insert(val);
                        key=val;
                        flag=1;
                        m.insert(make_pair(ss,val));
                        val++;
                    }
                    else{
                        m.insert(make_pair(ss,val));
                        v[key].push_back(val);
                        val++;
                    }
                }
                else if(m.find(ss)!=m.end()){
                    if(!flag){
                        st.erase(m[ss]);
                        flag=1;
                        key=val;
                    }
                    else{
                        v[key].push_back(m[ss]);
                    }
                }
                if(j==x)
                    break;
                i=j+1;
            }
            memset(dp,0,sizeof(dp));
            memset(visited,0,sizeof(visited));
            for(sitr=st.begin();sitr!=st.end();sitr++)
                    DFS(*sitr);
            a=b=c=0;
            for(sitr=st.begin();sitr!=st.end();sitr++){
                a=dp[2][*sitr].first;
                b=dp[2][*sitr].second.first;
                c=dp[2][*sitr].second.second;
            }
            printf("%d. %d %d %d",test,b,c,a);
            test++;
        }
        if(s[0]<97){
            i=0;
            x=strlen(s);
            flag=0;
            stt=ftt=0;
            while(i<x){
                j=i;
                while(s[j]!=' ' && j<x){
                    if(!flag)
                        stt=(stt*10+(s[j]-'0'));
                    else{
                        ftt=(ftt*10+(s[j]-'0'));
                    }
                }
                flag=1;
                if(j==x)
                    break;
                i=j+1;
            }
            if(stt==0 && ftt==0)
                break;
        }
	}
	return 0;
}
void DFS(int i){
    int j,k;
    visited[i]=1;
    k=v[i].size();
    if(k==0){
    	dp[0][i]=make_pair(stt,make_pair(1,0));
    	dp[1][i]=make_pair(ftt,make_pair(0,1));
    	dp[2][i]=make_pair(stt,make_pair(1,0));
    	return ;
    }
    dp[0][i]=make_pair(stt,make_pair(1,0));
    dp[1][i]=make_pair(ftt,make_pair(0,1));
    for(j=0;j<k;j++){
        if(!visited[v[i][j]]){
            DFS(v[i][j]);
        }
        dp[0][i].first+=dp[2][v[i][j]].first;
        dp[0][i].second.first+=dp[2][v[i][j]].second.first;
        dp[0][i].second.first+=dp[2][v[i][j]].second.second;
        if(dp[0][v[i][j]].first<=dp[1][v[i][j]].first){
           dp[1][i].first+=dp[0][v[i][j]].first-stt;
           dp[1][i].second.first+=dp[0][v[i][j]].second.first-1;
           dp[1][i].second.second+=dp[0][v[i][j]].second.second;
        }
        else{
           dp[1][i].first+=dp[1][v[i][j]].first;
           dp[1][i].second.first+=dp[1][v[i][j]].second.first;
           dp[1][i].second.second+=dp[1][v[i][j]].second.second;
        }
    }
    if(dp[0][i].first<dp[1][i].first){
        dp[2][i].first=dp[0][i].first;
        dp[2][i].second.first=dp[0][i].second.first;
        dp[2][i].second.second=dp[0][i].second.second;
    }
    if(dp[1][i].first<dp[0][i].first){
        dp[2][i].first=dp[1][i].first;
        dp[2][i].second.first=dp[1][i].second.first;
        dp[2][i].second.second=dp[1][i].second.second;
    }
    if(dp[0][i].first==dp[1][i].first){
        if(dp[0][i].second.first+dp[0][i].second.second<=dp[1][i].second.first+dp[1][i].second.second){
            dp[2][i].first=dp[0][i].first;
            dp[2][i].second.first=dp[0][i].second.first;
            dp[2][i].second.second=dp[0][i].second.second;
        }
        else{
            dp[2][i].first=dp[1][i].first;
            dp[2][i].second.first=dp[1][i].second.first;
            dp[2][i].second.second=dp[1][i].second.second;
        }
    }
}
