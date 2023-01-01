#include <bits/stdc++.h>
using namespace std;

void merge(int arr[],int n,int s,int mid,int e){
    int n1=mid-s+1;
    int n2=e-mid;
    int arr1[n1];
    int arr2[n2];

    for(int i=0;i<n1;i++){
        arr1[i]=arr[s+i];
    }
    for(int i=0;i<n2;i++){
        arr2[i]=arr[mid+i+1];
    }

    int i=0;
    int j=0;
    int k=s;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            arr[k++]=arr1[i++];
        }
        else{
            arr[k++]=arr2[j++];
        }
    }

    while(i<n1){
        arr[k++]=arr1[i++];
    }
    while(j<n2){
        arr[k++]=arr2[j++];
    }

}

void mergeSort(int arr[],int n,int s,int e){
    if(s<e){
        int mid=(s+e)/2;
        mergeSort(arr,n,s,mid);
        mergeSort(arr,n,mid+1,e);
        merge(arr,n,s,mid,e);
    }

}

int main(){
    int arr[6]={6,5,4,3,2,1};
    mergeSort(arr,6,0,5);

    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
}