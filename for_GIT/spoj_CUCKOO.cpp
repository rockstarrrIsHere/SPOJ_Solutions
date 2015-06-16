#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define pc(x) putchar_unlocked(x);
void scanint(int &x);
inline void writeInt (int n);
void scanint(int &x){
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
inline void writeInt (int n){
    int N = n, rev, count = 0;
    rev = N;
    if (N == 0) { pc('0'); pc('\n'); return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
    while (count--) pc('0');
}

int main() {
	// your code goes here
	int t,m,n,count,tt,x,y,xx,xxx,flag,i;
	scanint(t);
	while(t--){
		scanint(m);scanint(n);
		int arr[10001];i=0;
		int brr[10001][2];
		memset(arr,-1,sizeof(arr));
		count=1;flag=0;
		while(m--){
			scanf("%d %d",&x,&y);
			brr[i][0]=x;brr[i][1]=y;
			if(arr[x]==-1){
				arr[x]=i;
			}
			else{
				if(arr[y]==-1)
					arr[y]=i;
				else{
					count=1;
					while(count<=n){
						xxx=x;
						xx=arr[x];
						arr[x]=i;
						x=brr[xx][0];y=brr[xx][1];
						if(xxx==x){
							if(arr[y]==-1){
								arr[y]=xx;
								break;
							}
							tt=x;
							x=y;
							y=tt;
							count++;
						}
						else{
							if(arr[x]==-1){
								arr[x]=xx;
								break;
							}
							count++;
						}
						if(count>n)
							flag=1;
					}
					if(count>n)
						flag=1;
				}
			}
			i++;
		}
		if(!flag)
			printf("successful hashing\n");
		else
			printf("rehash necessary\n");
	}
	return 0;
}
