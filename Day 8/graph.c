#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Graph {
    int adjMatrix[MAX][MAX];
    int numVertices;
} Graph;

void initGraph(Graph* g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph* g, int src, int dest) {
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1; // For undirected graph
}

void removeEdge(Graph* g, int src, int dest) {
    g->adjMatrix[src][dest] = 0;
    g->adjMatrix[dest][src] = 0; // For undirected graph
}

void displayGraph(Graph* g) {
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}


int main() {
    Graph g;
    int choice, vertices, src, dest;

    while (1) {
        
        printf("Graph Operations Menu:\n");
        printf("1. Initialize Graph\n");
        printf("2. Add Edge\n");
        printf("3. Remove Edge\n");
        printf("4. Display Graph\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of vertices: ");
                scanf("%d", &vertices);
                initGraph(&g, vertices);
                break;
            case 2:
                printf("Enter source and destination vertices: ");
                scanf("%d %d", &src, &dest);
                addEdge(&g, src, dest);
                break;
            case 3:
                printf("Enter source and destination vertices: ");
                scanf("%d %d", &src, &dest);
                removeEdge(&g, src, dest);
                break;
            case 4:
                displayGraph(&g);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}