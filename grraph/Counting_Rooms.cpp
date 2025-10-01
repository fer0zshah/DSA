#include<bits/stdc++.h>
using namespace std;
void dfs(int n,int m,int r,int c,vector<vector<int>>&vis,vector<vector<char>>&v){

    stack<pair<int,int>>s;
    s.push({r,c});
    vis[r][c]=1;
    while(!s.empty()){
        int row=s.top().first;
        int col=s.top().second;
        s.pop();
        int rmov[]={-1,0,1,0};
        int cmov[]={0,1,0,-1};
        for(int i=0;i<4;i++){
           int nrow=row+rmov[i];
           int ncol=col+cmov[i];
           if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&(!vis[nrow][ncol])){
            // cout<<nrow<<" "<<ncol<<endl;
                s.push({nrow,ncol});
                vis[nrow][ncol]=1;
           }
        }

    }

}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>v(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    vector<vector<int>>vis(n,vector<int>(m,0));
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='#'){
                vis[i][j]=1;
            }
        }
    }
    int c=0;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j]){
                // cout<<i<<" "<<j<<endl;
                dfs(n,m,i,j,vis,v);
                c++;
            }
        }
    }
    cout<<c<<endl;
}