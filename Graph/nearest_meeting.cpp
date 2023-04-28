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
