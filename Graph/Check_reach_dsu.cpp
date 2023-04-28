#include<bits/stdc++.h>
using namespace std;

// check reachability
class DSU {
private:
    vector<int> parent, size, rank;
public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        rank.resize(n + 1);
        for (int i = 0 ; i <= n ; i++) {
            parent[i] = i;
        }
    }

    int find(int v) {
        if (v == parent[v]) {
            return v;
        }
        return parent[v] = find(parent[v]);
    }

    void unionBySize(int u , int v) {
        u = find(u);
        v = find(v);

        if (u != v) {
            if (size[u] < size[v]) {
                swap(u, v);
            }

            parent[v] = u;
            size[u] += size[v];
        }
    }

    void unionByRank(int u , int v) {
        u = find(u);
        v = find(v);

        if (u != v) {
            if (rank[u] < rank[v]) {
                swap(u, v);
            }

            parent[v] = u;

            if (rank[u] == rank[v]) {
                rank[u]++;
            }
        }
    }
};

int main() {
    int n;
    cin >> n;

    DSU dsu(n);

    unordered_map<int, int> mp;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        mp[x] = i;
    }

    int e;
    cin >> e;

    for (int i = 0; i < e; ++i) {
        int x, y;
        cin >> x >> y;
        dsu.unionByRank(mp[x], mp[y]);
    }

    int a, b;
    cin >> a >> b;

    if (dsu.find(mp[a]) == dsu.find(mp[b])) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}

