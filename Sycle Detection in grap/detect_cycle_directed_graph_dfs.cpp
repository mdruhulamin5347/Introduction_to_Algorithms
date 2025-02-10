

// detect cycle in directed graph using dfs

#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
vector<bool>vis(1005,false);
vector<bool>pathVis(1005,false);
bool cycle;

void dfs(int src){
    
    vis[src]=true;
    pathVis[src]=true;

    for(int child : adj_list[src]){
        if(vis[child] && pathVis[child]){
            cycle = true;
        }
        if(!vis[child]){            
            dfs(child);
        }
    }
    pathVis[src]=false;
}


int main(){
    int n,e;
    cin >> n >> e;
    while(e--){
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
    }
    cycle = false;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    if(cycle)
        cout << "Cycle detect" << endl;
    else 
        cout << "No Cycle" << endl;
    return 0;
}