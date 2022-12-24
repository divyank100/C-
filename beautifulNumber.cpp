#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){

    
    int n;
    cin>>n;
    int arr[n];

    int x;
    cin>>x;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        bool isFound=false;
        int curr=arr[i];
        int dummy=0;
        while(curr>x){
            if(arr[i]%10==x){
                isFound=true;
                break;
            }
            else if( curr%10==x && curr+dummy==x){
                isFound=true;
                break;
            }
            else{
                curr--;
                dummy++;
            }
        }
        if(isFound){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    }
}