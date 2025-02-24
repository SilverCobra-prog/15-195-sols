#include <bits/stdc++.h>
#include <climits>
using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;

int main() {
    int n, m; vvc G;
    cin >> n >> m;
    G = vvc(n, vc(0));
    for (int i = 0; i < n; i++) {
        int u, v; cin >> u >> v; u--; v--;
        G[u].push_back(v); G[v].push_back(u);
    }

    int cnt = 0;

        while (!q.empty()) {
            cnt++;
            int v = q.front(); q.pop();
            for (auto &w : G[v]) {
                if (dist[w] == INT_MAX) {
                    dist[w] = (dist[v] + 1);
                    q.push(w);
                }
            }
        }
    cout << dist[n-1]-1;
}