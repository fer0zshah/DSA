#include <bits/stdc++.h>
using namespace std;
int BinarySearch(int a[],int key,int s){

    int start=0;
    int End=s-1;
    int mid=(start+End)/2;
    while(start<=End){
    if(key==a[mid]){
        return mid;
    }
    if(key>a[mid]){
        start=mid+1;
    }else{
        End=mid-1;
    }
    mid=(start+End)/2;


    }
    return -1;
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
        int val=BinarySearch(a,b[i],n);
         if(val==-1){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }
    }


    return 0;
}
