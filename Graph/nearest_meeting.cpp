#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> edges(N);
    for (int i = 0; i < N; i++)
        cin >> edges[i];

    int C1, C2;
    cin >> C1 >> C2;

    queue<int> q1, q2;
    vector<int> dist1(N, INT_MAX), dist2(N, INT_MAX);

    q1.push(C1);
    dist1[C1] = 0;
    q2.push(C2);
    dist2[C2] = 0;

    while (!q1.empty() || !q2.empty()) {
        if (!q1.empty()) {
            int curr1 = q1.front();
            q1.pop();
            if (dist2[curr1] != INT_MAX) {
                cout << curr1 << endl;
                return 0;
            }
            int next1 = edges[curr1];
            if (next1 != -1 && dist1[next1] == INT_MAX) {
                dist1[next1] = dist1[curr1] + 1;
                q1.push(next1);
            }
        }

        if (!q2.empty()) {
            int curr2 = q2.front();
            q2.pop();
            if (dist1[curr2] != INT_MAX) {
                cout << curr2 << endl;
                return 0;
            }
            int next2 = edges[curr2];
            if (next2 != -1 && dist2[next2] == INT_MAX) {
                dist2[next2] = dist2[curr2] + 1;
                q2.push(next2);
            }
        }
    }

    cout << "-1" << endl;
    return 0;
}


//////////////////////////
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
const int inf = 1e9;

void Dijkstra(int s, vector<vpii> &adj, vi &d) {
    int n = adj.size();
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    d.assign(n, inf);
    d[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().second;
        int d_u = pq.top().first;
        pq.pop();
        if (d_u != d[u]) continue;
        for (auto &v : adj[u]) {
            int to = v.first;
            int len = v.second;
            if (d[to] > d[u] + len) {
                d[to] = d[u] + len;
                pq.push({d[to], to});
            }
        }
    }
}

int minimumWeight(int n, vector<int> &edges, int C1, int C2) {
    // Create directed graph from the array given in input
    vector<vpii> graph(n);
    for (int i = 0; i < n; i++) {
        if (edges[i] == -1) continue;
        graph[i].push_back({edges[i], 1});
    }
    // Create two arrays A and B for storing min distance from C1 and C2
    vi A(n), B(n);
    // Part 1 and Part 2 of Algo -> Implement a dijkstra function and call it for both arrays A and B
    Dijkstra(C1, graph, A);
    Dijkstra(C2, graph, B);
    // Now comes Part 3 part of algo -> loop through and get node with min(A[i]+B[i])
    int node = -1, dist = inf;
    for (int i = 0; i < n; i++) {
        // if node is not accessible from any of them ignore it
        if (A[i] == inf || B[i] == inf) continue;
        if (dist > A[i] + B[i]) {
            dist = A[i] + B[i];
            node = i;
        }
    }
    return node;
}

int main() {
    int n;
    cin >> n;
    vector<int> edges(n);
    for (int i = 0; i < n; i++) cin >> edges[i];
    int C1, C2;
    cin >> C1 >> C2;
    int ans = minimumWeight(n, edges, C1, C2);
    cout << ans << endl;
    return 0;
}

