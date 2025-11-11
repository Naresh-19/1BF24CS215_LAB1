#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct data *next;
};

struct node *head=NULL;

void createList(int n){

    int i;int data;
    struct node *temp;
    for(i = 1; i<=n; i++){

        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data for %d node : ",i);
        scanf("%d", &data);
        newnode->data=data;
        newnode->next=NULL;

        if(head==0){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }

    }

}

void insertAtBeginning(int data){
    struct node *temp;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    if(head==NULL){
        head=temp=newnode;
        return;
    }
    else{
        newnode->next=head;
        head=newnode;

    }
    printf("Node inserted at beginning!\n");
}

void insertAtEnd(int data){
    struct node *temp;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    temp=head;

    if(head==NULL){
        head=temp=newnode;

    }


    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    //temp=newnode;

    printf("Node inserted at The End!\n");

}

void insertAtPosition(int pos, int data){
    struct node *temp;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    temp=head;
    if(pos==1){
        insertAtBeginning(data);
        return;
    }

    if(pos<1 || temp==NULL ){
        printf("Please enter a valid position!\n");
        return;
    }

    for(int i=1; i< pos-1 && temp!=NULL; i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next =newnode;

    printf("Node inserted at pos=%d with value =%d", pos, data);

}

void displayList(){
    struct node *temp;
    temp=head;

    printf("\nThe linked list : ");

    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");

}

void main(){
    int data,pos,n,choice;
    printf("Select operations on Linked List : \n");;
    printf("1. create a linked list\n");
    printf("2. insert a node at Beginning\n");
    printf("3. insert a node at The end\n");
    printf("4. insert a node at Given Postion\n");
    printf("5. Display the Liked list\n");
    printf("6. Exit\n");

    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                    printf("\nEnter the number of nodes: ");
                    scanf("%d",&n);
                    createList(n);
                    break;
            case 2:
                    printf("\nEnter the data: ");
                    scanf("%d",&data);
                    insertAtBeginning(data);
                    break;

            case 3:
                    printf("\nEnter the data: ");
                    scanf("%d",&data);
                    insertAtEnd(data);
                    break;
            case 4:
                    printf("\nEnter the position and data : ");
                    scanf("%d %d",&pos, &data);
                    insertAtPosition(pos, data);
                    break;
            case 5:
                    displayList();
                    break;
            case 6:
                    printf("Program ended successfully...\n");
                    exit(0);
            default:
                    printf("Invalid choice ! Try again\n");
                    break;

        }

    }
}

