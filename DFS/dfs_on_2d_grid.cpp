
#include <bits/stdc++.h>
using namespace std;

int n,m;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>> d = {{-1,0},{0,-1},{1,0},{0,1}};

bool valid(int i,int j){
    if(i<0 || j<0 || i>=n || j>=m)
        return false;
    return true;
}

void dfs(int si, int sj){
    cout << si << " " << sj << endl;
    vis[si][sj]=true;
    
    for(int i=0; i<4; i++){
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if(vis[ci][cj]==false && valid(ci,cj)==true){
            dfs(ci,cj);            
        }
    }
}

int main(){
    
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> grid[i][j];
    
    memset(vis,false,sizeof(vis));

    int si,sj;
    cin >> si >> sj;
    dfs(si,sj);
    
    return 0;
}