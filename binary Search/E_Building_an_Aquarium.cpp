#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin >> t;
    while (t--)
    {
        LL n, x;
        cin >> n >> x;
        vector<LL>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        LL s=1,e=1e10;
        while(s<e-1){
            LL h=(e+s)/2,w=0;
        
            for(int i=0;i<n;i++){
                if(v[i]<h){
                    w+=(h-v[i]);
                }
            }
            cout<<h<<" "<<w<<endl;
            if(w>x){
                e=h;
            }else{
                s=h+1;
            }
            
        }
        
        cout<<s<<"\n";
    }

    return 0;
}