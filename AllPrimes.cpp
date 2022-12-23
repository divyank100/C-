#include <iostream>
using namespace std;

void printPrime(int n){
    int i;
    for(i=2;i<=n;i++){
        if(n%i==0)
            break; 
    }
    // if(i==n){
    //     cout<<n<<" ";
    // }
}

int main(){
    int n;
    cin>>n;

    for(int i=2;i<=n;i++){
        printPrime(i);
    }

}