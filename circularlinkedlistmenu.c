#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start=NULL;

//Functions
void traverse(struct node *);
struct node *create_ll(struct node *);
struct node *insert_end(struct node *);
struct node *insert_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_beg(struct node *);
void search(struct node *);

int main()
{
    int ch;
    int n,i=0;
    printf("select the no of times the operations must be performed\n");
    scanf("%d",&n);
    
   for(i=1;i<=n;i++)
   {
        printf("Choose the operation to be performed in a linked list\n");
        printf("1.Create a linked list\n");
        printf("2.Insert at the beg\n");
        printf("3.Insert at the end\n");
        printf("4.Delete at the beg\n");
        printf("5.Delete at the end\n");
        printf("6.Search\n");
        printf("7.Display\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            start=create_ll(start);
            break;
            case 2:
            start=insert_beg(start);
            break;
            case 3:
            start=insert_end(start);
            break;
            case 4:
            start=delete_beg(start);
            break;
            case 5:
            start=delete_end(start);
            break;
            case 6:
            search(start);
            break; 
            case 7:
            traverse(start);
            break;
            default:printf("Invalid input.\n");
            break;
        }
   }
    return 0;
}

void traverse(struct node *start)
{
    struct node *ptr;
    ptr=start;
    while(ptr->next!=start)
    {
        printf("The output is:%d\n",ptr->data);
        ptr=ptr->next;
    }
    printf("The output is:%d\n",ptr->data);
}

struct node *create_ll(struct node *start)
{
    int val;
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&val);
    new_node->data=val;
    start=new_node;
    new_node->next=start;
    return start;
    
}

struct node *insert_end(struct node *start)
{
    int val;
    struct node *new_node,*ptr;
    ptr=start;
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&val);
    new_node->data=val;
    while(ptr->next!=start)
    {
        ptr=ptr->next;
    }
    ptr->next=new_node;
    new_node->next=start;
    return start;
}

struct node *insert_beg(struct node *start)
{
    int val;
    struct node *new_node,*ptr;
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&val);
    new_node->data=val;
    
    
    ptr=start;
    while(ptr->next!=start)
    {
        ptr=ptr->next;
    }
    ptr->next=new_node;
    new_node->next=start;
    start=new_node;
    return start;
    
}

struct node *delete_end(struct node *start)
{
    struct node *preptr,*ptr;
    ptr=start;
    while(ptr->next!=start)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=ptr->next;
    free(ptr);
    return start;
}

struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr=start;
    while(ptr->next!=start)
    {
        ptr=ptr->next;
    }
    ptr->next=start->next;
    free(start);
    start=ptr->next;
    return start;
}

void search(struct node *start)
{
    int val;
    struct node *new_node,*ptr;
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&val);
    ptr=start;
    while(ptr->data!=val)
    {
        ptr=ptr->next;
    }
    if(ptr->data==val)
    {
        printf("The data was found.\n");
    }
    else 
    {
        printf("the data was not found\n");
    }
}
