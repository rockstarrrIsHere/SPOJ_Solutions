#include<stdio.h>
#include<malloc.h>
int binary_search(int *p,int low,int high,int x);
int main()
{
    int t,n,k,i,j,d,x,b;
    int *p[2];
    scanf("%d",&t);
    scanf("%d",&n);
    scanf("%d",&k);
    for(i=0;i<2;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&p[i][j]);
    }
    b=(n-1);
    for(i=0;i<n;i++)
    {
        x=p[0][i];
        d=binary_search(p[1],0,b,(k-x));
        if(d!=0)
        {
            for(i=d;i<n;i++)
            {
                p[i]=p[i+1];
            }
            b--;
        }
        if(d==-1)
            break;
    }
    if(i==n)
        printf("YES");
    else
        printf("NO");

    return 0;
}
int binary_search(int *p,int low,int high,int x)
{
    if(low==high)
    {
        if(p[low]==x)
            return low;
        else
            return (-1);

    }
    int mid,a=-1;
    mid=(low+high)/2;
    if(x>p[mid])
    {
        a=binary_search(p,(mid+1),high,x);
    }
    if(x<p[mid])
    {
        a=binary_search(p,low,(mid-1),x);
    }
    if(x==p[mid])
    {

        return mid;
    }

    return a;


}

