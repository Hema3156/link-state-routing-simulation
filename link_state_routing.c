// ================================================================
// DSA Mini Project - Link State Routing Simulation
// ================================================================

#include <stdio.h>
#include <limits.h>

#define MAX 10
#define INF 9999

int n; // Number of routers
int cost[MAX][MAX]; // Graph (Adjacency Matrix) 
int dist[MAX]; // Distance array - Linear DS
int visited[MAX];

// Function 1: Create Network Topology-
void createNetworkTopology() {
    printf("Enter number of routers: ");
    scanf("%d", &n);
    printf("\nEnter cost adjacency matrix (use 9999 for no direct link):\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
}

// Function 2: Initialize Routing Tables

void initializeRoutingTables() {
    printf("\nInitial Routing Table (Cost Matrix):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cost[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }
}

// Dijkstra Algorithm - Find shortest path from given router
void dijkstra(int src) {
    for (int i = 0; i < n; i++) {
        dist[i] = cost[src][i];
        visited[i] = 0;
    }

    dist[src] = 0;
    visited[src] = 1;

    for (int count = 1; count < n - 1; count++) {
        int min = INF, u = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1) break; // no reachable node

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && (dist[u] + cost[u][v] < dist[v])) {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    printf("\nRouting Table for Router %d:\n", src + 1);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("Router %d -> Router %d : Unreachable\n", src + 1, i + 1);
        else
            printf("Router %d -> Router %d : Cost = %d\n", src + 1, i + 1, dist[i]);
    }
}

// Function 3: Update Link Cost
void updateLinkCost() {
    int r1, r2, newCost;
    printf("\nEnter the two routers (1-based index) whose link cost to update: ");
    scanf("%d%d", &r1, &r2);
    printf("Enter new cost: ");
    scanf("%d", &newCost);

    cost[r1 - 1][r2 - 1] = newCost;
    cost[r2 - 1][r1 - 1] = newCost;

    printf("Link cost between Router %d and Router %d updated to %d successfully.\n",
           r1, r2, newCost);
}

// Function 4: Print Routing Tables (for all routers)
void printRoutingTables() {
    for (int i = 0; i < n; i++) {
        dijkstra(i);
    }
}

// Main Function - Menu Driven Simulation
int main() {
    int choice;
    printf("\n=== LINK STATE ROUTING SIMULATOR ===\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Network Topology\n");
        printf("2. Initialize Routing Tables\n");
        printf("3. Display Routing Tables (Dijkstra)\n");
        printf("4. Update Link Cost\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createNetworkTopology();
                break;
            case 2:
                initializeRoutingTables();
                break;
            case 3:
                printRoutingTables();
                break;
            case 4:
                updateLinkCost();
                break;
            case 5:
                printf("Exiting simulation...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}