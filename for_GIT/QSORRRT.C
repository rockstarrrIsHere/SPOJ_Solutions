#include<stdio.h>
int qksort(long int *p,int g,int h);
int main()
{
    int n,k,i;
    long int sumc=0;
    long int s[100],ss[100];
    scanf("%d",&n);
   // scanf("%d",&k);
    for(i=0;i<n;i++){
        scanf("%ld",&s[i]);
    }
    qksort(s,0,n-1);
    for(i=0;i<n;i++)
        printf("%ld",s[i]);
    int j=0;
    /*for(i=(n-1);i>=0;i--){
        ss[j++]=s[i];
    }

    int y=0;int c=1;
    while(1)
    {
        for(i=y;i<(k+y);i++)
        {
            if(i>=n)
                break;
            sumc=sumc+ss[i];
        }
        if(i<n){
            c++;
            for(j=i;j<(i+k);j++){
                if(j>=n)
                    break;
                ss[j]=c*ss[j];
            }
            y=y+k;
        }
        if(i>=n)
            break;

    }
    printf("%ld",sumc);*/
    return 0;
}
int qksort(long int *p,int g,int h)
{
		 int i,j;
            long int t,key;
		 if(g==h)
				return 0;
		 i=g;j=h;
		 key=p[h];
		 while(1)
		 {

				 while(i!=(h+1))
				 {
						if(i==h)
                            break;
						if(p[i]>=key)
								break;
						i++;
				 }


				while(j!=(g-1))
				{
						if(j==g)
                            break;
						if(p[j]<=key)
								break;
						j--;
				}

        if(i>=j)
            break;
             if((i<=h) && (j>=g)){
        t=p[i];
        p[i]=p[j];
        p[j]=t;
                  i++;
        j--;
         }




    }
    if(i==j){
    qksort(p,g,j-1);
    qksort(p,i,h);
    }
    if(i>j){
        qksort(p,g,j);
    qksort(p,i,h);

    }

    return 0;
}
