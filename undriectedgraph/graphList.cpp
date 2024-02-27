//here we ajancency list as it takes less amount of space compare matrix
//we use vector where space complexity will be O(2 * no.of edges)
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    //for 1 base graph
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    return 0;
}