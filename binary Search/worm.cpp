#include<bits/stdc++.h>
using namespace std;
int lowerbound(vector<int>&v,int s,int q){
    int l=0,r=s-1;
    int mid=l+(r-l)/2;;
    int ans=0;
    while(l<=r){

        if(v[mid]>=q){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
        mid=l+(r-l)/2;

    }

    return ans+1 ;
}

int main()
{
    int s1;
    cin>>s1;
    vector<int>v;


     int val;
    for(int i=0;i<s1;i++){
        cin>>val;
        v.push_back(val);
    }
    vector<int>l;
        int x;
        for(int i=0;i<s1;i++){
        if(i==0){
            x=v[i];
        }else{
           x=v[i]+x;
        }
        l.push_back(x);

    }
    // for(int i=0;i<s1;i++){
    //     cout<<l[i]<<" ";
    // }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int q;
        cin>>q;
      cout<<lowerbound(l,s1,q)<<endl;
    }
return 0;
}
