#include<bits/stdc++.h>
using namespace std;
int P,N,a,b;
void Find(int n);
int main(){
    int t,n,i,j;
    scanf("%d",&t);
    while(t--){
        N=0;
        scanf("%d %d %d %d",&a,&b,&P,&n);
        Find(n);
        printf("%d\n",N);
    }
    return 0;
}
void Find(int n){
	if(n==1){
		N=(N+a)%P;
	}
    else if(n==2){
		N=(N+b)%P;

    }
    else{
	    Find(n-2);
	    Find(n-1);
	}
}







