#include <stdio.h>
#define N 5

int stack[N];
int top = -1;

void push() {
    if (top == N - 1) {
        printf("Stack overflow\n");
    } else {
        int x;
        printf("Enter the number to be pushed: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

void pop() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        int item = stack[top];
        printf("The element %d is popped\n", item);
        top--;
    }
}

void peek() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("The peek element is: %d\n", stack[top]);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    
    while(1){
        int a;
        printf("Enter the choice: 1.Push 2.Pop 3.Peek 4.Display 5.exit\n");
        scanf("%d",&a);
        switch (a) {
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
            printf("exited");
            return 0;
        default:
            printf("Invalid choice\n");
            break;
    }

    }


    return 0;
}
