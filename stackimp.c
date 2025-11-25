#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node* next;};
struct Node* top=NULL;

void push(){
    int x;
    struct Node* temp;
    printf("enter the data to be pushed:\n");
    scanf("%d",&x);
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=x;
    newnode->next=top;
    top=newnode;
    }
void pop(){
    struct Node* temp=top;
    if(top==NULL){
        printf("the stack is empty\n");
    }
    else{
        printf("the poped data is %d",temp->data);
        top=top->next;
        free(temp);
    }
}
void peek(){
    if(top==NULL){
        printf("its empty\n");
    }
    else{
        printf("the peek element is: %d\n",top->data);
    }
}
void display(){
    struct Node* temp=top;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");}
void main(){
    int data,pos,n,choice;
    printf("Select operations on Linked List : \n");;
    printf("1. push\n");
    printf("2. pop\n");
    printf("3. peek\n");
    printf("4. display\n");
    printf("5. Exit\n");

    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                    push();
                    break;
            case 2:
                    pop();
                    break;

            case 3:
                    peek();
                    break;
            case 4:
                    display();
                    break;
            case 5:
                    printf("Program ended successfully...\n");
                    exit(0);
            default:
                    printf("Invalid choice ! Try again\n");
                    break;

        }

    }
}
