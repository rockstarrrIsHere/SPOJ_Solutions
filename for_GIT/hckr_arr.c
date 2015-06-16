#include<stdio.h>
#include<malloc.h>
int qksort(long long int *p,long long int g,long long int h,long long int d);
long long int p[1000];
int main()
{

    long long int i,j,n,k;
		scanf("%lld",&n);

		for(i=0;i<n;i++)
				scanf("%lld",&p[i]);
		qksort(p,0,n-1,p[0]);


		return 0;
}
int qksort(long long int *p,long long int g,long long int h,long long int d)
{
		 long long int i,j,t,m,k,x;
		 if(g==h)
				return 0;
		 i=g;j=i+1;

        while(1){
             if(j>h)
                 break;
             if(p[j]<d){
                    x=p[j];
                 for(m=j;m>i;m--){

                     p[m]=p[m-1];
                 }
                 p[i]=x;
                 i++;
             }

             j++;

         }

		if((i-1)>=g)
		qksort(p,g,i-1,p[g]);
		if((i+1)<=h)
		qksort(p,i+1,h,p[i+1]);
		for(k=g;k<=h;k++)
            printf("%lld",p[k]);
        printf("\n");
    return 0;
}
