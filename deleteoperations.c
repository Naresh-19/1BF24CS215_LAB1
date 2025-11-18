#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head=NULL;
struct Node* temp=NULL;
void createlinkedlist(int n){
    for(int i=1;i<=n;i++){
        struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ",i);
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }
}
void deleteatfront(){
    temp=head;
    if(head==NULL){
        printf("The  lInked lIst ids empty\n");
    }
    else{
        temp=head;
        head=head->next;
        printf("the deleted element is %d\n",temp->data);
        free(temp);
    }
}
void deleteatend(){
    struct Node* prev;
    temp=head;
    if(head==NULL){
        printf("The linked list id empty\n");
    }
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    printf("the deleted element ids %d \n",temp->data);
    free(temp);
}
void deletethegiven(int data){
    int x=data;
    struct Node* prev;
    temp=head;
    if(head->data==data){
        deleteatfront();
        return;
    }
    while(temp->data!=x && temp!=NULL){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("The value is not found\n");
        return;
    }
    else{
        printf("The deleted data is %d",temp->data);
    }
    prev->next=temp->next;
    free(temp);
}
void display(){
    temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}
void main(){
    int data,n,choice;
    printf("Select operations on Linked List : \n");
    printf("1. create a linked list\n");
    printf("2. delete at front\n");
    printf("3. delete at The end\n");
    printf("4. delete the given val\n");
    printf("5. Display the Liked list\n");
    printf("6. Exit\n");

    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                    printf("\nEnter the number of nodes: ");
                    scanf("%d",&n);
                    createlinkedlist(n);
                    break;
            case 2:
                    deleteatfront();
                    break;

            case 3:
                    deleteatend();
                    break;
            case 4:
                    printf("\nEnter the val : ");
                    scanf("%d", &data);
                    deletethegiven(data);
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
