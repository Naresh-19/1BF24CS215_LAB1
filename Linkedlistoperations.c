#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
    };
struct Node* head=NULL;
struct Node* temp=NULL;
struct Node* head1=NULL;
void createList(int n){

    int i;int data;
    struct Node *temp;
    for(i = 1; i<=n; i++){

        struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
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
void sort(struct Node* head){
    struct Node* i;
    struct Node* j;
    int t;
    for(i=head;i->next!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(i->data > j->data){
                t=i->data;
                i->data=j->data;
                j->data=t;
            }
        }
    }

    }
void createList1(int n){

    int i;int data;
    struct Node *temp=head1;
    for(i = 1; i<=n; i++){

        struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
        printf("Enter the data for %d node : ",i);
        scanf("%d", &data);
        newnode->data=data;
        newnode->next=NULL;

        if(head1==0){
            head1=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }

    }
}
void display(){
    temp=head;
    while(temp!=NULL){
          printf("%d->",temp->data);
          temp=temp->next;}
    printf("NULL\n");
}
void reverse(struct Node* head){
    struct Node* prev=NULL;
    struct Node* next=NULL;
    struct Node* curr=head;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    while(prev!=NULL){
        printf("%d->",prev->data);
        prev=prev->next;
    }
    printf("NULL\n");
}
void concat(struct Node* head,struct Node* head1){
    struct Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head1;
}
void main(){
    int choice;int n;
    printf("Select operations on Linked List : \n");;
    printf("1. create a linked list\n");
    printf("2. create a linkedlist 1\n");
    printf("3. sort\n");
    printf("4. reverse");
    printf("5. concat\n");
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
                    printf("\nEnter the number of nodes: ");
                    scanf("%d",&n);
                    createList1(n);
                    break;

            case 3:
                    sort(head);
                    display();
                    break;
            case 4:
                    reverse(head);
                    break;
            case 5:
                    concat(head,head1);
                    display();
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
