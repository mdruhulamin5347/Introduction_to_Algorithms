
#include <bits/stdc++.h>
using namespace std;

int main(){
    int adj_matrix[105][105];

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(i==j)
                adj_matrix[i][j]=0;
            else
                adj_matrix[i][j]=INT_MAX;
        }    
    }

    int n,e;
    cin >> n >> e;
    while(e--){
        int a,b,c;
        cin >> a >> b >> c;
        adj_matrix[a][b] = c;
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(adj_matrix[i][k] != INT_MAX && adj_matrix[k][j] != INT_MAX && adj_matrix[i][k] + adj_matrix[k][j] < adj_matrix[i][j]){
                    adj_matrix[i][j] = adj_matrix[i][k] + adj_matrix[k][j];
                }
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(adj_matrix[i][j] == INT_MAX)
                cout << "INF" << " ";
            else
                cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}