#include <iostream>
#include<stdio.h>
using namespace std;
int arr[10005];
unsigned long long int xx(int x,int y);
unsigned long long int H;
int main() {
	int i,j;
	for(i=1;i<=10000;i++)
		arr[i]=i;
	for(i=2;i<=10000;i++){
		if(arr[i]==i){
			for(j=i;j<=10000;j=j+i){
				arr[j]=arr[j]-arr[j]/i;
			}
		}
	}
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		H=0;
	/*
	for( i=1;i<=n;i++){
	    	H=H+arr[i]*arr[i];
	    for( j=i+1;j<=n;j++){

                    H=H+2*arr[i]*arr[j];

          }

	}*/

	xx(1,n);
	printf("%llu\n",H);
	}
	return 0;
}
unsigned long long int xx(int x,int y){
	unsigned long long int sum,d1,d2;
	if(x==y){
		H=H+arr[x]*arr[x];
		return arr[x];
	}
	d1=xx(x,(x+y)/2);d2=xx((x+y)/2+1,y);
	H=H+2*d1*d2;
	sum=d1+d2;
	return sum;
}
