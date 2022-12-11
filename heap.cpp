#include <bits/stdc++.h>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        size=0;
        arr[size]=-1;
    }

    void insert(int val){
        size=size+1;
        int index=size;
        arr[index]=val;

        while(index>1){
            int parent=index/2;
            if(arr[index]>arr[parent]){
                swap(arr[index],arr[parent]);
                index=parent;
            }
            else{
                return;
            }
        }
    }

    void deletefromHeap(){
        if(size==0){
            cout<<"Nothing to delete";
            return;
        }
        arr[1]=arr[size];
        int index=1;
        size--;
        
        while(index<=size){
            int left=2*index;
            int right=2*index+1;

            if(left<=size && arr[left]>arr[index]){
                swap(arr[left],arr[index]);
                index=left;
            }
            else if(right<=size && arr[right]>arr[index]){
                swap(arr[right],arr[index]);
                index=right;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
    }
};

void heapify(int arr[],int n,int i){
        int largest=i;
        int left=2*i;
        int right=2*i+1;

        if(left<n && arr[largest]<arr[left]){
            largest=left;
        }
        if(right<n && arr[largest]<arr[right]){
            largest=right;
        }
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
    }

int main(){
     heap h;
    h.insert(50);
    h.insert(40);
    h.insert(60);
    h.insert(30);
    h.insert(20);
    h.insert(70);

    h.print();
    cout<<endl;

    h.deletefromHeap();
    h.print();
    cout<<endl;

    h.deletefromHeap();
    h.print();
    cout<<endl;

    // h.deletefromtHeap();
    // h.print();
}