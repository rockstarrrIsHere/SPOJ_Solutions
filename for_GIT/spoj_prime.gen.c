#include<stdio.h>


int prime[10000],primes;

void init_primes(){
     static int isprime[32000];
     int i,j;
     for(i=2;i<32000;i++) isprime[i]=1;
     for(i=2;i*i < 32000;i++)if(isprime[i])
     {
         for(j=2*i;j<32000;j+=i) isprime[j]=0;
     }
     primes=0;
     for(i=2;i<32000;i++)
        if(isprime[i])
            prime[primes++]=i;
}

int seive[100001];

void find_seive(int lo, int hi){
   int i,j,p,n;
   for(i=0; i<=hi-lo; i++)
       seive[i]=1;
   for(j=0;;j++){
       p=prime[j];
       if(p*p > hi) break;
       n = (lo/p)*p;
       if(n<lo) n+=p;
       if(n==p) n+=p;
       for(;n<=hi; n+=p)
          seive[n-lo]=0;
   }
}

int main(){
    int cases,caseno,lower,upper,i;
    init_primes();
    scanf("%d",&cases);
    for(caseno=0;caseno<cases;caseno++){
        if(caseno) printf("\n");
        scanf("%d%d",&lower,&upper);
        if(lower<2) lower=2;
        find_seive(lower,upper);
        for(i=0; i<=upper-lower; i++)
            if(seive[i]){
               printf("%d\n",lower+i);
            }
    }
    return 0;
}
