#include <bits/stdc++.h>
using namespace std;

void takeInput(int arr[][4],int row,int col){
     for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
}


void print(int arr[][4],int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void spiralPrint(int arr[][4],int row,int col){
    int startingRow=0;
    int startingCol=0;
    int endingRow=row-1;
    int endingCol=col-1;

    int total=row*col;
    int count=0;

    while(count<total){
        // For starting row
        for(int index=startingCol;index<=endingCol && count<total ;index++){
            cout<<arr[startingRow][index]<<" ";
            count++;
        }
        cout<<endl;
        startingRow++;

        for(int index=startingRow;index<=endingRow && count<total;index++){
            cout<<arr[index][endingCol]<<" ";
            count++;
        }
        cout<<endl;
        endingCol--;

        for(int index=endingCol;index>=startingCol && count<total;index--){
            cout<<arr[endingRow][index]<<" ";
            count++;
        }
        cout<<endl;
        endingRow--;

        for(int index=endingRow;index>=startingRow && count<total;index--){
            cout<<arr[index][startingCol]<<" ";
            count++;
        }
        cout<<endl;
        startingCol++;
        
}
}

int main(){
    int arr[4][4];
    takeInput(arr,4,4);
    print(arr,4,4);
    spiralPrint(arr,4,4);
    
    
    
}