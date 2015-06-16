#include<stdio.h>

int isLeap(int year);
int main(){
    int t,day,month,year,x=1,leap,y;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&day);
        scanf("%d",&month);
        scanf("%d",&year);
        leap=isLeap(year);
        int m=year%100;
        year=year/100;
        x=20;
        while(x<=year)
            x=4+x;
        --x;
        x=2*(x-year);
        //if(leap==0)
            {
            if(month==1)
                y=0;
            if(month==2)
                y=3;
            if(month==3)
                y=3;
            if(month==4)
                y=6;
            if(month==5)
                y=1;
            if(month==6)
                y=4;
            if(month==7)
                y=6;
            if(month==8)
                y=2;
            if(month==9)
                y=5;
            if(month==10)
                y=0;
            if(month==11)
                y=3;
            if(month==12)
                y=5;
        }
/*
        if(leap==1){
            if(month==1)
                y=0;
            if(month==2)
                y=3;
            if(month==3)
                y=4;
            if(month==4)
                y=0;
            if(month==5)
                y=2;
            if(month==6)
                y=5;
            if(month==7)
                y=0;
            if(month==8)
                y=3;
            if(month==9)
                y=6;
            if(month==10)
                y=1;
            if(month==11)
                y=4;
            if(month==12)
                y=6;
        }*/
        int formu;
        if(leap==0)
            formu=(x+((m+(m/4))%7)+y+(day%7));
        else{
            if(month==1 || month==2)
                formu=(x+((m+(m/4))%7)+y+(day%7)-1);
            else
                formu=(x+((m+(m/4))%7)+y+(day%7));
        }
        formu=formu%7;
        if(formu==0)
            printf("Sunday\n");
        if(formu==1)
            printf("Monday\n");
        if(formu==2)
            printf("Tuesday\n");
        if(formu==3)
            printf("Wednesday\n");
        if(formu==4)
            printf("Thursday\n");
        if(formu==5)
            printf("Friday\n");
        if(formu==6)
            printf("Saturday\n");
    }
    return 0;
}
int isLeap(int year){
    if(year%100==0){
        if((year/100)%4==0)
            return 1;
        else
            return 0;
    }
    else{
        if((year%100)%4==0)
            return 1;
        else
            return 0;
    }
    return 0;
}

