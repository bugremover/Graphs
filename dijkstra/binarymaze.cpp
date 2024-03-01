//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // taking a queue that stores distance and row nd col of node;
        queue<pair<int,pair<int,int>>> q;
        //creating 2d vector that stores 1e9 as distance
        //checking if source and destination are on same cell
        if(source.first == destination.first && source.second== destination.second) return 0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int> (m,1e9));
        //marking source distance as 0
        dist[source.first][source.second]=0;
        q.push({0,{source.first,source.second}});
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,-1,0,+1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int distance=it.first;
            int row=it.second.first;
            int col=it.second.second;
            //moving four directions
            for(int i=0;i<4;i++){
                int newrow=row+delrow[i];
                int newcol=col+delcol[i];
                if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && grid[newrow][newcol]==1 && distance+1 <dist[newrow][newcol]){
                    dist[newrow][newcol]=distance+1;
                    //if its true then we will return
                    if(newrow == destination.first && newcol == destination.second) return distance +1;
                    q.push({distance+1,{newrow,newcol}});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends