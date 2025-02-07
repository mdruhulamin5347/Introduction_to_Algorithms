
// problem number 2


// Problem Statement

// You will be given an undirected graph as input. Then you will be given  queries. For each query you will be given a node . You need to print the nodes that are connected with  in descending order.

// Note: If there is no node connected to , then print -1.

// Input Format

// The first line will contain  and , the number of nodes and the number of edges, respectively. The values of the nodes range from  to .
// Next  lines will contain two node values which means there is a connection between first node and second node.
// The next line will contain .
// The following  lines will each contain .
// Constraints

// Output Format

// Output the nodes that are connected with  in descending order.



#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,e;
    cin >> n >> e;
    vector<int> adj_list[n];    

    while(e--){
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    
    int q;
    cin >> q;
    while(q--){
        vector<int> v;
        int x;
        cin >> x;
        if(adj_list[x].empty()){
            v.push_back(-1);
        }
        for(int val : adj_list[x])
        {         
            v.push_back(val);
        }        
        sort(v.begin(),v.end(),greater<int>());
        for(int ans : v){
            cout << ans << " ";
        }
        cout << endl;
    }

    return 0;
}