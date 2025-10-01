#include <bits/stdc++.h>
using namespace std;
int BinSearch(int a[],int key,int s){
    int start=0,End=s-1;
    int mid=0,ans=0;
    while(start<=End){
        mid=start-(start-End)/2;
        if(key>=a[mid]){
            ans=mid+1;
            start=mid+1;
        }else{
            End=mid-1;
        }
    }
    return ans;
}



int main() {
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int b[k];
    for(int i=0;i<k;i++){
        cin>>b[i];
    }
    for(int i=0;i<k;i++){
        int val=BinSearch(a,b[i],n);
        cout<<val<<endl;

    }




    return 0;
}
