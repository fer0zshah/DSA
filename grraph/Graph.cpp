#include<bits/stdc++.h>
using namespace std;
class graph{
public:
    unordered_map<int,list<int>>adj;
    void addEdge(int u,int v,bool direction){
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }
    void print(){
    for(auto i:adj){
        cout<<i.first<<"->";
        for(auto j: i.second){
            cout<<j<<", ";
        }
        cout<<endl;
        }
    }
};
int main()
{
   int n;
   cout<<"enter nmbe of nodes:"<<endl;
   cin>>n;
   int m;
   cout<<"enter number of edges :"<<endl;
    cin>>m;
    graph g;
    for(int i;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);

    }
    g.print();

}
