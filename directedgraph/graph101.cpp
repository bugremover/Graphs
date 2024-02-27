#include <iostream>
#include <vector>
using namespace std;
int main(){
    //m=no.of edges
    int n,m;
    cin>>n>>m;
    //graph starts with one
    vector<int> adj[n+1];
    //for 1 base graph
    for(int i=0;i<m;i++){
        //take nodes that are connected with edges
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        //pushing only if direction present else no
        adj[v].push_back(u);
        //space complexity will be O(no.of Edges)
    }


    return 0;
}