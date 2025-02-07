

// problem number 4

// Problem Statement

// You are given an  sized 2D matrix that represents a map of a building. Each cell represents a wall or a room. The connected rooms are called apartments. Your task is to count the number of apartments in that building. You can walk left, right, up, and down through the room cells. You can't pass through walls.

// Input Format

// The first input line has two integers  and : the height and width of the map.
// Then there are  lines of  characters describing the map. Each character is either .(room) or #(wall).
// Constraints

// Output Format

// Output the number of apartments


#include <bits/stdc++.h>
using namespace std;
int n,m;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>> d = {{-1,0},{0,-1},{1,0},{0,1}};

bool valid(int i,int j){
    if(i<0 || j<0 || i >= n || j >= m)
        return false;
    return true;
}

void dfs(int si,int sj){    

    vis[si][sj]=true;

    for(int i=0; i<4; i++){
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if(!vis[ci][cj] && valid(ci,cj) && grid[ci][cj]=='.'){
            dfs(ci,cj);
        }
    }
}


int main(){    
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }

    memset(vis,false,sizeof(vis));
    int count = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vis[i][j]==false && grid[i][j]=='.'){
                dfs(i,j);
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}