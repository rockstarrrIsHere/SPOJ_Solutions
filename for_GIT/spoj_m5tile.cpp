#include<bits/stdc++.h>
#define ff(x,y) for(x=1;x<=y;x++)
main(){int n,i,j,l;double d,e,f,P=acos(-1);n=0;while(n<=32){n+=2;l=ceil(n/2);d=1;ff(j,3)ff(i,l){e=cos(P*j/6);f=cos(P*i/(n+1));d*=4*(e*e+f*f);}std::cout<<d<<'\n';}}



  /* RUBY

  include Math;n=0;P=acos(-1);while n<=32;n+=2;d=1;l=(n/2).ceil;for j in 1..3;for i in 1..l;e=cos((P*j)/6);f=cos((P*i)/(n+1));d*=4*(e*e+f*f);end;end;puts d.floor;end;

 */


/*
#include<bits/stdc++.h>
main(){	int n,i,j,l;long double d,e,f,P=acos(-1);n=0;while(n<=32){n+=2;l=ceil(n/2);d=1;for(j=1;j<=3;j++)for(i=1;i<=l;i++){e=cos((P*j)/6);f=cos((P*i)/(n+1));d*=4*(e*e+f*f);}std::cout<<d<<'\n';}}
*/
