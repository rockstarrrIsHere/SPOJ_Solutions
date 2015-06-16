#include<iostream>
#include<string>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<algorithm>
#include<stack>
#include<vector>
#include<list>
#include<bitset>
#include<string.h>
using namespace std;
#define MOD 1000000007
#define ULL int
#define MAX 200005
int A[MAX],n;
int arr[MAX];
int a,b,c;
int partitions(int low,int high);
int selection_algorithm(int left,int right,int kth);
long long int kucj();
long long int kucj(){
    A[1]=1;int t=0,i,d,j;
    long long int sum=1;
    A[2]=(a*A[1]+b*2+c);
        if(A[2]>=MOD){
            A[2]%=MOD;
            sum+=A[2];
            t=1;
        }
        for(i=3;i<=n;i++){
            if(t==0){
                if(i%2==0)
                	d=(a*A[(i)/2] + b*i + c);
                else
                	d=(a*A[(i-1)/2] + b*i + c);
                if(d>=MOD){
                    A[i]=d;
                    A[i]%=MOD;
                	sum+=A[i];
                	t=1;
                }
                else{
                	A[i]=d;
                	sum+=d;
                }
            }
            if(t==1)
            {
               /* for(j=1;j<=i-1;j++)
                    A[j]=arr[j];*/
                if(i%2==0)
                	d=selection_algorithm(1,i-1,(i)/2);
                else
                	d=selection_algorithm(1,i-1,(i-1)/2);
                A[i]= (a*d + b*i + c)%MOD;
            	sum+=A[i];
            }
        }
	return sum;
}
int main()
{
    int t,i;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d %d",&a,&b,&c,&n);
        long long int sum=0;
        sum=kucj();
        printf("%lld\n",sum);
    }
    return 0;
}
int partitions(int low,int high)
{
    int p=low,r=high,x,y,i=p-1;
    y=rand()%(p)+1+r-p;
    x=A[y];
    for(int j=p;j<=r-1;j++)
    {
        if (A[j]<=x)
        {

            i=i+1;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}
int selection_algorithm(int left,int right,int kth)
{
    for(;;)
    {
        int pivotIndex=partitions(left,right);          //Select the Pivot Between Left and Right
        int len=pivotIndex-left+1;

        if(kth==len)
            return A[pivotIndex];

        else if(kth<len)
            right=pivotIndex-1;

        else
        {
            kth=kth-len;
            left=pivotIndex+1;
        }
    }
}
