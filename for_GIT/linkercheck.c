#include<stdio.h>
#include<string.h>
#include<malloc.h>
struct node{
	int data;
	struct node* next;
};
int main()
{
	struct node **p,*pp;
	int qe,i;
	pp=(struct node* )malloc(sizeof(struct node));
    for(i=0;i<50;i++){
        p[i]=(struct node* )malloc(1*sizeof(struct node));
        p[i+1]=(p[i]->next);
        (p[i]->data)=i;
    }
	p[i]=NULL;
	i=0;
	pp=p[0];
	while(pp!=NULL){
        qe=pp->data;
        pp->data=pp->next->data;
        pp->next->data=qe;
        pp=pp->next->next;
	}
	pp=p[0];
	while(pp!=NULL){
        printf("%d ",pp->data);
        pp=pp->next;
	}

	return 0;
}
