#include<stdio.h>
int qksort(long int *p,int g,int h);
int main()
{
    int n,k,i;
    long int sumc=0;
    long int s[100],ss[100];
    scanf("%d",&n);
    scanf("%d",&k);
    for(i=0;i<n;i++){
        scanf("%ld",&s[i]);
    }
    qksort(s,0,n);
    int j=0;
    for(i=(n-1);i>=0;i--){
        ss[j++]=s[i];
    }

    int y=0;int c=1;
    while(1)
    {
        for(i=y;i<(k+y);i++)
        {
            if(i>=n)
                break;
            sumc=sumc+ss[i];
        }
        if(i<n){
            c++;
            for(j=i;j<(i+k);j++){
                if(j>=n)
                    break;
                ss[j]=c*ss[j];
            }
            y=y+k;
        }
        if(i>=n)
            break;

    }
    printf("%ld",sumc);
    return 0;
}
int qksort(long int *p,int g,int h)
{
     int i,j;
    long int t;
     if(g==h)
        return 0;
     i=g;j=h;
     while(1)
     {
         if(i!=(h+1)){
         while(1)
         {
            if(p[i]>=p[h])
                break;
            i++;
         }
         }
         if(j!=(g-1)){
        while(1)
        {
            if(p[j]<=p[h])
                break;
            j--;
        }
         }
         if((i<=h) && (j>=g)){
        t=p[i];
        p[i]=p[j];
        p[j]=t;
         }


        if(i>=j)
            break;
        i++;
        j--;
    }
    qksort(p,g,j);
    qksort(p,i,h);
    return 0;
}
