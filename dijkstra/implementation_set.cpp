//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int,int>> st;
        vector<int> dist(V,1e9);
        dist[S]=0;
        st.insert({0,S});
        while(!st.empty()){
            // * will give the value of top value that means minimum value
            auto it= *(st.begin());
            //traversing in the set and getting top most value;
            int node=it.second;
            int distance=it.first;
            //erasing that value to remove duplicates
            st.erase(it);
            for(auto it:adj[node]){
                int edgeWeight=it[1];
                int adjNode=it[0];
                if(dist[adjNode] != 1e9){
                    st.erase({dist[adjNode],adjNode})
                    dist[adjNode]=distance+edgeWeight;
                    st.insert({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends