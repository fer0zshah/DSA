#include<bits/stdc++.h>
using namespace std;
int lowerbound(vector<int>v,int key,int s){
    int l=0,r=s-1;
    int mid=r-(r-l)\2;
    int ans=-1;
    while(l<=r){
        if(v[i]>=key){
            ans=mid;
            r=mid-1;
        }else l=mid+1;
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
         int k;
        cin>>k;
        cout<<lowerbound(v,k,n)<<endl;
    }
    return 0;

}
