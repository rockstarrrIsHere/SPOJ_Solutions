#include<stdio.h>
void main()
{
    int arr[200];
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
                for(m=0;m<=index;m++)
                {
                    pro=(j*arr[m]+carry);
                    arr[m]=pro%10;
                    carry=pro/10;

                }
                while(carry!=0){
                   arr[m++]=carry%10;
                   carry=carry/10;
                }
                index=m-1;
            }
        }
        for(i=index;i>=0;i--)
            printf("%d",arr[i]);
        if(x/100==1)
            printf("00");
        printf("\n");
    }

}
