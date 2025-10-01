#include<bits/stdc++.h>
using namespace std;
  string s;

void  dir(int r,int c){
    // cout<<r<<" "<<c<<endl;
  
    if(r==-1&&c==0)s.push_back('U');
    else if(r==0&&c==1)s.push_back('R');
    else if(r==1&&c==0)s.push_back('D');
    else if(r==0&&c==-1)s.push_back('L');
    // cout<<s<<endl;

}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>v(n,vector<char>(m));
   vector<vector<int>>vis(n,vector<int>(m,0));
    int sr,sc,dr,dc;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
            if(v[i][j]=='A'){
                sr=i;
                sc=j;
            }else if(v[i][j]=='B'){
                dr=i;
                dc=j;
            }else if(v[i][j]=='#'){
                vis[i][j]=1;
            }
        }
    }
    // cout<<dr<<" "<<dc<<endl;
   vector<vector<pair<int, int>>> p(n, vector<pair<int, int>>(m, {-1, -1}));
    queue<pair<int,int>>q;
    q.push({sr,sc});
    vis[sr][sc]=1;
    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
         int rmov[]={-1,0,1,0};
        int cmov[]={0,1,0,-1};
        for(int i=0;i<4;i++){
             int nrow=row+rmov[i];
             int ncol=col+cmov[i];
           
             if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&(!vis[nrow][ncol])){
                p[nrow][ncol]={row,col};
                q.push({nrow,ncol});
                vis[nrow][ncol]=1;
                
             }
        }
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << "(" << p[i][j].first << "," << p[i][j].second << ") ";
    //     }
    //     cout << endl;
    // }cout<<endl;
    if(!vis[dr][dc]){
        cout<<"NO"<<endl;
        return 0;
    }
    pair<int,int> curr={dr,dc};
   pair<int,int> source={sr,sc};
//    string s;
    while(curr.first!=source.first||curr.second!=source.second){
        int i=curr.first;
        int j=curr.second;
        // cout<<i<<" "<<j<<endl;
      curr=p[curr.first][curr.second];
    //   cout<<curr.first<<" "<<curr.second<<endl;
        int rmov=i-curr.first;
        int cmov=j-curr.second;
         dir( rmov, cmov);   
    }
    reverse(s.begin(),s.end());
   

        cout<<"YES"<<endl;
        cout<<s.size()<<endl<<s<<endl; 
  
}