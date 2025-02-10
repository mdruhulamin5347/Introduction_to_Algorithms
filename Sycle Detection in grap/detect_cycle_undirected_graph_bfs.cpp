

// cycle ditection of undirecten graph



#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
vector<bool>vis(1005,false);
vector<int> parent(1005,-1);
bool cycle;

void bfs(int src){
    queue<int>q;
    q.push(src);
    vis[src]=true;
    parent[src]=0;
    while(!q.empty()){
        int par = q.front();
        q.pop();
       

        for(int child : adj_list[par]){
            if(vis[child] && parent[par] != child)
                cycle = true;
            if(!vis[child]){
                q.push(child);
                vis[child]=true;
                parent[child]=par;
            }
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
            bfs(i);
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