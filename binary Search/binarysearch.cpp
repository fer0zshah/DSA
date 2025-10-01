#include<bits/stdc++.h>
using namespace std;
int bin_search(vector<int>v,int key){
    int s=v.size();
    int l=0,r=s-1;
    int mid=l+(r-l)/2;
    int ans=0;
    while(l<=r){
            mid=l+(r-l)/2;
           if(v[mid]<=key){
            l=mid+1;
            ans=mid;
           }else{
            r=mid-1;
           }


}
 return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        v.push_back(val);
    }

    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int m;
        cin >>m;
        int index=bin_search(v,m);
        cout<<index<<endl;
    }

    return 0;
}
