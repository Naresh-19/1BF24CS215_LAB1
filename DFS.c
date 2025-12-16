#include <stdio.h>

int visited[50];
int graph[50][50];
int i, j, n;



int DFS(int x){
    visited[x]=1;
    for(int i=0;i<n;i++){
        if(graph[x][i]==1 && visited[i]==0){
            DFS(i);
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
    DFS(0);
    int connected=1;
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            connected=0;
            break;
        }
    }
    if(connected){
        printf("Graph is connected\n");
    }
    else{
        printf("Graph is Disconnected");
    }

    return 0;
}
