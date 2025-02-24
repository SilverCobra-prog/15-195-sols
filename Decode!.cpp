#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    int n, m; vvi G;
    cin >> n >> m;
    G = vvi(26, vi());
    for (int i = 0; i < n; i++) {
        char l1, l2;
        cin >> l1; cin >> l2;
        int pos1 = l1 - 'a';
        int pos2 = l2 - 'a';
        G[pos1].push_back(pos2); 
    }

    while(m--) {
        string w1, w2;
        cin >> w1 >> w2;
        if(w1.size()!=w2.size()) {
            cout << "no" << endl;
            continue;
        }
        bool works = true;
        for(int i = 0; i < w1.size(); i++) {
            vector<bool> found(1000, false);
            int u = w1[i] - 'a';
            int x = w2[i] - 'a';
            queue<int> q; q.push(u); found[u] = true;
            while (!q.empty()) {
                int v = q.front(); q.pop();
                for (auto &w : G[v]) {
                    if (!found[w]) {
                        found[w] = true;
                        q.push(w);
                    }
                }
            }
            if(!found[x]) {
                works = false;
                break;
            }
        }
        if(works) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}