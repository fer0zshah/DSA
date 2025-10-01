#include<bits/stdc++.h>
using namespace std;
int bin_search(vector<int>v,int key){
    int s=v.size();
    int l=0,r=s-1;
    int mid=r+(l-r)/2;
    while(l<=r){
        if(v[mid]==key){
            return mid;
        }
        if(v[mid]<key){
            r=mid-1;
        }else l=mid+1;
        int mid=r+(l-r)/2;
    }
    return -1;
}
int main()
{
    vector<int>a={3,5,7,8,9,10,12,23,34,45,56};
    //int index=bin_search(a,23);
    //cout<<index<<endl;
    cout<<"hello world";
    return 0;
}
