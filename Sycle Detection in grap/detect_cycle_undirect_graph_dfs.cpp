

// cycle ditection of undirecten graph using dfs



#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
vector<bool>vis(1005,false);
vector<int> parent(1005,-1);
bool cycle;

void dfs(int src){   

    vis[src] = true;   
    
    for(int child : adj_list[src]){
        if(vis[child] && parent[src] != child)
            cycle = true;
        if(!vis[child]){
            parent[child] = src;
            dfs(child);            
        }
    }

}

int main(){
    int n,e;
    cin >> n >> e;
    while(e--){
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    cycle = false;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    if(cycle){
        cout << "Cycle ditected" << endl;
    }
    else{
        cout << "No Cycle" << endl;
    }
    return 0;
}