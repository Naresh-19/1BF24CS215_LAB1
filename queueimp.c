#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node* next;};
struct Node* front=NULL;
struct Node* rear=NULL;

void enque(){
    int x;
    struct Node* temp;
    printf("enter the data to be pushed:\n");
    scanf("%d",&x);
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=x;
    newnode->next=NULL;
    if(rear==NULL){
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}

void deque(){
    struct Node* temp=front;
    if(front==NULL){
        printf("the queue is empty\n");
    }
    else{
        printf("the poped data is %d",temp->data);
        front=front->next;
        free(temp);
    }
}
void display(){
    struct Node* temp=front;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");}
void main(){
    int data,pos,n,choice;
    printf("Select operations on Linked List : \n");;
    printf("1. enque\n");
    printf("2. deque\n");
    printf("3. display\n");
    printf("4. Exit\n");

    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                    enque();
                    break;
            case 2:
                    deque();
                    break;
            case 3:
                    display();
                    break;
            case 4:
                    printf("Program ended successfully...\n");
                    exit(0);
            default:
                    printf("Invalid choice ! Try again\n");
                    break;

        }

    }
}
