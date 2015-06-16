#include<stdio.h>
#include<malloc.h>
int qksort(long int *p,int g,int h);
long int min(long int i,long int j);
long int min(long int i,long int j)
{
    if(i>=j)
        return j;
    else
        return i;
    return 0;
}
int main()
{
    long int p[100000],d=0;
    int i,j,n,k;
    scanf("%d",&n);
    scanf("%d",&k);
    for(i=0;i<n;i++)
        scanf("%ld",&p[i]);
    qksort(p,0,n-1);
    d=100000000;
    for(i=0;i<n;i++)
    {
        if((k+i)<=n){
        for(j=i;j<(k+i);j++)
            {
                d=min((p[k+i-1]-p[i]),d);
            }
    }


    }
    printf("%ld",d);

    return 0;
}
int qksort(long int *p,int g,int h)
{
     int i,j,t;
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
         if(i>=j)
            break;

         if((i<=h) && (j>=g)){
        t=p[i];
        p[i]=p[j];
        p[j]=t;
         }


                i++;
        j--;
    }
    if(i==j){
    qksort(p,g,j-1);
    qksort(p,i,h);
    }
    else{
        qksort(p,g,j);
    qksort(p,i,h);
    }
    return 0;
}
