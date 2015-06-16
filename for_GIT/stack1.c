#include<stdio.h>
#include<malloc.h>
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
    head=NULL;
    printf("%d",IsEmpty(head));
    free(head);
}
int IsEmpty(Stack head)
{
    return head==NULL;
}
