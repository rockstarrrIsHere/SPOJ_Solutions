#include<cstdio>
#include<queue>
#include<stdio.h>
#include<string.h>
#include <string>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n,i,k;float total,totalx;
   	char s[7];
   	strcpy(s,"PASSED");
    string num;
    float score[5],t,m=0;
    float arr[6],d=0;
    int j;
    scanf("%d",&n);

    while(n--){
        totalx=0;strcpy(s,"PASSED");
        d=0;
        for(i=0;i<6;i++){
            scanf("%f",&arr[i]);
            d=d+arr[i];
        }
        for(i=0;i<=5;i++){
            for(j=0;j<5;j++){

                 cin>>num;
                /* if(num[0]=='a')
                    score[j]=0.0;
                 else*/
                 score[j]= atof(num.c_str());
            }
            for(j=0;j<=1;j++){
                for(k=j+1;k<=2;k++){
                    if(score[k]<score[j]){
                        t=score[k];
                        score[k]=score[j];
                        score[j]=t;
                    }
                }
            }
            m=0;
            m=score[1]+score[2];
            m=((45*m)/40.0);
            float g=(score[3]/2.0);
            m=m+g;
            if(score[4]<51)
                m=m+5;
            if(score[4]<61 && score[4]>=51)
                m=m+4;
            if(score[4]<71 && score[4]>=61)
                m=m+3;
            if(score[4]<81 && score[4]>=71)
                m=m+2;
            if(score[4]<91 && score[4]>=81)
                m=m+1;

            if(m>=91)
                total=10;
            if(m>=81 && m<91)
                total=9;
            if(m>=71 && m<81)
                total=8;
            if(m>=61 && m<71)
                total=7;
            if(m>50 && m<61)
                total=6;
            if(m==50)
                total=5;
            if(m<50){
                total=0;
                strcpy(s,"FAILED");
            }
            totalx=totalx+total*arr[i];
        }
        double gpa;
        gpa=totalx/d;

        printf("%s, %.2f\n",s,gpa);
    }
    return 0;
}

