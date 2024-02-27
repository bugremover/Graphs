#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> bfsofgraph(int V, vector<int> adj[]) {
    // Create visit array
    vector<bool> visit(V + 1, false); // Use bool for visited nodes

    // Start from node 1 (if 1-based indexing)
    visit[1] = true;

    // Create queue
    queue<int> q;
    q.push(1);

    // BFS traversal
    vector<int> bfs;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        // Check neighbors
        for (auto it : adj[node]) {
            if (!visit[it]) {
                visit[it] = true;
                q.push(it);
            }
        }
    }

    return bfs;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Use 0-based indexing if necessary
    vector<int> adj[n + 1]; // Adjust size if using 1-based indexing

    // Add edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // Consider directed or undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }

    vector<int> bfs = bfsofgraph(n, adj);

    // Print BFS result
    for (int node : bfs) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
