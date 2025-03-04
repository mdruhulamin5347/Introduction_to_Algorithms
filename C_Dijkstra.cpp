#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<pair<ll, ll>> adj_list[100005];
vector<ll> path(100005, LLONG_MAX);
vector<ll> shortest_path(100005, -1);

void dijkstra(ll src) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, src});
    path[src] = 0;

    while (!pq.empty()) {
        pair<ll, ll> par = pq.top();
        pq.pop();
        ll par_dis = par.first;
        ll par_node = par.second;

        if (par_dis > path[par_node]) continue;

        for (auto child : adj_list[par_node]) {
            ll child_node = child.first;
            ll child_dis = child.second;

            if (par_dis + child_dis < path[child_node]) {
                path[child_node] = par_dis + child_dis;
                pq.push({path[child_node], child_node});
                shortest_path[child_node] = par_node;
            }
        }
    }
}

int main() {
    ll n, e;
    cin >> n >> e;

    while (e--) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }

    dijkstra(1);

    if (path[n] == LLONG_MAX) { 
        cout << -1 << endl;
        return 0;
    }

    vector<ll> ans;
    ll node = n;
    while (node != -1) {
        ans.push_back(node);
        node = shortest_path[node];
    }

    reverse(ans.begin(), ans.end());
    for (ll val : ans) {
        cout << val << " ";
    }

    return 0;
}
