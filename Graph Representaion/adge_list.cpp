

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,e;
    cin >> n >> e;

    vector<pair<int,int>> adge_list;

    while(e--){
        int a,b;
        cin >> a >> b;
        adge_list.push_back({a,b});
    }

    for(auto p : adge_list){
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}