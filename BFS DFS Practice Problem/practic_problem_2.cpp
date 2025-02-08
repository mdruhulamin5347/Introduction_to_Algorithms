
// problem number 2

// Question: You will be given an undirected graph which will be connected as input. Then you will be given a level L. You need to print the node values at level L in descending order. The source will be 0 always.


#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
vector<bool>vis(1005,false);
vector<int>level(1005,-1);

void bfs(int src){
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
                level[child]=level[par]+1;
            }
        }
    }
}
// main function 
int main(){
    int n,e;
    cin >> n >> e;
    while(e--){
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    bfs(0);

    int x;
    cin >> x;
    for(int i=n-1; 0<i; i--){        
        if(level[i]==x){
            cout << i << " ";
        }

    }

    return 0;
}