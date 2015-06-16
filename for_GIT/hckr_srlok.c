#include<stdio.h>
#include<math.h>
#include<string.h>
#include<malloc.h>
int qksort(int *p,int g,int h);
int arr[10][100000];
int main(){
    int t;
    int i;
    int s[10][1],j,k;
    long int sum1=0,sum2=0;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&s[i][0]);
        for(j=0;j<s[i][0];j++)
            scanf("%d",&arr[i][j]);
    }

    for(i=0;i<t;i++){
        qksort(arr[i],0,s[i][0]-1);
        n=arr[i][0];
        for(j=(n/2);j<=(3*n)/4;j++){
            sum1=0;
            sum2=0;

            if(j!=0){
                for(k=0;k<j;k++)
                    sum1=(sum1+arr[i][k]);
            }
            if(j!=(s[i][0]-1)){
                for(k=j+1;k<s[i][0];k++)
                    sum2=(sum2+arr[i][k]);
            }
            if(sum1==sum2){
                printf("YES\n");
                break;
            }
        }
        if(j==((3*n)/4+1))
            printf("NO\n");
    }
    return 0;
}
int qksort(int *p,int g,int h)
{
		 int i,j;
        int t;
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
