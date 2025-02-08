
// problem number 1

// Question: You will be given an undirected graph as input. Then you will be given a query Q. For each query, you will be given source S and destination D. You need to print the shortest distance between S and D. If there is no path from S to D, print -1.



#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];

void bfs(int src,int dst){
    vector<bool>vis(1005,false);
    vector<int>level(1005,-1);
    queue<int>q;
    q.push(src);
    vis[src]=true;
    level[src]=0;
    while(!q.empty()){
        int par = q.front();
        q.pop();

      
        for(int child : adj_list[par]){
            if(!vis[child]){
                q.push(child);
                vis[child]=true;
                level[child] = level[par] + 1;
            }
        }
    } 
    cout  << level[dst] << endl;   
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
    int q;
    cin >> q;
    while(q--){
        int src,dst;
        cin >> src >> dst;
        bfs(src,dst);        
    }
    
    return 0;
}