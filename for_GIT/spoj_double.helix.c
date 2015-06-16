#include<stdio.h>
long int arr[100][10001];
int main(){
		long int t1,t2,i=0,j;

		long int pp1=0;
		long int pp2=0;
		long int m;
		long int sum=0,k=1,n,sum1=0,sum2=0;


		arr[0][0]=1;
		while(arr[i][0]!=0){
				scanf("%ld",&arr[i][0]);
				if(arr[i][0]==0)
					break;
				if(arr[i][0]!=0){
						for(j=1;j<=arr[i][0];j++)
								scanf("%ld",&arr[i][j]);
						i++;
						scanf("%ld",&arr[i][0]);
						for(j=1;j<=arr[i][0];j++)
								scanf("%ld",&arr[i][j]);
						i++;
						arr[i][0]=1;
				}
		}
		i=0;

		while(arr[i][0]!=0){
				sum=0;
				t1=arr[i][0];
				t2=arr[i+1][0];
				pp1=0;
				pp2=0;
				k=1;
				for(j=1;j<=t1;j++){
						n=arr[i][j];
						sum1=0;
						sum2=0;
						if(k<=t2){
								while(1){
										if(n==arr[i+1][k]){

												for(m=(pp1+1);m<=j;m++)
														sum1=(sum1+arr[i][m]);

												for(m=(pp2+1);m<=k;m++)
														sum2=(sum2+arr[i+1][m]);
												if(sum1>=sum2)
														sum=(sum+sum1);
												else
														sum=(sum+sum2);
												pp1=j;
												pp2=k;
												break;
										}
										if(n<arr[i+1][k]){
												break;
										}
										k++;
										if(k>t2)
												break;
								}
						}

				}
				sum1=0;
				sum2=0;
				if((pp1<t1) || (pp2<t2)){
					for(m=(pp1+1);m<=t1;m++)
						sum1=(sum1+arr[i][m]);
					for(m=(pp2+1);m<=t2;m++)
					sum2=(sum2+arr[i+1][m]);
					if(sum1>=sum2)
						sum=(sum+sum1);
					else
						sum=(sum+sum2);
				}
				printf("%ld\n",sum);
				i=i+2;
		}

		return 0;
}
