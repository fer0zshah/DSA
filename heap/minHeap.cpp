#innclude<iostream>
using namespace std ;
class heap{
public:
    int a[100];
    int s;
    heap(){
        s=0;
    }
    void inserT(int data){
        s++;
        int i=s;
        int p=i/2;
        arr[i]=data;
        while(i>1){
            if(a[i]<a[p]){
                swap(a[i],a[p]);
                i=p;
            }else return ;
        }
    }

};
int main()
{
    heap h

}
