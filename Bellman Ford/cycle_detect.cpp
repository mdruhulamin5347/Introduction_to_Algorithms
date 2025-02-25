
#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int a,b,c;
    Edge(int a,int b,int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int main(){
    int n,e;
    vector<Edge> edge_list;
    vector<int>dis(1005,INT_MAX);
    cin >> n >> e;
    while(e--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a,b,c));
    }

    dis[0]=0;
    
    for(int i=0; i<n-1; i++){
        for(auto ad : edge_list){
            int a,b,c;
            a = ad.a;
            b = ad.b;
            c = ad.c;
            if(dis[a] != INT_MAX && dis[a] + c < dis[b]){
                dis[b] = dis[a] + c;
            }
        }
    }

    bool cycle = false;
    for(auto ad : edge_list){
        int a,b,c;
        a = ad.a;
        b = ad.b;
        c = ad.c;
        if(dis[a] != INT_MAX && dis[a] + c < dis[b]){
            cycle = true;
            break;
        }
    }

    if(cycle)
        cout << "Cycle is present";
    else 
        cout << "Don't Cycle Available";
    
    return 0;
}