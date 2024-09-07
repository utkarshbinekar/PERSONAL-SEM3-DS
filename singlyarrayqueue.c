#include<stdio.h>
#define Max 5
int que[Max];
int f=-1;
int r=-1;

void insert();
void delete();
void display();

void main(){
    int ch;
    do{
        printf("ENTER THE CHOICE\n1.Insert\n2.Delete\n3.Display\n4.Stop\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:insert();
            break;
            case 2:delete();
            break;
            case 3:display();
            break;
            case 4:printf("Program Ended\n");
            break;
            default:printf("Invalid input\n");
        }
    }while(ch!=4);
    
}


void insert(){
    if(r==Max-1){
        printf("Queue overflow\n");
    }
    else{
        if(r==-1&&f==-1){
            r=f=0;
        }
        else{
            r++;
        }
        printf("Enter the data\n");
        scanf("%d",&que[r]);
    }
}
void delete(){
    if(r==-1 && f==-1){
        printf("Queue underflow\n");
    }
    else{
        printf("The deleted element is %d\n",que[f]);
        if(r==f){
            r=f=-1;
        }
        else{
            f++;
        }
    }
}
void display(){
    if(r==-1 && f==-1){
        printf("Queue underflow\n");
    }
    else{
        for(int i=f;i<=r;i++){
            printf("Data: %d\n",que[i]);
        }
    }
}