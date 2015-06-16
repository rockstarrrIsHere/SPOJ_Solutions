#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define B 137
int int_mod(int a);
int int_mod(int a){
    return (a+MOD)%MOD;
}
int main() {
    int t,i,j,hashval,hashrev,k,x;
    char ch;
    scanf("%d",&t);
    while(t--){
        char ss[100005];
        char s[100005];
        scanf("%s",ss);
        j=0;x=strlen(ss);k=0;
        while(1){
            ch=ss[j];j++;
            while(1){
                if(ss[j]==ch && j<x){
                    j++;
                }
                else
                    break;
            }
            s[k++]=ch;
            if(j>=x)
                break;
        }
        s[k]='\0';j=0;
        //printf("%s\n",s);
        char r[100005];
        for(i=k-1;i>=0;i--)
            r[j++]=s[i];
        r[j]='\0';
        hashval=0;hashrev=0;
        for(i=0;i<k;i++){
            hashval=int_mod(hashval*B+(s[i]-96));
            hashrev=int_mod(hashrev*B+(r[i]-96));
        }
        if(hashval==hashrev)
            printf("YES\n");
        else
            printf("NO\n");
    }
	return 0;
}
