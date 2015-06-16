#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node *Ptr;
void FirSe(int x,int n);
int main()
{
    int x=4,n=0;
    FirSe(x,n);
    return 0;
}
void FirSe(int x,int n)
{
    int i=3,j;
    Ptr head,x2,p;
    Ptr pappu[10];
    p=pappu[0];
    p=(struct node* )malloc(sizeof(struct node));
    x2=(struct node* )malloc(sizeof(struct node));
    head=(struct node* )malloc(sizeof(struct node));
    if(n==5)
        return 0;
    head->data=2;
    p=head->next;

    while(i!=x)
    {

        for(j=2;j<i;j++)
        {
            if(i%j==0)
                break;
        }
        if(j==i)
        {
            p->data=i;
            p=p->next;
        }
        i++;
    }
    p=NULL;
    p=head;
    while(p!=NULL)
    {
        if(((p->data) + (x2->data)) == x)
            break;
        x2=x2->next;
        if(x2==NULL && p->next!=NULL)
        {
            p=p->next;
            x2=p->next;
        }

    }
      if(p==NULL)
            printf("%d",0);
      else
            printf("%d",1);
        n++;
        FirSe((x+2),n);

}
