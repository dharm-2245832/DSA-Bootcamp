#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;
int adj[MAX][MAX], visited[MAX], n;

void enqueue(int v) {
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else {
        if (front == -1)
            front = 0;
        queue[++rear] = v;
    }
}

int dequeue() {
    int v;
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        v = queue[front++];
        if (front > rear)
            front = rear = -1;
        return v;
    }
}

void bfs(int start) {
    int i, v;
    enqueue(start);
    visited[start] = 1;
    printf("BFS Traversal: ");
    while (front != -1) {
        v = dequeue();
        printf("%d ", v);
        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int i, j, start;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Adjacency matrix entered:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    bfs(start);
    return 0;
}