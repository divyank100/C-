#include <iostream>
using namespace std;

bool h_path(int** edg, int n, int st, int end, bool* visited){
	visited[st] = true;
	if(edg[st][end]==1){
		return true;
	}
	for(int i = 0;i<n;i++){
		if(i == st){
			continue;
		}
		if(edg[st][i] == 1){
			if(visited[i]){
				continue;
			}
			else{
				bool ans = h_path(edg,n,i,end,visited);
				if(ans){
					return true;
				}
			}
		}
	}
	return false;
}

int main(){
    int n;
    int e;
    cin>>n>>e;

    int** edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }

    for(int i=0;i<e;i++){
        int f;
        int s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }

    cout<<"Give two vertex: ";
    int v1;
    int v2;
    cin>>v1>>v2;

    bool* visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }

    cout<<h_path(edges,n,v1,v2,visited);

    
}