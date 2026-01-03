#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> bfsOfGraph(int V, int start, vector<int> adj[]) {
        vector<int> vis(V+1, 0);
        vis[start] = 1;

        queue<int> q;
        q.push(start);

        vector<int> bfs;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<int> adj[V+1];   // adjacency list (0-based indexing)

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // undirected
    }

    int start;
    cin >> start;

    Solution obj;
    vector<int> result = obj.bfsOfGraph(V, start, adj);

    // print BFS traversal
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
