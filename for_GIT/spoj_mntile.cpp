#include<bits/stdc++.h>
#define ff(x,y) for(x=1;x<=y;x++)
main(){int n,m,t,i,j,k,l;long double d,e,f,P=acos(-1);std::cin>>t;while(t--){std::cin>>n>>m;d=1;if(n%2&&m%2)d=0;k=ceil(m/2),l=ceil(n/2);ff(j,k)ff(i,l){e=cos((P*j)/(m+1));f=cos((P*i)/(n+1));d*=(4*e*e+4*f*f);}std::cout<<floor(d)<<'\n';}}
