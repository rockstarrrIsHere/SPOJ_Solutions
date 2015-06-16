#include<stdio.h>
#include<math.h>
#include<string.h>
#include<malloc.h>
int qksort(long int *p,int g,int h);
int main(){
    int t,i;
    int arr[100];
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&arr[i]);
    }
    qksort(arr,0,(t-1));
    for(i=0;i<t;i=i+2){
        if(arr[i]!=arr[i+1]){
            break;
        }
    }
    printf("%d",arr[i]);
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

