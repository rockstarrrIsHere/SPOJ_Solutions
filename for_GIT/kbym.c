#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node *Ptr;
Ptr FindMe(Ptr p10,int x);
int main()
{
    Ptr p=(int* )malloc(sizeof(struct node));
    Ptr q=(int* )malloc(sizeof(struct node));
    p->next=q;
    q->next=NULL;
    p->data=10;
    p->next->data=20;
    int x=20;
    int a;
    printf("%u\n",a=FindMe(p,x));
    printf("%u",q);
    return 0;
}
Ptr FindMe(Ptr p10,int x)
{
    while(p10!=NULL)
    {
        if(p10->data==x)
            return p10;
        else
            p10=p10->next;
    }
}

