

// problem number 3


// Problem Statement

// You are given an  sized 2D matrix that represents a map of a building. Each cell represents a wall, a floor or a room. You will be given two rooms  and . You need to tell if you can go from room  to  by passing through the floors. You can walk left, right, up, and down through the floor cells. You can't pass through walls.

// Input Format

// The first input line has two integers  and : the height and width of the map.
// Then there are  lines of  characters describing the map. Each character is .(floor), #(wall), A or B (rooms).
// Constraints

// Output Format

// Output YES if you can go from room  to , NO otherwise.


#include <bits/stdc++.h>
using namespace std;
int n,m;
char grid[1005][1005];
bool vis[1005][1005];
int level[1005][1005];
vector<pair<int,int>> d = {{-1,0},{0,-1},{1,0},{0,1}};

bool valid(int i,int j){
    if(i<0 || j<0 || i>=n || j>=m){
        return false;
    }
    return true;
}

void dfs(int si,int sj){

    vis[si][sj]=true;    
    level[si][sj]=0;

    for(int i=0; i<4; i++){
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if(!vis[ci][cj] && valid(ci,cj) && grid[ci][cj] != '#'){            
            dfs(ci,cj);         
            level[ci][cj] = level[si][sj] + 1;   
        }
    }
}

int main(){    
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> grid[i][j];


    int si,sj,di,dj;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 'A'){
                si = i;
                sj = j;
            }
            else if(grid[i][j] == 'B'){
                di=i;
                dj=j;
            }
        }       
    }
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));    
    dfs(si,sj);

    if(level[di][dj] == -1)
        cout << "NO";
    else 
        cout << "YES";

    return 0;
}