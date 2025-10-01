#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
 
int main() {
ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int n,m;
cin>>n>>m;
vector<vector<int>>adjlist(n+1);
for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adjlist[u].push_back(v);
    adjlist[v].push_back(u);
}
vector<int>vis(n+1,-1);
queue<int>q;
bool f=1;
for(int i=1;i<=n;i++){
    // cout<<vis[i]<<" ";
    
    if(vis[i]!=-1)continue;
    vis[i]=1;
    q.push(i);
    while(!q.empty()){
        int p=q.front();
        q.pop();
        for(auto adj:adjlist[p]){
            if(vis[adj]==-1){
                vis[adj]=3-vis[p];
                q.push(adj);
            }else if(vis[adj]==vis[p]){
                f=false;
            }
        }
    }

}
if(f){
    for(int i=1;i<n+1;i++){
        cout<<vis[i]<<" ";
    }
}else cout<<"IMPOSSIBLE" ;

 
 return 0; }