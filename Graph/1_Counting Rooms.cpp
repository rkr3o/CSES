#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
#define print(v) for (auto x : v) cout << x << " ";
vector<vector<char>>adj(1000 + 10 , vector<char>(1000 + 10));
vector<vector<int>>vis(1000 + 10 , vector<int>(1000 + 10 , 0));

void dfs(int row , int col , int n , int m)
{

    vis[row][col] = 1;

    int drow[] = { -1, 0, +1, 0};
    int dcol[] = {0, +1, 0, -1};

    for (int i = 0; i < 4; ++i)
    {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if (nrow >= 0  and ncol >= 0 and nrow < n and ncol < m and adj[nrow][ncol] == '.' and !vis[nrow][ncol])
        {
            dfs(nrow, ncol , n , m);
        }
    }
}

void bfs(int row , int col , int n , int m)
{
    queue<pair<int, int>>q;
    q.push({row, col});
    vis[row][col] = 1;

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        int drow[] = { -1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};

        for (int i = 0; i < 4; ++i)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0  and ncol >= 0 and nrow < n and ncol < m and adj[nrow][ncol] == '.' and !vis[nrow][ncol])
            {
                vis[nrow][ncol] = 1;
                q.push({nrow, ncol});
            }
        }
    }
}

int main()
{

    int n , m ;
    cin >> n >> m ;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0 ; j < m ; j++)
        {
            cin >> adj[i][j];
        }
    }

    int cnt = 0 ;
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < m ; j++)
        {
            if (adj[i][j] == '.' and !vis[i][j])
            {
                cnt++;
                bfs(i, j, n, m);

            }
        }
    }

    cout << cnt << endl;

}