#include<stdio.h>
#include<math.h>
#include<string.h>
#include<malloc.h>
#define N 1000001
int arr[N];
int qksort(int *p,long int g,long int h,int key);
int main(){
    long int n,i;
    int retval=0;
    scanf("%ld",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);

    }


    retval=qksort(arr,0,n-1,arr[n-1]);
    printf("%d",retval);
    return 0;
}

int qksort(int *p,long int g,long int h,int key)
{
		 long int i,j,k;
         int t,retval=0;

		 i=g;j=h;
		 while(1)
		 {
				 if(i!=(h+1)){
				 while(1)
				 {
						if(p[i]>=key)
								break;
						i++;
				 }
				 }
				 if(j!=(g-1)){
				while(1)
				{
						if(p[j]<=key)
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

    if(j==((h+1)/2)){
        return key;
    }
    if(j>((h+1)/2)){

        retval=qksort(arr,0,h,arr[j]);
    }
    if(j<((h+1)/2)){

        while(k>=0){

        retval=qksort(arr,0,h,arr[j+1]);
    }

    return retval;
}

}
