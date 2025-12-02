#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node* prev;
    struct Node* next;
    int data;};
struct Node* head=NULL;
struct Node* temp=NULL;
void createDoublyLinkedlist(int n){
     for(int i=1;i<=n;i++){
        struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
        printf("enter the data:\n");
        scanf("%d",&newNode->data);
        newNode->prev=NULL;
        newNode->next=NULL;
        if(head==NULL){
            head=temp=newNode;
        }
        else{
            temp->next=newNode;
            newNode->prev=temp;
            temp=newNode;

        }
     }
}
void insertatbeginning(){
    int n;
    printf("enter the val:\n");
    scanf("%d",&n);
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=n;
    newNode->prev=NULL;
    newNode->next=NULL;
    if(head==NULL){
        head=temp=newNode;
    }
    else{
        newNode->next=head;
        head=newNode;
    }
     }
void deletethegivenval(){
    int n;
    printf("enter the number:\n");
    scanf("%d",&n);
    struct Node* curr=head;
    while(curr!=NULL && curr->data!=n){
         curr=curr->next;
    }
    if(curr==head){
        head=curr->next;
        if(head!=NULL){
            head->prev=NULL;
        }
        free(curr);
    }
    if(curr->next==NULL){
        curr->prev->next=NULL;
        free(curr);
    }
    else{
        curr->next->prev=curr->prev;
        curr->prev->next=curr->next;
        free(curr);
    }
}
void display(){
    struct Node* curr=head;
    while(curr!=NULL){
        printf("%d<=>",curr->data);
        curr=curr->next;
    }
    printf("NULL");
}
void insertatleftofnode(){
    int a;
    int b;
    printf("enter the node:\n");
    scanf("%d",&a);
    printf("enter the val:\n");
    scanf("%d",&b);
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=b;
    newNode->prev=NULL;
    newNode->next=NULL;
    struct Node* curr=head;
    while(curr!=NULL && curr->data!=a){
        curr=curr->next;
    }
    if(curr==head){
        insertatbeginning(b);
        return;
    }
    if(curr==NULL){
        printf("Node Not found\n");
    }
    else{
        curr->prev->next=newNode;
        curr->prev=newNode;
        newNode->prev=curr->prev;
        newNode->next=curr;
    }
}
void main(){
    int choice;int n;
    printf("Select operations on Linked List : \n");;
    printf("1. create a Doublylinked list\n");
    printf("2. insertatbeginning\n");
    printf("3. insertatleftofnode\n");
    printf("4. deletethegiven\n");
    printf("5. display\n");
    printf("6. Exit\n");

    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                    printf("\nEnter the number of nodes: ");
                    scanf("%d",&n);
                    createDoublyLinkedlist(n);
                    break;
            case 2:
                    insertatbeginning();
                    break;

            case 3:
                    insertatleftofnode();
                    break;
            case 4:
                    deletethegivenval();
                    break;
            case 5:
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
