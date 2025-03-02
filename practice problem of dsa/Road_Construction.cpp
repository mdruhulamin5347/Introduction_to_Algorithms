

#include <bits/stdc++.h>
using namespace std;
vector<int>group_size(100005,1);
vector<int>par(100005,-1);
int mx,cmpt;

int find(int node){
    if(par[node] == -1) return node;
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

void union_dsu(int node1,int node2){
    int leader1 = find(node1);
    int leader2 = find(node2);
    if(leader1 == leader2){
        return;
    }
    if(group_size[leader1] >= group_size[leader2]){
        group_size[leader1] += group_size[leader2];
        par[leader2] = leader1;
        mx = max(mx,group_size[leader1]);
    }
    else{
        group_size[leader2] += group_size[leader1];
        par[leader1] = leader2;
        mx = max(mx,group_size[leader2]);
    }
    cmpt--;
}

int main(){
    int n,e;
    cin >> n >> e;
    mx = 1;
    cmpt = n;
    while(e--){
        int a,b;
        cin >> a >> b;
        union_dsu(a,b);
        cout << cmpt << " " << mx << endl;
    }
    return 0;
}