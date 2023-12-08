#include <stdio.h>
#include <string.h>

#define INF 99999
#define MAX_VERTICES 10

struct Graph {
    int V;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

void floydWarshall(struct Graph* graph) {
    int dist[MAX_VERTICES][MAX_VERTICES];
    int i, j, k;

    // Copy adjacency matrix to dist
    for (i = 0; i < graph->V; i++) {
        for (j = 0; j < graph->V; j++) {
            dist[i][j] = graph->adjMatrix[i][j];
        }
    }

    // Applying Floyd-Warshall algorithm
    for (k = 0; k < graph->V; k++) {
        for (i = 0; i < graph->V; i++) {
            for (j = 0; j < graph->V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances in matrix shape
    printf("\nShortest distances between every pair of vertices:\n");
    printf("Vertex\t");
    for (i = 0; i < graph->V; i++) {
        printf("%d\t", i + 1);
    }
    printf("\n");
    for (i = 0; i < graph->V; i++) {
        printf("%d\t", i + 1);
        for (j = 0; j < graph->V; j++) {
            if (dist[i][j] == INF) {
                printf("inf\t");
            } else {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    struct Graph graph;
    int i, j;
    char input[10];

    printf("Enter the number of vertices in your graph: ");
    scanf("%d", &graph.V);

    printf("Enter 'inf' (case-sensitive) or '99999' to represent no or infinite direct edge between vertices.\n");

    // Input adjacency matrix
    for (i = 0; i < graph.V; i++) {
        for (j = 0; j < graph.V; j++) {
            printf("Enter the weight from vertex %d to vertex %d: ", i + 1, j + 1);
            scanf("%s", input);
            if (strcmp(input, "inf") == 0) {
                graph.adjMatrix[i][j] = INF;
            } else {
                sscanf(input,"%d", &graph.adjMatrix[i][j]);
            }
        }
    }

    // Apply Floyd-Warshall algorithm
    floydWarshall(&graph);

    return 0;
}
