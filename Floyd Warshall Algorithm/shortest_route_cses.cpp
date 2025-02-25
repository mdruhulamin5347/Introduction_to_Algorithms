
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,e,q;
    cin >> n >> e >> q;
    long long int dis[n+5][n+5];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j)
                dis[i][j]=0;
            else 
                dis[i][j]=LLONG_MAX;
        }
    }

    while(e--){
        long long int a,b,c;
        cin >> a >> b >> c;
        dis[a][b] = min(dis[a][b],c);
        dis[b][a] = min(dis[a][b],c);
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dis[i][k] != LLONG_MAX && dis[k][j] != LLONG_MAX && dis[i][k] + dis[k][j] < dis[i][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    while(q--){
        int s,d;
        cin >> s >> d;
        if(dis[s][d] == LLONG_MAX) cout << -1 << endl;
        else cout << dis[s][d] << endl;
    }

    return 0;
}