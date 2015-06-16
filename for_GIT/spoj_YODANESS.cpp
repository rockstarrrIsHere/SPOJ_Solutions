#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ULL unsigned long long int
ULL mergesort(ULL arr[],ULL low,ULL high,ULL t[]);
int main()
{
    ULL n,test,ans,i;
    scanf("%llu",&test);
	while(test--){
        scanf("%llu",&n);
        map<string,int> m;
        ULL arr[n],t[n];
        for(i=0;i<n;i++){
        	char s[25];
        	scanf("%s",s);
        	m.insert(make_pair(s,i));
        }
        for(i=0;i<n;i++){
        	char s[25];
        	scanf("%s",s);
        	arr[i]=m[s];
        }
        /*for(i=0;i<n;i++)
            scanf("%llu",&arr[i]);*/
        ans=mergesort(arr,0,n-1,t);
        printf("%llu\n",ans);
	}
    return 0;
}
ULL mergesort(ULL arr[],ULL low,ULL high,ULL t[])
{
	ULL mid,i,l,r,j,k,count=0;
	if(low==high)
        return 0;
	mid=((low+high)/2);
	l=mergesort(arr,low,mid,t);
	r=mergesort(arr,mid+1,high,t);
    j=(mid+1);
	for(i=low;i<=mid;i++){
        while(j<=high){
            if(arr[i]>arr[j])
                j++;
            else
                break;
        }
        count+=j-(mid+1);
	}
	i=low;j=mid+1;k=0;
	while(i<=mid && j<=high){
       if(arr[i]<arr[j]){
           t[k]=arr[i];
           i++;k++;
       }
       else{
          t[k]=arr[j];
          j++;k++;
       }
    }
    while(i<=mid){
       t[k]=arr[i];
       i++;k++;
    }
    while(j<=high){
       t[k]=arr[j];
       j++;k++;
    }
    k=0;
    for(i=low;i<=high;i++)
        arr[i]=t[k++];
    return l+r+count;
}
