#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insertNode(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void inorder(struct node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void display(struct node* root) {
    printf("BINARY SEARCH TREE: ");
    inorder(root);
    printf("\n");
}

int main() {
    struct node* root = NULL;
    int choice, n;

    printf("Select operations on TREE:\n");
    printf("1. insertNode\n");
    printf("2. display\n");
    printf("3. inorder\n");
    printf("4. postorder\n");
    printf("5. preorder\n");
    printf("6. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the number: ");
                scanf("%d", &n);
                root = insertNode(root, n);  // FIXED
                break;
            case 2:
                display(root);
                break;
            case 3:
                inorder(root);
                printf("\n");
                break;
            case 4:
                postorder(root);
                printf("\n");
                break;
            case 5:
                preorder(root);
                printf("\n");
                break;
            case 6:
                printf("Program ended successfully...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again\n");
                break;
        }
    }
    return 0;
}
