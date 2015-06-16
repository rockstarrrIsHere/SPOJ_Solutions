#include<stdio.h>
struct node
{
    int index;
    int data;
    struct node *next;
};
typedef struct node* Stack;
int main()
{
    Stack head=(Stack )malloc(sizeof(struct node));
    head->next=NULL;
    printf("%d",IsEmpty(head));
}
int IsEmpty(Stack head)
{
    return head->next!=NULL;
}
