#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>a[m];
    for(int i=0;i<m;i++){
            int u,v;
        cin>>u>>v;

        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        cout<<i<<" : ";
        for(auto it=a[i].begin();it!=a[i].end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }



}
