#include<stdio.h>
#include<conio.h>
#include<math.h>

int main()
{
		int arr[9][9];int mat[9][9];
		int k=0,m=2,l=0,z=0,n=0,g=0,h=2,q=0;
		int i,j;

		printf("Enter the sudoke(unsolved)..\n\n");
		for(i=0;i<=8;i++)
		{
				for(j=0;j<=8;j++)
				{
						scanf("%d",&arr[i][j]);
				}
		}

		while(1)
		{
				for(j=k;j<=m;j++)
				{
						for(i=g;i<=h;i++)
						{
								if(arr[j][i]!=0)
								{
										mat[l][z]=arr[j][i];
										z++;
								}
						}



				}
				l++;z=0;n++;g=g+3;h=h+3;
				if(n>=3)
				{
						k=k+3;m=m+3;n=0;g=0;h=2;q++;
				}
				if(q==3)
						break;
		}





}

