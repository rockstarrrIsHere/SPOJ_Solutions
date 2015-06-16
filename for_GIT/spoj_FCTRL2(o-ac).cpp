#include<stdio.h>
int main()
{
    int arr[200];
    int sum[200];
    int x,t,i,m,pro,carry,j,index;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&x);
        pro=1;
        arr[0]=1;
        index=0;
        for(j=1;j<=x;j++){
            m=0;
            if(j%100!=0){
                carry=0;
                while(m<=index){
                    pro=(j*arr[m]+carry);
                    sum[m]=pro%10;
                    carry=pro/10;
                    m++;
                }
                while(carry!=0){
                   sum[m]=carry%10;
                   carry=carry/10;
                   index=m;
                   m++;
               }
               for(i=0;i<=index;i++)
                 arr[i]=sum[i];
            }
        }
        for(i=index;i>=0;i--)
            printf("%d",arr[i]);
        if(x/100==1)
            printf("00");
        printf("\n");
    }
    return 0;
}
