#include <stdio.h>
#define Max 100
int que[Max];
int l = -1;
int r = -1;

void enqueue();
void dequeue();
void insert_right();
void insert_left();
void delete_right();
void delete_left();
void display();

int main()
{
    int ch;
    do
    {
        printf("Enter the choice\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            printf("Ended the program\n");
            break;
        default:
            printf("Invalid input\n");
        }
    } while (ch != 3);
    return 0;
}

void enqueue()
{
    int f;
    do
    {
        printf("Enter the choice\n");
        printf("1.Insert right\n");
        printf("2.Delete right\n");
        printf("3.Delete left\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        scanf("%d", &f);
        switch (f)
        {
        case 1:
            insert_right();
            break;
        case 2:
            delete_right();
            break;
        case 3:
            delete_left();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Enqueue ended\n");
            break;
        default:
            printf("Invalid input\n");
        }
    } while (f != 5);
}

void dequeue()
{
    int d;
    do
    {
        printf("Enter the choice\n");
        printf("1.Insert right\n");
        printf("2.Insert left\n");
        printf("3.Delete right\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        scanf("%d", &d);
        switch (d)
        {
        case 1:
            insert_right();
            break;
        case 2:
            insert_left();
            break;
        case 3:
            delete_right();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Dequeue ended\n");
            break;
        default:
            printf("Invalid input\n");
        }
    } while (d != 5);
}

void insert_right()
{
    if (l == 0 && r == Max - 1 || r == l - 1)
    {
        printf("Queue Overflow");
    }
    else
    {
        if (r == -1 && l == -1)
        {
            l = r = 0;
        }
        else if (r == Max - 1 && l != 0)
        {
            r = 0;
        }
        else
        {
            r++;
        }
        printf("Enter the data");
        scanf("%d", &que[r]);
    }
}

void insert_left()
{
    if (l == 0 && r == Max - 1 || r == l - 1)
    {
        printf("Queue Overflow");
    }
    else
    {
        if (r == -1 && l == -1)
        {
            l = r = Max - 1;
        }
        else if (r != Max - 1 && l == 0)
        {
            l = Max - 1;
        }
        else
        {
            l--;
        }
        printf("Enter the data");
        scanf("%d", &que[l]);
    }
}

void delete_right()
{
    if (r == -1 && l == -1)
    {
        printf("Queue Underflow");
    }
    else
    {
        printf("The deleted element is %d", que[l]);
        if (r == l)
        {
            r = l = -1;
        }
        else if (l == Max - 1)
        {
            l = 0;
        }
        else
        {
            l++;
        }
    }
}

void delete_left()
{
    if (r == -1 && l == -1)
    {
        printf("Queue Underflow");
    }
    else
    {
        printf("The deleted element is %d", que[r]);
        if (r == l)
        {
            r = l = -1;
        }
        else if (r == 0)
        {
            r = Max - 1;
        }
        else
        {
            r--;
        }
    }
}

void display()
{
    if (r == -1 && l == -1)
    {
        printf("Queue Underflow");
    }
    else
    {
        if (l <= r)
        {
            for (int i = l; i <= r; i++)
            {
                printf("%d ", que[i]);
            }
        }
        else
        {
            for (int i = l; i <= Max - 1; i++)
            {
                printf("%d ", que[i]);
            }
            for (int i = 0; i <= r; i++)
            {
                printf("%d ", que[i]);
            }
        }
    }
}