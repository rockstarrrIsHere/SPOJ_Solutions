#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define MOD 1000000007

typedef struct matrix
{
    long long int mat[2][2][40];
}matrix;
matrix pow_2;
void mul(long long int n)
{
    if(n==1)
    {
        pow_2.mat[0][0][1]=1;
        pow_2.mat[0][1][1]=1;
        pow_2.mat[1][0][1]=1;
        pow_2.mat[1][1][1]=0;
        return;
    }
    long long int temp,i,j,k;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            temp=0;
            for(k=0;k<2;k++)
                temp=(temp+pow_2.mat[i][k][n-1]*pow_2.mat[k][j][n-1])%MOD;
            pow_2.mat[i][j][n]=temp;
        }
    }
}
void generate()
{
    long long int i;
    for(i=1;i<40;i++)
         mul(i);
 }
 long long cal(long long n)
 {
     if(n==0)
         return 0;
     if(n==1||n==2)
         return 1;
     n-=2;
     long long temp_mat[2][1],temp_ans[2][1];
     temp_mat[0][0]=1;
     temp_mat[1][0]=1;
     int var=1;
     while(n)
     {
         if(n%2)
         {
             temp_ans[0][0]=((temp_mat[0][0]*pow_2.mat[0][0][var])%MOD+(temp_mat[1][0]*pow_2.mat[0][1][var])%MOD)%MOD;
             temp_ans[1][0]=((temp_mat[0][0]*pow_2.mat[1][0][var])%MOD+(temp_mat[1][0]*pow_2.mat[1][1][var])%MOD)%MOD;
             temp_mat[0][0]=temp_ans[0][0];
             temp_mat[1][0]=temp_ans[1][0];
         }
         var++;
         n>>=1;
    }
    return temp_mat[0][0];
}
long long sum(int num)
{
    return (cal(num)-1)%MOD;
}
long long int fib_n_sum(int start,int end)
{
    long long ans=(sum(end+2)-sum(start+2))%MOD;
    return ans;
}
int main()
{
    generate();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int start,end;
        scanf("%d%d",&start,&end);
        long long sum=fib_n_sum(start-1,end);
        if(sum<0)
        {
            sum+=MOD;
            sum=sum%MOD;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
