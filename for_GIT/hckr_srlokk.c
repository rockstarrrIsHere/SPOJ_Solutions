#include<stdio.h>
#include<math.h>
#include<string.h>
#include<malloc.h>
int qksort(long int *p,int g,int h);
int min(long int x,long int y);
int max(long int x,long int y);
int max(long int x,long int y){
    if(x>=y)
        return x;
    else
        return y;
    return 0;
}
int min(long int x,long int y){
    if(x<=y)
        return x;
    else
        return y;
    return 0;
}
int main(){
    int n,i;
    long int a[100],j,X;
    long int N,M,m,d=0,d1=1000000000;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%ld",&a[i]);
    scanf("%ld",&M);
    scanf("%ld",&N);
    qksort(a,0,n-1);
    if(a[0]>=N)
      printf("%ld",M);
    if(a[n-1]<=M)
      printf("%ld",N);
    else{
        for(j=M;j<=N;j++){
          d1=1000000000;i=0;
          while(i<n){
            if(a[i]<=j)
               d1=min(d1,(j-a[i]));
            if(a[i]>j){
                m=a[i]-j;
                d1=min(d1,m);
                if(m>d1)
                    break;
            }

            i++;
          }
          if(d<d1){
            d=max(d,d1);
            X=j;
          }
        }
        printf("%ld",X);
    }


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
