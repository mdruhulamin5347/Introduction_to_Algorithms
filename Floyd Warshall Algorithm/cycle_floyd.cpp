

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,e;
    cin >> n >> e;
    int adj_m[n+5][n+5];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j)
                adj_m[i][j]=0;
            else
                adj_m[i][j]=INT_MAX;
        }
    }

    while(e--){
        int a,b,c;
        cin >> a >> b >> c;
        adj_m[a][b]=c;
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(adj_m[i][k] != INT_MAX && adj_m[k][j] != INT_MAX && adj_m[i][k] + adj_m[k][j] < adj_m[i][j]){
                    adj_m[i][j] = adj_m[i][k] + adj_m[k][j];
                }
            }
        }
    }


    bool cycle = false;

    for(int i=0; i<n; i++){
        if(adj_m[i][i] < 0){
            cycle =true;
            break;
        }
    }

    if(cycle)
        cout << "cycle is present";
    else
        cout << "don't available cycle";

    return 0;
}