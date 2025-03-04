
#include <bits/stdc++.h>
using namespace std;
vector<int>group_size(10005,1);
vector<int>par(10005,-1);

int find(int node){
    if(par[node] == -1) return node;
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int node1,int node2){
    int leader1 = find(node1);
    int leader2 = find(node2);
    if(group_size[leader1] >= group_size[leader2]){
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    }        
    else {
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }

}

int main(){
    int n;
    vector<pair<int,int>>rmv;
    vector<pair<int,int>>create;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        int leaderA = find(a);
        int leaderB = find(b);

        if (leaderA == leaderB) {
            rmv.push_back({a, b});
        } else {
            dsu_union(a, b);
        }
    }


    for (int i = 2; i <= n; i++) {
        int leader1 = find(1);
        int leader2 = find(i);

        if (leader1 != leader2) {
            create.push_back({1, i});
            dsu_union(1, i);
        }
    }
    cout << rmv.size() << endl;
    for (int i = 0; i < rmv.size(); i++) {
        cout << rmv[i].first << " " << rmv[i].second << " " << create[i].first << " " << create[i].second << endl;
    }
    return 0;
}