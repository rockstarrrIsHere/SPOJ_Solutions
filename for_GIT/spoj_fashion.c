#include<stdio.h>
#include<math.h>
#include<string.h>
#include<malloc.h>
int qksort(long int *p,int g,int h);
long int men[1000][1000];
long int women[1000][1000];
int main(){
    int t,n,j;
    long int sum=0,i;
    int nn[1000][1];

    scanf("%d",&t);
    i=0;
    for(i=0;i<t;i++){
        scanf("%d",&nn[i][0]);
        n=nn[i][0];
        for(j=0;j<n;j++)
            scanf("%ld",&men[i][j]);
        for(j=0;j<n;j++)
            scanf("%ld",&women[i][j]);

    }
    i=0;
    while(i<t){
        n=nn[i][0];sum=0;
        qksort(men[i],0,n-1);
        qksort(women[i],0,n-1);
        for(j=0;j<n;j++){
            sum=(sum+men[i][j]*women[i][j]);
        }
        printf("%ld\n",sum);
        i++;
    }
    return 0;
}
int qksort(long int *p,int g,int h)
{
		 int i,j;
            long int t,key;
		 if(g==h)
				return 0;
		 i=g;j=h;
		 key=p[h];
		 while(1)
		 {

				 while(i!=(h+1))
				 {
						if(i==h)
                            break;
						if(p[i]>=key)
								break;
						i++;
				 }


				while(j!=(g-1))
				{
						if(j==g)
                            break;
						if(p[j]<=key)
								break;
						j--;
				}

        if(i>=j)
            break;
             if((i<=h) && (j>=g)){
        t=p[i];
        p[i]=p[j];
        p[j]=t;
                  i++;
        j--;
         }




    }
    if(i==j){
    qksort(p,g,j-1);
    qksort(p,i,h);
    }
    if(i>j){
        qksort(p,g,j);
    qksort(p,i,h);

    }

    return 0;
}


