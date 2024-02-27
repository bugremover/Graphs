#include <iostream>
using namespace std;
int main(){
    int n,m;
    //take two inputs as no.of nodes and no.edges
    cin>>n>>m;
    //create adjacency matrix that stores 1 if there is edges else 0
    int adj[n+1][m+1];
    //if graph is 1 based then take m+1 else m
    //run for loop to take input of edges between nodes like u and v
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        //storing as one to given edges in matrix
        //but this will be costly space complexityO(N * N)
        adj[u][v]=1;
        adj[v][u]=1;
    }
    cout<<"adjanceny matrix";
    for(int i=0;i<n+1;i++){
        for(int j=0;j<=m+1;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
    
}