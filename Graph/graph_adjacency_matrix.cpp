#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // adjacency matrix (1-based indexing)
    int adj[n + 1][n + 1] = {0};

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // remove for directed graph
    }

    // print matrix
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
