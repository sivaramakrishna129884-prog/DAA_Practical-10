#include <iostream>
using namespace std;

int main() {
    int n, cost[10][10];
    int parent[10];
    int minCost = 0, edges = 0;
    int min, u = 0, v = 0;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter cost adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
            if (cost[i][j] == 0)
                cost[i][j] = 9999;
        }
        parent[i] = i;
    }

    cout << "Edges in Minimum Spanning Tree:\n";

    while (edges < n - 1) {
        min = 9999;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        if (min == 9999)
            break;

        int a = u, b = v;

        while (parent[a] != a)
            a = parent[a];

        while (parent[b] != b)
            b = parent[b];

        if (a != b) {
            cout << u << " - " << v
                 << " : " << min << endl;

            minCost += min;
            parent[a] = b;
            edges++;
        }

        cost[u][v] = 9999;
        cost[v][u] = 9999;
    }

    if (edges != n - 1)
        cout << "Graph is disconnected";
    else
        cout << "Minimum Cost: " << minCost;

    return 0;
}
