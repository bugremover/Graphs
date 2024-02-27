#include <iostream>
#include <vector>
using namespace std;

void dfsrecursive(int node, vector<int> adj[], vector<bool> visit, vector<int> &ls) {
  // Mark the node as visited
  visit[node] = true;

  // Add the node to the output list
  ls.push_back(node);

  // Visit the unvisited neighbors of the node
  for (int neighbor : adj[node]) {
    if (!visit[neighbor]) {
      dfsrecursive(neighbor, adj, visit, ls);
    }
  }
}

vector<int> dfsofgraph(int v, vector<int> adj[]) {
  // Create a visited array to keep track of visited nodes
  vector<bool> visit(v, false);

  // Start the DFS from the first node
  vector<int> dfs;
  dfsrecursive(0, adj, visit, dfs);

  return dfs;
}

int main() {
  int n, m;
  cin >> n >> m;

  // Create an adjacency list to represent the graph
  vector<int> adj[n];

  // Read the edges from the input
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u); // For undirected graph
  }

  // Perform DFS and print the result
  vector<int> dfs = dfsofgraph(n, adj);
  for (int node : dfs) {
    cout << node << " ";
  }
  cout << endl;

  return 0;
}
