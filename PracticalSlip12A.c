#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];

    // Input the adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Check if the matrix is symmetric
    int isSymmetric = 1; // Assume it's symmetric
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != graph[j][i]) {
                isSymmetric = 0; // If a mismatch is found, it's not symmetric
                break;
            }
        }
        if (!isSymmetric) {
            break;
        }
    }

    if (isSymmetric) {
        printf("The graph is undirected (symmetric).\n");

        // Calculate in-degree of all vertices
        int inDegree[n];
        for (int i = 0; i < n; i++) {
            inDegree[i] = 0;
            for (int j = 0; j < n; j++) {
                inDegree[i] += graph[j][i];
            }
        }

        // Print in-degree of all vertices
        printf("In-degree of vertices:\n");
        for (int i = 0; i < n; i++) {
            printf("Vertex %d: %d\n", i, inDegree[i]);
        }
    } else {
        printf("The graph is not undirected (not symmetric).\n");
    }

    return 0;
}
