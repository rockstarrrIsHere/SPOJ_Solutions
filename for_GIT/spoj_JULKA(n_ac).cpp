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
#include<string.h>
#define ULL unsigned long long int
using namespace std;
int main()
{
    char s[105],t[105],ch;
    char c[105],c1[105];
    int i,d,x,y,j,k,m,u,l;
    for(i=1;i<=10;i++){
        scanf("%s",s);
        scanf("%s",c);
        j=strlen(s);
        for(k=j-1;k>=j/2;k--)
            swap(s[j-1-k],s[k]);
        m=strlen(c);
        for(k=m-1;k>=m/2;k--)
            swap(c[m-1-k],c[k]);
        for(k=m;k<j;k++)
            c[k]='0';
        for(k=0;k<j;k++){
            x=s[k]-'0';
            y=c[k]-'0';
            if(x>=y){
                s[k]=(s[k]-c[k]);
                ch=(char)(((int)'0')+(x-y));
                s[k]=ch;
            }
            else{
                x+=10;
                x=x-y;
                ch=char(((int)'0') + (x) );
                s[k]=ch;
                u=k+1;
                while(u<j){
                    if(s[u]!='0'){
                        x=s[u]-'0';
                        ch=(char)(((int)'0') + x-1 );
                        s[u]=ch;
                        break;
                    }
                    ch=(char)(((int)'0')+9);
                    s[u]=ch;
                }

            }
        }
        j=strlen(s);y=0;
        for(k=j-1;k>=0;k--){
            x=s[k]-'0';
            if(y==0){
                y=x/2;
                ch=char(((int)'0')+y);
                s[k]=ch;
                y=x%2;
            }
            else{
                x=10+x;
                y=x/2;
                ch=char(((int)'0')+y);
                s[k]=ch;
                y=x%2;
            }
        }
        strcpy(t,s);
        j=strlen(s);
        d=0;
        for(k=0;k<j;k++){
            x=s[k]-'0';
            y=c[k]-'0';
            x=x+y+d;
            y=x%10;
            ch=char(((int)'0')+y);
            s[k]=ch;
            d=x/10;
        }
        if(d!=0 && k==j)
            s[j]=d;
        j=strlen(s);
        m=strlen(t);
        k=j-1;
        while(s[k]=='0' && k!=0)
            k--;
        for(l=k;l>=0;l--)
            printf("%c",s[l]);
        printf("\n");

        k=m-1;
        while(t[k]=='0' && k!=0)
            k--;
        for(l=k;l>=0;l--)
            printf("%c",t[l]);
        printf("\n");
    }
	return 0;
}

