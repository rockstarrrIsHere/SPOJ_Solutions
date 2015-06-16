#include<iostream>
#include<string>
#include<math.h>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    int t,a;
    string s;
    int x,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d\n",&a);
        cin>>s;
        a=a%10;
        if(s[0]=='0')
            printf("1\n");
        else{
            x=s.size();
            if(x>=2)
              m=((int)(s[x-1]-'0')+(10*(int)(s[x-2]-'0')));
            if(x==1)
              m=(int)(s[0]-48);
            x=(m%4);
            if(x==0)
              m=pow(a,4);
            if(x!=0)
              m=pow(a,x);
            m=m%10;
            printf("%d\n",m%10);
            }
      }
    return 0;
}
