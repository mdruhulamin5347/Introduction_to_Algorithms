
// problem number 1


// Problem Statement

// You will be given a directed graph as input. Then you will receive  queries. For each query, you will be given two nodes,  and . You need to determine whether you can go from  to  directly without using any other nodes.

// Input Format

// The first line will contain  and , the number of nodes and the number of edges, respectively. The values of the nodes range from  to .
// Next  lines will contain two node values which means there is a connection from first node to second node.
// The next line will contain .
// The following  lines will each contain  and .
// Constraints

// Output Format

// For each query output YES if it is possible to go from  to  directly without using any other nodes, NO otherwise. Don't forget to put a new line after each query.


#include <bits/stdc++.h>
using namespace std;

int main(){    
    int n,e;
    cin >> n >> e;
    int adj_matrix[n][n];
    memset(adj_matrix,0,sizeof(adj_matrix));

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(i==j)
                adj_matrix[i][j]=1;
            
    while(e--){
        int a,b;
        cin >> a >> b;
        adj_matrix[a][b]=1;
    }
     
    int t;
    cin >> t;
    while(t--){
        int x,y;
        cin >> x >> y;
        if(adj_matrix[x][y])
            cout << "YES" << endl;        
        else
            cout << "NO" << endl;
    }
    
    return 0;
}