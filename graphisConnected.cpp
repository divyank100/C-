#include <bits/stdc++.h>
using namespace std;

void printDFS(int** edges,int n,int sv,bool* visited){
    // cout<<sv<<" ";
    visited[sv]=true;

    for(int i=0;i<n;i++){
        if(i==sv){
            continue;
        }
        if(edges[i][sv]==1){
            if(visited[i]){
                continue;
            }
            printDFS(edges,n,i,visited);
        }
    }

}

bool isConnected(int** edges,int n,int sv){
    bool* visited=new bool[n];

    for(int i=0;i<n;i++){
        visited[i]=false;
    }

    printDFS(edges,n,sv,visited);

    bool virginity=true;
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            virginity=false;
            return false;
        }
    }
    if(virginity){
        return true;
    }

}


int main(){
    int n,e;
    cin>>n>>e;

    int** edges= new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];

        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }

    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;

        edges[f][s]=1;
        edges[s][f]=1;
    }

    cout<<isConnected(edges,n,0);

    
    

}