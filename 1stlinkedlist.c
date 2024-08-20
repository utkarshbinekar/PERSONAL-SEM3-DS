#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};
struct node *start;
void main()
{   int num;
    struct node *p,*q;
    p=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data");
    scanf("%d",&num);
    p->data=num;
    p->next=NULL;

    q=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data");
    scanf("%d",&num);
    q->data=num;
    q->next=NULL;

    p->next=q;

}
