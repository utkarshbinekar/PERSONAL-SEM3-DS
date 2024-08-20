#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *start;
struct node *create_ll(struct node *);
struct node *insert_end(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_after(struct node *);
struct node *insert_before(struct node *);
struct node *delete_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_after(struct node *);
struct node *delete_thenode(struct node *);
void traverse(struct node *);
void search(struct node *);

int main()
{
    int ch, n, i;
    printf("Enter the no of operations to be performed:\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("Enter the operation you want to choose in the singly linked list\n1.Create a linked list.\n2.Insert at beginnin\n3.Insert at the end.\n4.Insert after the node.\n5.Insert before the node.\n6.Delete the first node.\n7.Delete the last node.\n8.Delete before the node. \n9.Delete after the node.\n10.Display all the nodes.\n11.Search a node.\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            start = create_ll(start);
            break;
        case 2:
            start = insert_beg(start);
            break;
        case 3:
            start = insert_end(start);
            break;
        case 4:
            start = insert_after(start);
            break;
        case 5:
            start = insert_before(start);
            break;
        case 6:
            start = delete_beg(start);
            break;
        case 7:
            start = delete_end(start);
            break;
        case 8:
            start = delete_thenode(start);
            break;
        case 9:
            start = delete_after(start);
            break;
        case 10:
            traverse(start);
            break;
        case 11:
            search(start);
            break;
        default:
            printf("Invalid Input.");
            break;
        }
    }

    return 0;
}

