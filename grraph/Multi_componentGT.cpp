#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
   vector<vector<int>>adj(V);
   for(int i=0;i<edges.size();i++){
       int u=edges[i][0];
       int v=edges[i][1];

       adj[u].push_back(v);
       adj[v].push_back(u);
   }
        vector<int>vis(V,0);
        vector<vector<int>>ans;
       for(int i=0;i<V;i++){
           if(!vis[i]){
               vector<int>com;
               stack<int>s;
               s.push(i);
               vis[i]=1;
               while(!s.empty()){
                   int node=s.top();
                   s.pop();
                   com.push_back(node);
                   for(auto it:adj[node]){
                       if(!vis[it]){
                           vis[it]=1;
                           s.push(it);
                       }
                   }
               }
               ans.push_back(com);
            //    dfs(i,vis,adj,com);
            //    ans.push_back(com);
           }
       }
       return ans;
}
int main()
{
    int V,E;
    cin>>V>>E;vector<vector<int>>edges(E,vector<int>(2));
    for(int i=0;i<E;i++){
        cin>>edges[i][0]>>edges[i][1];
    }
    vector<vector<int>>r=depthFirstSearch(V, E,edges);
    cout<<r.size()<<endl;
    for(auto &it:r){
        for(int v:it){
            cout<<v<<" ";
        }
        cout<<endl;
    }


}
