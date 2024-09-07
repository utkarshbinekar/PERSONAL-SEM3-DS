#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *FRONT = NULL;
struct node *REAR = NULL;

void insert();
void delete();
void display();

int main() {
    int ch;
    do {
        printf("ENTER THE CHOICE\n1. Insert\n2. Delete\n3. Display\n4. Stop\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Program Ended\n");
                break;
            default:
                printf("Invalid input\n");
        }
    } while (ch != 4);
    
    return 0;
}

void insert() {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the Data\n");
    scanf("%d", &new_node->data);
    new_node->next = NULL;

    if (REAR == NULL) {
        FRONT = REAR = new_node;
    } else {
        REAR->next = new_node;
        REAR = new_node;
    }
}

void delete() {
    if (FRONT == NULL) {
        printf("Queue Underflow\n");
    } else {
        struct node *ptr = FRONT;
        printf("The deleted element is %d\n", FRONT->data);
        FRONT = FRONT->next;
        if (FRONT == NULL) {
            REAR = NULL;
        }
        free(ptr);
    }
}

void display() {
    if (FRONT == NULL) {
        printf("Queue is empty\n");
    } else {
        struct node *ptr = FRONT;
        while (ptr != NULL) {
            printf("Data: %d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}
