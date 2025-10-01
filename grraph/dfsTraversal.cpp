#include<bits/stdc++.h>
class Solution {
  public:
  void dfs(int node,vector<int>&ans,vector<vector<int>>&adj,vector<int>&vis){
      ans.push_back(node);
      vis[node]=1;
      for(auto it:adj[node]){
          if(!vis[it]){
              dfs(it,ans,adj,vis);
          }
      }

  }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>vis(n,0);
        int start=0;

        vector<int>ans;


        dfs(0,ans,adj,vis);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
