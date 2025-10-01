#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m ;
    vector<vector<int>>adjlist(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    queue<pair<int,int>>q;
    vector<int>vis(n+1,0);
    // vector<pair<int,int>>v;
    map<int,int>mp;
    int src=1,p=-1;
    vis[src]=1;
    q.push({src,p});
    while(!q.empty()){
        int node=q.front().first;
            p=q.front().second;
            // v.push_back({node,p});
            mp[node]=p;
            q.pop();
            for(auto it:adjlist[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,node});
                }
            }
    }
    if(!vis[n]){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    int curr=n;
    vector<int>ans;
    while(curr!=-1){
        ans.push_back(curr);
        curr=mp[curr];
    }
    cout<<ans.size()<<endl;
    reverse(ans.begin(),ans.end());
    for(auto it:ans){
        cout<<it<<" ";
    }
   
   
}