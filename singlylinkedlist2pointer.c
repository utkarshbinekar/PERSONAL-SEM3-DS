#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;
struct node *new = NULL;

void create();
void insertbeg();
void insertend();
void insertsp();
void deletebeg();
void deleteend();
void deletesp();
void display();

int main()
{
    int ch;
    do
    {
        printf("Enter the choice\n");
        printf("1.Create\n");
        printf("2.Insert beginning\n");
        printf("3.Insert end\n");
        printf("4.Insert at specific position\n");
        printf("5.Delete beginning\n");
        printf("6.Delete end\n");
        printf("7.Delete at specific position\n");
        printf("8.Display\n");
        printf("9.Stop\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            insertbeg();
            break;
        case 3:
            insertend();
            break;
        case 4:
            insertsp();
            break;
        case 5:
            deletebeg();
            break;
        case 6:
            deleteend();
            break;
        case 7:
            deletesp();
            break;
        case 8:
            display();
            break;
        case 9:
            printf("Program Ended\n");
            break;
        }
    } while (ch != 9);
    return 0;
}

void create()
{
    int ch;
    do
    {
        printf("Enter the choice\n1.Create\n2.Stop\n");
        scanf("%d", &ch);
        if (ch == 1)
        {
            new = (struct node *)malloc(sizeof(struct node));
            printf("Enter the value\n");
            scanf("%d", &(new->val));
            new->next = NULL;
            if (!head)
            {
                head = new;
                tail = new;
            }
            else
            {
                tail->next = new;
                tail = new;
            }
        }
    } while (ch != 2);
}

void insertbeg()
{
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value\n");
    scanf("%d", &(new->val));
    new->next = NULL;
    if (!head)
    {
        head = new;
        tail = new;
    }
    else
    {
        new->next = head;
        head = new;
    }
}

void insertend()
{
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value\n");
    scanf("%d", &(new->val));
    new->next = NULL;
    if (!head)
    {
        head = new;
        tail = new;
    }
    else
    {
        tail->next = new;
        tail = new;
    }
}

void insertsp()
{
    if (!head)
    {
        printf("No list is present\n");
    }
    else
    {
        struct node *temp = head;
        int count = 1, pos, i;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        printf("Enter the position\n");
        scanf("%d", &pos);
        if (pos == 1)
        {
            insertbeg();
        }
        else if (pos == count + 1)
        {
            insertend();
        }
        else if (pos > count + 1)
        {
            printf("Out of bound\n");
        }
        else
        {
            new = (struct node *)malloc(sizeof(struct node));
            printf("Enter the value\n");
            scanf("%d", &(new->val));
            new->next = NULL;
            temp = head;
            struct node *temp2 = head;
            for (i = 1; i <= count - 1; i++)
            {
                temp2 = temp;
                temp = temp->next;
            }
            temp2->next = new;
            new->next = temp;
        }
    }
}

void deletebeg()
{
    if (!head)
    {
        printf("No list is present\n");
    }
    else if (head == tail)
    {
        free(head);
        head = NULL;
        tail = NULL;
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
}

void deleteend()
{
    if (!head)
    {
        printf("No list is present\n");
    }
    else if (head == tail)
    {
        free(head);
        head = NULL;
        tail = NULL;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        free(tail);
        tail = temp;
    }
}

void deletesp()
{
    if (!head)
    {
        printf("No list is present\n");
    }
    else
    {
        struct node *temp = head;
        int count = 1, pos, i;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        printf("Enter the position\n");
        scanf("%d", &pos);
        if (pos == 1)
        {
            deletebeg();
        }
        else if (pos == count)
        {
            deleteend();
        }
        else if (pos > count)
        {
            printf("Out of bound\n");
        }
        else
        {
            temp = head;
            struct node *temp2 = head;
            for (i = 1; i <= count - 1; i++)
            {
                temp2 = temp;
                temp = temp->next;
            }
            temp2->next = temp->next;
            free(temp);
        }
    }
}

void display()
{
    if (!head)
    {
        printf("No list is present \n");
    }
    else
    {
        struct node *temp = head;
        while (temp != NULL)
        {
            printf("Data: %d\n", temp->val);
            temp = temp->next;
        }
    }
}
