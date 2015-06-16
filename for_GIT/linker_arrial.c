#include<stdio.h>
#include<math.h>
#include<string.h>
#include<malloc.h>
struct node{
    int data;
    struct node *next;
};

int main(){
    struct node *p[40],*pp;
    int i=0;
    pp=(struct node* )malloc(sizeof(struct node));
    for(i=0;i<40;i++)
        p[i]=(struct node* )malloc(sizeof(struct node));
    for(i=0;i<39;i++){
        p[i]->next=p[i+1];
        p[i]->data=i;
    }
    p[i]->data=39;
    p[i]->next=NULL;
    pp=p[0];
    while(pp!=NULL){
        printf("%d ",pp->data);
        pp=pp->next;
    }
    return 0;
}
