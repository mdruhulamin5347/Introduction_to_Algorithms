
// diakstra algorithm solve by more optimize approch


#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj_list[1005];
vector<int>path(1005,INT_MAX);

void dijkstra(int src){
    priority_queue<pair<int,int>> pq;
    pq.push({src,0});
    path[src]=0;
    while(!pq.empty()){
        pair<int,int> par = pq.top();
        pq.pop();
        int par_dis = par.first;
        int par_node = par.second;

        for(auto child : adj_list[par_node]){
            int child_node = child.first;
            int child_dis = child.second;
            if(par_dis + child_dis < path[child_node]){
                path[child_node] = par_dis + child_dis;
                pq.push({path[child_node],child_node});
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