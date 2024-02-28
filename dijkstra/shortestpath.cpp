//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Create a graph{adjancency list}
        vector<pair<int,int>> adj[n+1];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        //declare minimum heap;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        //declare distance array;
       vector<int> dist(n+1,1e9),parent(n+1);
       //mark parent array themselves
       for(int i=1;i<=n;i++) parent[i]=i;
        dist[1]=0;
        pq.push({0,1});
        //intialize array
        //int parent[n+1];
        //vector<int> parent(n+1);
        //weigth and node
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int weight=it.first;
            
            for(auto it:adj[node]){
                int adjNode=it.first;
                int edgeWeight=it.second;
                if(edgeWeight+weight < dist[adjNode]){
                    dist[adjNode] =  edgeWeight + weight;
                    pq.push({edgeWeight+weight,adjNode});
                    //here parent of adjnode is node
                    parent[adjNode]=node;
                }
            }
        }
        //if destination didnt reach then
        if(dist[n]== 1e9) 
            return {-1};
        vector<int> path;
        int  node=n;
        //if its equal then all nodes are visited 
        while(parent[node] != node ){
            path.push_back(node);
            node=parent[node];
        }
        //manually pushing 1 into the path
        path.push_back(1);
        //reveser path
        reverse(path.begin(),path.end());
        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int,int>,int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0],edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1],edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans=0;
        for(int i=2;i<res.size();i++)
        {
            ans+=mp[{res[i],res[i-1]}];
        }
        if(res.size()==1) ans=res[0];
        cout<<ans<<endl;
    }
}

// } Driver Code Ends