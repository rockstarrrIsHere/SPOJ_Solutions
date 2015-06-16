#include<stdio.h>
using namespace std;
int main() {
    int t;
    int flag=0,n,i,x;
    scanf("%d",&t);
    while(t--){
        flag=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&x);
            if(x>i-1)
                flag=1;
        }
        if(flag)
            printf("NO\n");
        else
            printf("YES\n");
    }
	return 0;
}
