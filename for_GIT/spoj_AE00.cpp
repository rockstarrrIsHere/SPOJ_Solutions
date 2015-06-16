#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    long long int n,i=2,sum,j;

		scanf("%ld",&n);
		sum=n;
		while(i*i<=n){
				j=i;
				while((i*j)<=n){
						sum++;j++;
				}
				i++;
		}
		printf("%ld\n",sum);

    return 0;
}
