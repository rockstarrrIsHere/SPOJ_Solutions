// TLE using map
#include<bits/stdc++.h>
using namespace std;
int a[4005];
    int b[4005];
    int c[4005];
    int d[4005];
int main(){
    int t,i,j;
    int sum;

    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&a[i]);
        scanf("%d",&b[i]);
        scanf("%d",&c[i]);
        scanf("%d",&d[i]);
    }
    map<int,int> m1;
    for(i=0;i<t;i++){
        for(j=0;j<t;j++){
            sum=a[i]+b[j];
            if(m1.find(sum)!=m1.end())
                m1[sum]++;
            else
                m1[sum]=1;
        }
    }
    int cnt=0;
    for(i=0;i<t;i++){
    	for(j=0;j<t;j++){
            sum=-1*(c[i]+d[j]);
            if(m1.find(sum)!=m1.end())
                cnt+=m1[sum];
        }
    }
    printf("%d\n",cnt);
    return 0;
}


// tle vector
#include <ios>
#include <algorithm>
#include <vector>
#include<stdio.h>
using namespace std;

#define MAX 4000
#define pb(v) push_back(v)
#define ub(X,v) upper_bound(X.begin(),X.end(),v)
#define lb(X,v) lower_bound(X.begin(),X.end(),v)

int a[MAX][4];

int main() {
	int n, i, j, val, cnt = 0;
	vector <int> V;
	scanf("%d", &n);
	for(i=0; i<n; i++)
		scanf("%d %d %d %d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			V.pb(a[i][0]+a[j][1]);
	sort(V.begin(), V.end());
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			val = -(a[i][2]+a[j][3]);
			cnt += ub(V,val) - lb(V,val);
		}
	}
	printf("%d\n", cnt);
	return 0;
}



// AC without stl
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
#define MAX 10000001
using namespace std;

int N;
int S[101];
int itr,itr2;
int values[MAX];
int R[MAX];

//bsearch returning the count of number appears in array,if number doesn't exist returns 0
int bsearch(int val)
{
    int size=0,temp=0;
    int low=0,high=itr;
    int mid;
    int iterations=100;
    while(low<=high && iterations)
    {
         iterations--;
        mid=(low+high)/2;
        if(values[mid]==val)
        {
            temp=mid-1;
            while(mid<itr && values[mid]==val)
            {
               size++;
               mid++;
            }
            while(temp>=0 && values[temp]==val)
            {
                size++;
                temp--;
            }
            return size;
        }
        else if(values[mid]>val)
        high=mid-1;
        else
        low=mid+1;
    }
    return 0;
}
int main()
{

     int a[4000],b[4000],c[4000],d[40000],value,i,j,k;
     int temp,size2;
     long long int count=0;
     //FILE *fp=fopen("in.txt","r");
     scanf("%d",&N);
     for(i=0;i<N;i++)
     {
         scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
     }
      itr=0;
      //store all values of a*b+c in values array
     for(i=0;i<N;i++)
     {
         for(j=0;j<N;j++)
         {

                 values[itr++]=a[i]+b[j];//(a+b)
         }
     }
     //sort the values array
     sort(values,values+itr);
      itr2=0;
     for(i=0;i<N;i++)
     {
         for(j=0;j<N;j++)
         {
                R[itr2++]=(c[i]+d[j])*(-1);//-(d+c)
         }
     }
        sort(R,R+itr2);
        int size1;
        for(i=0;i<itr2;)
        {
             size1=0;
	         temp=R[i];
             while(R[i]==temp && i<itr2)
		     {
                   size1++;
                   i++;
		     }
            size2=bsearch(temp);
            count+=size1*size2;
	}
     printf("%lld\n",count);
     return 0;
}
