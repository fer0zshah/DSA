#include<iostream>
using namespace std;
class heap{
public:
    int arr[100];
    int s;
    heap(){
        arr[0]=-1;
        s=0;

    }
    void inserT(int data){
        s++;
        int i=s;
        int p=i/2;
        arr[i]=data;
        while(i>1){
                if(arr[i]>arr[p]){
                    swap(arr[i],arr[p]);
                    i=p;
                }else return;

        }

    }
    void deleten(){
        if(s==0){
            return;
        }
        arr[1]=arr[s];
        s--;
        int i=1;
        while(i<s){
            int l=2*i;
            int r=2*i+1;
            if(arr[l]>arr[i]&&l<s){
                swap(arr[i],arr[l]);
            }else if(arr[r]>arr[i]&&r<s){
            swap(arr[i],arr[r]);
        }else return;
        }
    }
    void heapify(int a[],int n,int i){
        int largest=i;
        int l=2*i+1;
        int r=2*i;
        if(l<n&&a[l]>a[largest]){
           largest=l;
        }if(r<n&& a[r]>a[largest]){
           largest=r;
        }
        if(largest!=i){
            swap(a[largest],a[i]);
            heapify(a,n,largest);
        }
    }
    void print(){
        for(int i=1;i<=s;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }


};
int main()
{
    heap h;
    h.inserT(50);
    h.inserT(40);
    h.inserT(35);
    h.inserT(30);
    h.print();
    h.deleten();
        h.print();
    int a[6]={-1,54,52,53,55,50};
    int n=5;
    for(int i=n/2;i>0;i--){

    h.heapify(a,n,i) ;

    }
    cout<<"print the array now "<<endl;
    for(int i=1;i<n;i++){
        cout<<a[i]<<" ";
    }
}
