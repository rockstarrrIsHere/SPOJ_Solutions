#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node *Ptr;
int main()
{
    int x=0;

    int n;
    Ptr p,head;
    head=(struct node* )malloc(sizeof(struct node));
    p=head;
    scanf("%d",&n);
    while(x!=(n))
    {
        p->next=(struct node* )malloc(sizeof(struct node));
        x++;
        p=p->next;
    }
    p=head;
    for(x=0;x<n;x++)
    {
        scanf("%d",&(p->data));
        p=p->next;
    }
    p=NULL;
    printf("%d",head->next->data);
    p=head;
    Ptr q=head;
    while(p!=NULL)
    {
        q=p->next;
        free(p);
        p=q;
    }
    return 0;

}
