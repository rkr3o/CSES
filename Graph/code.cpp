#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int62_t
#define span(a) begin(a), end(a)
#define ll long long int
#define print(v) for (auto x : v) cout << x << " ";
const int mod = 1e9 + 7;
const int N = 1e5 + 10;


// the maze

bool reachDestination(vector<vector<int>> &maze, int n, int m, int row, int col, int rowend, int colend)
{
    queue<pair<int, int>>q;
    vector<vector<int>>vis(n, vector<int>(m, 0));
    q.push({row, col});
    vis[row][col] = 1;

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if (row == rowend and col == colend)
        {
            return true;
        }

        int drow[] = { -1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};

        for (int i = 0 ; i < 4 ; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            while (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && maze[nrow][ncol] == 0) {
                nrow += drow[i];
                ncol += dcol[i];
            }

            // Comeback one step;
            nrow -= drow[i];
            ncol -= dcol[i];

            if (!vis[nrow][ncol]) {
                vis[nrow][ncol] = 1;
                q.push({nrow, ncol});
            }
        }
    }
    return false;
}
////
void maximumWeightNode()
{
    int n ;
    cin >> n ;
    vector<int>edges(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> edges[i];
    }
    vector<int>weight(n, 0);
    for (int i = 0; i < n; ++i)
    {
        if (edges[i] != -1)
        {
            weight[edges[i]] += i;
        }
    }

    int maxi = -1 ;
    int ind = -1;

    for (int i = n - 1 ; i >= 0 ; i--)
    {
        if (weight[i] > maxi)
        {
            maxi = weight[i];
            ind = i ;
        }
    }

    cout << ind << endl;
}

///largest sum cycle

class DSU
{
private:
    vector<int>parent, size, rank;
public:
    DSU(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        rank.resize(n + 1);
        for (int i = 0 ; i <= n ; i++)
        {
            parent[i] = i;
        }
    }

    //path comression
    int find(int v)
    {
        if (v == parent[v])return v ;

        return parent[v] = find(parent[v]);
    }

    //size
    void UnionBySize(int u , int v)
    {
        u = find(u);
        v = find(v);

        if (u != v)
        {
            if (size[u] < size[v])
            {
                swap(u, v);
            }

            parent[v] = u;
            size[u] += size[v];
        }
    }

    void unionByRank(int u , int v )
    {
        u = find(u);
        v = find(v);
        if (u != v)
        {
            if (rank[u] < rank[v])
            {
                swap(u, v);
            }

            parent[v] = u;

            if (rank[u] == rank[v])
            {
                rank[u]++;
            }
        }
    }
};

class Solution
{


public:
    long long largestSumCycle(int N, vector<int> Edge)
    {
        long long ans = -1;
        DSU dsu(N);
        for (int i = 0; i < N; i++)
        {
            if (Edge[i] == -1) {
                continue;
            }
            int p1 = dsu.find(i);
            int p2 = dsu.find(Edge[i]);
            if (p1 == p2) {
                int curr = i;
                long long sum = 0;
                do {
                    sum += curr;
                    curr = Edge[curr];
                } while (curr != i);
                ans = max(ans, sum);
            }
            dsu.unionByRank(i, Edge[i]);
        }
        return ans;
    }
};
////////////////////////////
//same question using disjoint set

void solve()
{

    // maximumWeightNode();
    largestSumCycle();

}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--)
    {
        solve();
    }
}