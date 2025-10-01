#include<bits/stdc++.h>
using namespace std;
const int MAXN=10e5+5;
 vector<vector<int>>adjlist(MAXN);
int c=0,m,n,ans=0;
vector<int>vis(MAXN,0);
vector<int>cat(MAXN,0);
void dfs (int node,int c){
    if(cat[node])c++;
    else c=0;
    if(c>m)return ;
    vis[node]=1;
    int f=1;
    for(auto it:adjlist[node]){
        if(!vis[it]){
            f=0;
            dfs(it,c);
        }
    }
    if(f)ans++;
}

int main(){

 
    cin>>n>>m;

    for(int i=1;i<n+1;i++){
        cin>>cat[i];
    }
   
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    dfs(1,c);
    cout<<ans;

}
