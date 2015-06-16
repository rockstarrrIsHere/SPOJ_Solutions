#include<stdio.h>
//using namespace std;
int main()
{
   int arr[10000];
   int n,i;
   int d=-1,sum=0;
   while(1){
      scanf("%d",&n);
      if(n==-1)
        break;
      sum=0;
      for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        sum=(sum+arr[i]);
      }
      d=-1;
      if(sum%n==0){
      sum=(sum/n);
      d=0;
      for(i=--i;i>=0;i--){
        if(arr[i]>sum)
            d=(d+(arr[i]-sum));
      }
      }
      printf("%d\n",d);
   }
   return 0;
}
