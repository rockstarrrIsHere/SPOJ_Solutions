#include<stdio.h>
#include<math.h>
#include<string.h>
#include<malloc.h>

char arr[2][100000];
int main(){
    long int n,i;
    int j;
    char ch;
    char s[4];
    char ss[4]={'A','B','C','D'};
    scanf("%ld",&n);
    scanf("%s",arr[0]);
    for(j=0;j<4;j++)
            s[j]='0';
    j=0;
    int p=0,m=2,k=0;
    s[0]=arr[0][0];
    s[1]=arr[0][1];
    for(i=0;i<4;i++){
        ch=ss[i];
        j=0;
        while(s[j]!='0'){
            if(ch==s[j]){
                break;
            }
            j++;
        }
        if(s[j]=='0'){
            arr[1][p++]=ch;
            s[m++]=ch;
        }
    }

    for(k=2;k<=(2*n-2);k=k+2){
        for(j=0;j<4;j++)
            s[j]='0';
         s[0]=arr[0][k];
         s[1]=arr[0][k+1];
         m=2;p=k;
        for(i=0;i<4;i++){
            ch=ss[i];
            j=0;
            while(s[j]!='0'){
                if(ch==s[j]){
                    break;
                }
                j++;
            }
            if(s[j]=='0'){
                if(arr[1][k-1]!=ch){
                    arr[1][p++]=ch;
                    s[m++]=ch;
                }
                if(arr[1][k-1]==ch){
                    arr[1][k+1]=ch;
                    s[m++]=ch;
                }
            }
        }
    }
    puts(arr[1]);
    return 0;
}
