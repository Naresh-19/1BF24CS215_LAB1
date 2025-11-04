#include<stdio.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;
void enqueue(int x){
    if(front==rear && front==-1){
        front=0;
        rear=0;
        queue[front]=x;
    }
    else if(front==(rear+1)%N){
        printf("Queue is Full\n");
    }
    else{
        rear=(rear+1)%N;
        queue[rear]=x;
    }
}
void dequeue(){
    if(front==rear && front==-1){
        printf("queue is empty\n");
    }
    else if(front==rear){
        printf("the poped element is :%d\n",queue[front]);
        front=-1;
        rear=-1;
    }
    else{
        printf("the poped element is : %d\n",queue[front]);
        front=(front+1)%N;
    }
    }
void display(){
    int i=front;
    while(i!=rear){
        printf("%d ",queue[i]);
        i=(i+1)%N;
    }
    printf("%d ",queue[i]);
}
int main(){
    int p;
    while(1){
        char choice;
        printf("enter the choice:a.enqueue b.dequeue c.display d.exit :\n");
        scanf(" %c",&choice);
        switch(choice){
            case('a'):
                printf("enter the number to be pushed: \n");
                scanf(" %d",&p);
                enqueue(p);
                break;
            case ('b'):
                dequeue();
                break;
            case ('c'):
                display();
                break;
            case ('d'):
                break;
                return 0;
            default:
                printf("invalid choice\n");
                break;
        }
    }
    return 0;
}
