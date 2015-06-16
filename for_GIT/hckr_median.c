#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int arr[100001];
int generateme(int j);
int qksort(int *p,long int g,long int h,long int pot);
int main()
{
    long int n,i,pot;
    int retval;
    scanf("%ld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    pot=n/2;

    retval=qksort(arr,0,n-1,pot);
    printf("%d",retval);
    return 0;
}

int generateme(int j)

{
    int randomnumber=0;
    srand(time(NULL));
    randomnumber = (rand() % j);
    return randomnumber;

}

int qksort(int *p,long int g,long int h,long int pot)
{
    long int i,j,k;
    int key,t,retval=0;

    k=(generateme(h-g+1)+g);

    key=p[k];
    if(g==h)
        return p[g];
    i=0;j=h;
    while(1)
    {
        while(i<=h)
        {
            if(p[i]>key)
                break;
            i++;
        }
        while(j>=g)
        {
            if(p[j]<=key)
                break;
            j--;
        }
        if(i>=j)
            break;
        else
        {
            t=p[i];
            p[i]=p[j];
            p[j]=t;
            i++;
            j--;
        }
    }
    /*if(i==j){
        k=(j-g);

        if(k==pot)
            return key;
        if(k>pot)
        {
         retval=qksort(arr,g,j,pot);
        }
        if(k<pot)
        {
            retval=qksort(arr,i,h,pot-k);
        }
    }*/
    //if(i>j){
        k=(j-g);

        if(k==pot)
            return key;
        if(k>pot)
        {
         retval=qksort(arr,g,j,pot);
        }
        if(k<pot)
        {
            retval=qksort(arr,j,h,pot-k);
        }

    //}
    return retval;
}
