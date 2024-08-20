/*Utkarsh Binekar
SINGLY LINKED LIST MENU DRIVEN PROGRAM*/
// Libraries
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Struct
struct node
{
    int data;
    struct node *next;
};

// Universal variables
struct node *start = NULL;
struct node *preptr;
struct node *postptr;
struct node *ptr;
struct node *new_node;
int val;

// Functions
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

// Main
int main()
{
    int ch, n, i;
    printf("Enter the no of operations to be performed:\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("Enter the operation you want to choose in the singly linked list\n1.Create a linked list.\n2.Insert at beginnin\n3.Insert at the end.\n4.Insert after the node.\n5.Insert before the node.\n6.Delete the first node.\n7.Delete the last node.\n8.Delete the node. \n9.Delete after the node.\n10.Display all the nodes.\n11.Search a node.\n");
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

// ALL FUNCTIONS
struct node *create_ll(struct node *start)
{
    if (start != NULL)
    {
        start=insert_end(start);
    }
    else
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data:\n");
        scanf("%d", &val);
        new_node->data = val;
        new_node->next = NULL;
        start = new_node;
    }
    return start;
}

struct node *insert_end(struct node *start)
{
    ptr = start;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data:\n");
    scanf("%d", &val);
    new_node->data = val;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next = NULL;

    return start;
}

struct node *insert_beg(struct node *start)
{
    if (start == NULL)
    {
        start = create_ll(start);
    }
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data:\n");
    scanf("%d", &val);
    new_node->data = val;
    new_node->next = start;
    start = new_node;
    return start;
}

struct node *insert_after(struct node *start)
{
    int after;
    ptr = start;
    printf("Enter the data it should be inserted after\n");
    scanf("%d", &after);
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data:\n");
    scanf("%d", &val);
    while (ptr->data != after)
    {
        ptr = ptr->next;
        postptr = ptr->next;
    }
    new_node->data = val;
    new_node->next = postptr;
    ptr->next = new_node;
    return start;
}

struct node *insert_before(struct node *start)
{
    int before;
    ptr = start;
    printf("Enter the data it should be inserted before\n");
    scanf("%d", &before);
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data:\n");
    scanf("%d", &val);
    while (ptr->data != before)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    new_node->data = val;
    preptr->next = new_node;
    new_node->next = ptr;
    return start;
}

struct node *delete_end(struct node *start)
{
    ptr = start;
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    return start;
}

struct node *delete_beg(struct node *start)
{
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}

struct node *delete_after(struct node *start)
{
    int after;
    ptr = start;
    printf("Enter the data it should be deleted after\n");
    scanf("%d", &after);
    while (ptr->data != after)
    {
        ptr = ptr->next;
        postptr = ptr->next;
    }
    ptr->next = postptr->next;
    free(postptr);
    return start;
}

struct node *delete_thenode(struct node *start)
{
    int search;
    ptr = start;
    printf("Enter the data it should be deleted\n");
    scanf("%d", &search);
    while (ptr->data != search)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return start;
}

void traverse(struct node *start)
{
    ptr = start;
    while (ptr->next != NULL)
    {
        printf("The node value is %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("The node value is %d\n", ptr->data);
}

void search(struct node *start)
{
    ptr = start;
    printf("Enter the node to be searched\n");
    scanf("%d", &val);
    while (ptr->data != val)
    {
        ptr = ptr->next;
    }
    if (ptr->data == val)
    {
        printf("The data of the node was found");
    }
    else
        printf("The data of the node was not found");
}