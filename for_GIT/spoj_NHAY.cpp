#include<iostream>
#include<string>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<algorithm>
#include<stack>
#include<vector>
#include<list>
#include<map>
#include<bitset>
#include<string.h>
using namespace std;
using namespace std;
int main(){
    int t,i,j,x;char c;
    char s[15];
    char ss[15];
    scanf("%s",s);
    i=0;j=strlen(s)-1;
    while(i<j){
        if(s[i]==s[j]){
            i++;j--;
        }
        else{
            break;
        }
    }
    if(i<j){
        if(s[i]==s[j-1]){
            c=s[j];
        for(x=0;x<i;x++)
            ss[x]=s[x];
        ss[i]=c;
        for(x=i+1;x<strlen(s);x++)
            ss[x+1]=s[x];
        ss[strlen(s)+1]='\0';

        }
        if(s[j]==s[i+1]){
               c=s[i];
        for(x=0;x<=j;x++)
            ss[x]=s[x];
        ss[j+1]=c;
        for(x=j+1;x<strlen(s);x++)
            ss[x+1]=s[x];
        ss[strlen(s)+1]='\0';
        }
       i=0;j=strlen(s);
    while(i<j){
        if(ss[i]==ss[j]){
            i++;j--;
        }
        else{
            break;
        }
    }
        if(i>=j)
            printf("%s\n",ss);
        else{
            printf("NA\n");
        }
    }
    else{
        if(strlen(s)%2==0){
            for(i=0;i<(strlen(s)/2);i++){
                ss[i]=s[i];
            }
            ss[strlen(s)/2]='a';
            for(i=(strlen(s)/2);i<strlen(s);i++)
                ss[i+1]=s[i];
            ss[strlen(s)+1]='\0';
            printf("%s\n",ss);
        }
        else{
            for(i=0;i<=strlen(s)/2;i++)
                ss[i]=s[i];
            ss[strlen(s)/2+1]=s[strlen(s)/2];
            for(i=strlen(s)/2+1;i<strlen(s);i++)
                ss[i+1]=s[i];
            ss[strlen(s)+1]='\0';
            printf("%s\n",ss);
        }
    }
}



