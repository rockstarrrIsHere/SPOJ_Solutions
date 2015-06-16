#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int a,b,c,d1,d2;
    while(1){
        d1=0;d2=1;
        scanf("%d %d %d",&a,&b,&c);
        if(a==0 && b==0 && c==0)
            break;
        d1=b-a;d2=c-b;
        if(d1==d2)
            printf("AP %d\n",d1+c);
        else
            printf("GP %d\n",(b/a)*c);

    }
    return 0;
}
