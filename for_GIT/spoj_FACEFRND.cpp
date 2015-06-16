#include<iostream>
#include<string>
#include<stdio.h>
#include<math.h>
#include<queue>
#include<algorithm>
#include<stack>
#include<vector>
#include<list>
#include<string.h>
using namespace std;
int main()
{
    int t,i,m,j,k;
    int arr[102];
    long long int d=0;
    vector<vector<string> > l1(105);
    vector<string> vv(105);
    int index=0;
    string s;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        l1[i].resize(105);
        cin>>s;
        l1[i][1]=s;
        scanf("%d",&arr[i]);
        for(j=2;j<(2+arr[i]);j++){
            cin>>s;
            l1[i][j]=s;
        }
    }
    for(i=1;i<=t;i++){
        for(k=2;k<(2+arr[i]);k++){
            s=l1[i][k];
            for(j=1;j<=t;j++){
            if(j!=i){
               if((l1[j][1].compare(s))==0)
                  break;

            }
          }
          if(j==(t+1)){
            for(j=1;j<=index;j++){
                if(vv[j]==s)
                    break;
            }
            if(j==(index+1)){
                d++;
                index++;
                vv[index]=s;
            }
          }
        }
    }
    printf("%lld",d);

    return 0;
}
