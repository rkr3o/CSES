#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1000001];

void addEdge(int u, int v) {
    adj[u].push_back(v);
}

void dfs(int src, unordered_set<int>& visited) {
    visited.insert(src);
    for(int i=0; i<adj[src].size(); i++) {
        int neighbor = adj[src][i];
        if(visited.count(neighbor) == 0) {
            dfs(neighbor, visited);
        }
    }
}

int main() {
    int n, e;
    cin >> n;
    unordered_map<int, int> ids;
    for(int i=0; i<n; i++) {
        int id;
        cin >> id;
        ids[id] = i; // assign a unique id to each member
    }

    cin >> e;
    for(int i=0; i<e; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(ids[u], ids[v]); // add edges between members
    }

    int src, dest;
    cin >> src >> dest;

    // perform dfs to check reachability
    unordered_set<int> visited;
    dfs(ids[src], visited);

    if(visited.count(ids[dest]) == 1) {
        cout << 1 << endl; // src can reach dest
    } else {
        cout << 0 << endl; // src cannot reach dest
    }
    return 0;
}
