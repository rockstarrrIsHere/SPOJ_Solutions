#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int n,d=0,a,b;
    scanf("%d",&n);
    if(n%2==0){
        if(n%4==0){
            a=n/4;
            b=0;d=1;
        }
        else{
            a=(n-6)/4;
            b=1;
            if(a>=1)
                d=2;
            else
                d=1;
        }
        d=d+x(a,b,d);
        while(a>=3){
            if(a>=3){
                b=b+2;
                a=a-3;
                if(a>=b)
                    d=d+b+1;
                if(a<b)
                    d=d+a+1;
            }
        }
    }
    printf("%d",d);
    return 0;
}
int x(int a,int b,int d){

}
