#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//unsigned long long int f(unsigned long long int n);
vector<unsigned long long int> arr;
int binar_search(int i,int j,unsigned long long int a);
int dp[100005];
int main() {
    int t,total,i,j,n,x;
    unsigned long long int xx;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector <long long> a (n);
        vector <bool> visited (n);
        for (int i = 0; i < n; i++) scanf ("%lld", &a[i]);
        sort (a.begin(), a.end());
        int right = n - 1, ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (visited[i]) continue;
            int hasBrokenLoop = 0;
            for (int j = right; j >= 0; j--) {
                if (visited[j]) continue;
                if (a[j] < a[i] / 2) {
                    right = j;
                    hasBrokenLoop = 1;
                    break;
                } else if (a[j] == a[i] / 2) {
                    ans ++;
                    visited[j] = 1;
                    right = j;
                    hasBrokenLoop = 1;
                    break;
                }
            }
            if (!hasBrokenLoop) {
                break;
            }
        }
        printf("%d\n",ans);
    }
	return 0;
}

