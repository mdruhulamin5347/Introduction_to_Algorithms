

// problem number 5


// Problem Statement

// You are given an  sized 2D matrix that represents a map of a building. Each cell represents a wall or a room. The connected rooms are called apartments. Your task is to count the number rooms in each of the apartments in that building. You can walk left, right, up, and down through the room cells. You can't pass through walls.

// You need to print the count of the rooms in ascending order. If there are no apartments available in that building, then you should print .

// Input Format

// The first input line has two integers  and : the height and width of the map.
// Then there are  lines of  characters describing the map. Each character is either .(room) or #(wall).
// Constraints

// Output Format

// Output the number of rooms in each of the apartments in ascending order.



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

int dfs(int si,int sj){

    vis[si][sj]=true;
    int node = 1;

    for(int i=0; i<4; i++){
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if(!vis[ci][cj] && valid(ci,cj) && grid[ci][cj]=='.'){            
            node += dfs(ci,cj);
        }
    }
    return node;
}


int main(){    
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }

    memset(vis,false,sizeof(vis));

    vector<int>v;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vis[i][j]==false && grid[i][j]=='.'){
                v.push_back(dfs(i,j));                
            }
        }
    }
    if(v.empty()){
        cout << 0 ;
    }
    sort(v.begin(),v.end());    
    for(int val : v){
        cout << val << " ";
    }   

    return 0;
}