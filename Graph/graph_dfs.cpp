#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &result) {
        vis[node] = 1;
        result.push_back(node);

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, result);
            }
        }
    }

    vector<int> dfsOfGraph(int V, int start, vector<int> adj[]) {
        vector<int> vis(V + 1, 0);
        vector<int> result;

        dfs(start, adj, vis, result);
        return result;
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<int> adj[V + 1];   // 1-based adjacency list

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // undirected graph
    }

    int start;
    cin >> start;

    Solution obj;
    vector<int> dfsTraversal = obj.dfsOfGraph(V, start, adj);

    for (int x : dfsTraversal) {
        cout << x << " ";
    }

    return 0;
}
