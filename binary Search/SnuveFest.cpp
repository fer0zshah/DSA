#include<bits/stdc++.h>
using namespace std;

int lowerbound(vector<long long>&v,long long key,int s){
    int l=0,r=s-1;
    int mid=r-(r-l)/2;;
    int ans=s;
    while(l<=r){

        if(v[mid]>=key){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
        mid=r-(r-l)/2;

 }


    return (ans);
    }
int upperbound(vector<long long>&v,long long key,int s){
    // int s=v.size();
    int l=0,r=s-1;
    int mid;
    int ans=s;
    // if(key<v[0])return 0;
    while(l<=r){
          mid=r-(r-l)/2;
        if(v[mid]>key){
           ans=mid;
            r=mid-1;
        }else l=mid+1;

    }

    return ans;


}
    //  cout<<ans<<endl;
int main()
{
    int n;
    cin>>n;
    vector<long long>A(n);
    vector<long long>B(n);
    vector<long long>C(n);

    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    for(int i=0;i<n;i++){
        cin>>B[i];
    }
    for(int i=0;i<n;i++){
        cin>>C[i];
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(C.begin(),C.end());

    long long sum=0;
    for(int i=0;i<n;i++){
        long long x=lowerbound(A,B[i],n);
        long long  y=n-upperbound(C,B[i],n);
        // cout<<B[i]<<" "<<x<<" "<<y<<"\n";
        sum+=x*y;
    }
    cout<<sum<<"\n";
}
