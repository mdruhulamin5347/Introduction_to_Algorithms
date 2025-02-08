
// problem number 3

// Question: You will be given an undirected graph as input. Then you will be given a node N. You need to print the number of nodes that are directly connected to the node N.


#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];

int main(){
    int n,e;
    cin >> n >> e;
    while(e--){
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    int x;
    cin >> x;

    cout << adj_list[x].size() << endl;
    
    return 0;
}