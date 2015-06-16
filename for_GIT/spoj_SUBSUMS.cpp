#include <bits/stdc++.h>
using namespace std;
long long int arr[40];
//long long int vrr[20];
long long int brr[131075];
long long int crr[131075];
int main() {
	int n;
	long long int a,b,sum,x,k,i,j;
	unsigned long long int m,mm;
	scanf("%d %lld %lld",&n,&a,&b);
	for(i=0;i<n;i++)
        scanf("%lld",&arr[i]);
    m=1<<n/2;memset(brr,0,sizeof(brr));
	for(i=1;i<m;i++){
        sum=0;
        for(j=0;j<n/2;j++){
            if(i&(1<<j)){
                sum+=arr[j];
            }
        }
        brr[i]=sum;
	}
	memset(crr,0,sizeof(crr));k=0;
	//sort(brr,brr+m);
	map<long long int,unsigned long long int > ma;
	map<long long int,unsigned long long int >::iterator itr;
	for(i=1;i<m;i++){
		if(ma.find(brr[i])==ma.end()){
			ma.insert(make_pair(brr[i],1));
		}
		else{
			ma[brr[i]]++;
		}
	}
	mm=n%2==0?m:m+1;
	for(i=0;i<mm;i++){
        sum=0;
        for(j=n/2;j<n;j++){
            if(i&(1<<j)){
                sum+=arr[j];
            }
        }
        crr[i]=sum;
	}
	unsigned long long int cnt=0;
	for(i=a;i<=b;i++){
        for(j=0;j<mm;j++){
            x=crr[j];
            if(x==i){
            	cnt++;
            	if(ma.find(0)!=ma.end())
            		cnt+=ma[0];
            }
            else{
            	if(ma.find(i-x)!=ma.end()){
                	cnt+=ma[i-x];
            	}
            }
        }
	}
	printf("%llu\n",cnt);
	return 0;
}
