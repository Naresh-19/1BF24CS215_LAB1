#include <stdio.h>

int visited[50];
int graph[50][50];
int queue[50];
int front = -1;
int rear = -1;
int i, j, n;

void enqueue(int x) {
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = x;
}

int dequeue() {
    int val = queue[front++];
    return val;
}

int isempty() {
    return (front == -1 || front > rear);
}

void BFS(int start) {
    enqueue(start);
    visited[start] = 1;

    while (!isempty()) {
        int p = dequeue();
        printf("%d ", p);

        for (i = 0; i < n; i++) {
            if (graph[p][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    char row[50];
    int start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        scanf("%s", row);
        for (j = 0; j < n; j++) {
            graph[i][j] = row[j] - '0';
        }
    }

    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter the start vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal of given graph is:\n");
    BFS(start);

    return 0;
}
