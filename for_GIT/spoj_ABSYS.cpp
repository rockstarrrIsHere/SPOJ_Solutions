#include<iostream>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<math.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main()
{
    int t,x,y,z;
    char s1[20],s2[2],s3[20],s4[2],s5[20];
    scanf("%d",&t);
    while(t--){
        scanf("%s %s %s %s %s",s1,s2,s3,s4,s5);
        while(1){
            if(strchr(s1,'m')==NULL){
                x=atoi(s1);
                if(strchr(s3,'m')==NULL){
                    y=atoi(s3);
                    z=x+y;
                    break;
                }
                else{
                    z=atoi(s5);
                    y=z-x;
                    break;
                }
            }
            else{
                y=atoi(s3);
                z=atoi(s5);
                x=z-y;
                break;
            }
        }
        printf("%d",x);printf(" + ");
        printf("%d",y);printf(" = ");
        printf("%d\n",z);
    }
    return 0;
}
