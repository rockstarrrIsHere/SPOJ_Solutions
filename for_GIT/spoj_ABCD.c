#include<stdio.h>
#include<math.h>
#include<string.h>
#include<malloc.h>

char arr[2][100002];

int main(){
    long int n,i,na=0,nb=0,nc=0,nd=0,j=0,mm=0;
    long int narr[4];
    char s[]={'A','B','C','D','0'};
    char c,cm;
    int x;
    for(i=0;i<4;i++)
        narr[i]=0;
    scanf("%ld",&n);
    scanf("%s",arr[0]);
    for(i=0;i<2*n;i++){
        c=arr[0][i];
        if(c=='A')
            narr[0]++;
        if(c=='B')
            narr[1]++;
        if(c=='C')
            narr[2]++;
        if(c=='D')
            narr[3]++;
    }
    if((narr[0]==n) || (narr[1]==n) || (narr[2]==n) || (narr[3]==n) ){
        for(mm=0;mm<4;mm++){
            if(narr[mm]==n){
                if(narr[0]==n)
                    cm='A';
                if(narr[1]==n)
                    cm='B';
                if(narr[2]==n)
                    cm='C';
                if(narr[3]==n)
                    cm='D';
                j=0;
                while(s[j]!='0'){
                    if(s[j]==cm){
                        while(s[j]!='0'){
                            s[j]=s[j+1];
                            j++;
                        }
                        break;
                    }
                    j++;
                }
            }
        }
    }


    c=arr[0][0];
    while(1){
    if(c!='A' && (narr[0]!=n))
    {
        arr[1][0]='A';
        narr[0]++;
        j=0;
        while(s[j]!='0'){
            if(s[j]=='A'){
                x=j;
                break;
            }
            j++;
        }
        break;
    }
    if(c!='B' && (narr[1]!=n))
    {
        arr[1][0]='B';
        narr[1]++;
        j=0;
        while(s[j]!='0'){
            if(s[j]=='B'){
                x=j;
                break;
            }
            j++;
        }
        break;
    }
    if(c!='C' && (narr[2]!=n))
    {
        arr[1][0]='C';
        narr[2]++;
        j=0;
        while(s[j]!='0'){
            if(s[j]=='C'){
                x=j;
                break;
            }
            j++;
        }
        break;
    }
    if(c!='D' && (narr[3]!=n))
    {
        arr[1][0]='D';
        narr[3]++;
        j=0;
        while(s[j]!='0'){
            if(s[j]=='D'){
                x=j;
                break;
            }
            j++;
        }
        break;
    }

    }


    if((narr[0]==n) || (narr[1]==n) || (narr[2]==n) || (narr[3]==n) ){
        for(mm=0;mm<4;mm++){
           if(narr[mm]==n){
            if(narr[0]==n)
                cm='A';
            if(narr[1]==n)
                cm='B';
            if(narr[2]==n)
                cm='C';
            if(narr[3]==n)
                cm='D';
            j=0;
            while(s[j]!='0'){
                if(s[j]==cm){
                while(s[j]!='0'){
                    s[j]=s[j+1];
                    j++;
                }
                break;
                }
                j++;
            }
          }
        }
      }


    x++;
    if(s[x]=='0')
        x=0;
    for(i=1;i<2*n;i++){
        c=arr[0][i];
        while(1){
            if(s[x]!=c)
            {
                arr[1][i]=s[x];
                if(s[x]=='A'){
                    narr[0]++;
                    cm='A';
                    if(narr[0]==n){
                        j=0;
                            while(s[j]!='0'){
                                if(s[j]==cm){
                                    while(s[j]!='0'){
                                        s[j]=s[j+1];
                                        j++;
                                    }
                                    break;
                                }
                                j++;
                            }
                    }
                }
                if(s[x]=='B'){
                    narr[1]++;
                    cm='B';
                    if(narr[1]==n){
                        j=0;
                            while(s[j]!='0'){
                                if(s[j]==cm){
                                    while(s[j]!='0'){
                                        s[j]=s[j+1];
                                        j++;
                                    }
                                    break;
                                }
                                j++;
                            }
                    }
                }
                if(s[x]=='C'){
                    narr[2]++;
                    cm='C';
                    if(narr[2]==n){
                        j=0;
                            while(s[j]!='0'){
                                if(s[j]==cm){
                                    while(s[j]!='0'){
                                        s[j]=s[j+1];
                                        j++;
                                    }
                                    break;
                                }
                                j++;
                            }
                    }
                }
                if(s[x]=='D'){
                    narr[3]++;
                    cm='D';
                    if(narr[3]==n){
                        j=0;
                            while(s[j]!='0'){
                                if(s[j]==cm){
                                    while(s[j]!='0'){
                                        s[j]=s[j+1];
                                        j++;
                                    }
                                    break;
                                }
                                j++;
                            }
                    }
                }
                break;
            }
            x++;
            if(s[x]=='0')
                x=0;
        }
        x++;
        if(s[x]=='0')
            x=0;
    }

    puts(arr[1]);
    return 0;
}
