#include <bits/stdc++.h>
using namespace std;
int main() {
    int t,i,j,m,n;
    cin>>t;
    while(t--){
        cin>>m>>n;
        int x[m+5];
        int y[n+5];
        for(i=1;i<m;i++)
            cin>>x[i];
        for(i=1;i<n;i++)
            cin>>y[i];
        sort(x+1,x+m);
        sort(y+1,y+n);
        reverse(x+1,x+m);
        reverse(y+1,y+n);

        int result=0;
        int h=1,v=1;i=1;j=1;
        while(i<m && j<n){
            if(x[i]>y[j]){
                result+=x[i]*v;
                h++;i++;
            }
            else{
                result+=y[j]*h;
                v++;j++;
            }
        }
        int sum;
        sum=0;
        while(i<m){
            sum+=x[i];
            i++;
        }
        result+=sum*v;
        sum=0;
        while(j<n){
            sum+=y[j];
            j++;
        }
        result+=sum*h;
        cout<<result<<endl;
    }


	return 0;
}
