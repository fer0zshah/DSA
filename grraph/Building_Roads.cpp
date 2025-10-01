#include<bits/stdc++.h>
using namespace std;
int dfs(int i,vector<vector<int>>&adjlist,vector<int>&vis){
             stack<int>s;
            s.push(i);
              vis[i]=1;
            vector<int>ans;
            while(!s.empty()){
                int node=s.top();
                ans.push_back(node);
                s.pop();
                for(auto it:adjlist[node]){
                    if(!vis[it]){
                        s.push(it);
                        vis[it]=1;
                    }
                }
            }
            int ln=ans[ans.size()-1];
            return ln;

}
int main(){
    int n,m;
    cin>>n>>m;
    // vector<vector<int>>v(m,vector<int>(2));
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<2;j++){
    //         cin>>v[i][j];
    //     }
    // }
    // vector<vector<int>>adjlist(n);
    // for(int i=0;i<m;i++){
    //     adjlist[v[i][0]].push_back(v[i][1]);
    //     adjlist[v[i][1]].push_back(v[i][0]);
    // }
    vector<vector<int>>adjlist(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    vector<int>vis(n+1,0);
   
    int c=0;
    int prev=0,ln;
    vector<pair<int,int>>p;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
           if(prev!=0){
            p.push_back({prev,i});
           }
            c++;
            ln=dfs(i,adjlist,vis);
        }
        prev=ln;
    }
    cout<<c-1<<endl;
    for(auto it:p){
        cout<<it.first<<" "<<it.second<<endl;
    }

}