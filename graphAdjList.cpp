#include <iostream>
#include<map>
#include <list>
using namespace std;

class graph{
    public:
    map<int,list<int>> adj;

    void add(int u,int v,bool direction){
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }

    void printGraph(){
        for(auto it:adj){
            cout<<it.first<<"->";
            for(auto j:it.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

};

int main(){
    cout<<"Hello";
    int n;
    cout<<"Enter the nodes"<<endl;
    cin>>n;

    int m;
    cout<<"Enter the edges"<<endl;
    cin>>m;

    graph g;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.add(u,v,0);
    }

    g.printGraph();
}