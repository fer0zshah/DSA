#include<iostream>
using namespace std;
class heap{
public:
    int a[100];
    int s;
    heap(){
        s=0;
    }

void heapify(int a[],int n,int i){
    int largest=i;
    int l=2*i;
    int r=2*i+1;
    if(l<n&&a[l]>a[largest]){
        largest=l;
    }
    if(r<n&&a[r]>a[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(a[largest],a[i]);
        heapify(a,n,largest);
    }

}
//void sorting(int a[]){
//while(!i)
//}
void PQ(int data){

        s++;
        int i=s;
        int p=i/2;
        a[i]=data;
        while(i>1){
                if(a[i]>a[p]){
                    swap(a[i],a[p]);
                    i=p;
                }else return;

        }

    }

void print(){
    for(int i=1;i<=s;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

};
 int main()
 {
     heap h;

    int arr[8]={-1,4,2,50,72,66,100,33};
    int n=7;
    for(int i=n/2;i>0;i--){
       h.heapify(arr,n,i);
    }
    cout<<"The maxHeap is:"<<endl;
   for(int i=1;i<=n;i++){
    cout<<arr[i]<<" ";
   }cout<<endl;
   int q[3]={8,15,35};
   for(int i=0;i<3;i++){
    h.PQ(q[i]);
   }
   h.print();

 }
