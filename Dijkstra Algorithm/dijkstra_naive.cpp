
// Dijkstra Algorithm solve by naive


#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj_list[105];
vector<int> path(105,INT_MAX);

void dijkstra(int src){
    queue<pair<int,int>>q;
    q.push({src,0});
    path[src]=0;
    while(!q.empty()){
        pair<int,int> par = q.front();
        int par_node = par.first;
        int par_dis = par.second;
        q.pop();

        for(auto child : adj_list[par_node]){
            int child_node = child.first;
            int child_dis = child.second;
            if(par_dis + child_dis < path[child_node]){
                path[child_node] = par_dis + child_dis;
                q.push({child_node,path[child_node]});
            }
        }
    }
}

int main(){
    int n,e;
    cin >> n >> e;
    while(e--){
        int a,b,c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});
    }    
    
    dijkstra(0);

    for(int i=0; i<n; i++)
        cout << path[i] << " ";

    return 0;
}