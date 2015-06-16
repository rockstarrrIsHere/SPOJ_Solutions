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
#include<set>
#include<string.h>
using namespace std;
#define MOD 1000000007
#define ULL unsigned long long int
bitset<1000002> arr;
ULL b[1000002];
ULL brr[105];
set<ULL> st;
int main(){
    ULL t,n,i,k,j,p,count,x,l,l1;
    double x1;
    for(i=3;i<=1000001;i+=2)
        arr[i]=true;
    arr[0]=false;arr[1]=false;
    arr[2]=true;
	for(i=3;i<=1001;i+=2){
		if(arr[i]==true){
            for(j=i*i;j<=1000001;j=j+2*i){
				arr[j]=false;
            }
		}
	}
	b[0]=1;
	b[1]=2;k=2;
	for(i=3;i<=1000000;i+=2){
        if(arr[i]==true)
            b[k++]=i;
	}
	p=0;
	scanf("%llu",&t);
    while(t--){
        p++;
        scanf("%llu",&n);
        for(i=1;i<=n;i++)
            scanf("%llu",&brr[i]);
        for(j=1;j<=n;j++){
            x=brr[j];l=1;
            while(1){
                x1=sqrt(x);
                l1=ceil(x1);
                if(l>l1)
                    break;
                if(x%b[l]==0){
                    st.insert(b[l]);
                    while(x%b[l]==0)
                        x/=b[l];
                }
                l++;
            }
            if(x>1)
                st.insert(x);
        }
        set<ULL>::iterator itr;count=0;
        for(itr=st.begin();itr!=st.end();itr++)
            count++;
        printf("Case #%llu: %llu\n",p,count);
        for(itr=st.begin();itr!=st.end();itr++){
            printf("%llu\n",*itr);
        }
    }
    return 0;
}
