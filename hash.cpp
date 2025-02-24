#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main() {
    int p; cin >> p;
    int n; cin >> n;
    int cnt = 1;
    unordered_map<int, bool> found;
    bool cool = false;
    for(int i = 0; i < n; i++) {
        int x; cin >> x; 
        if(found[x%p]) {
            cout << cnt;
            cool = true;
            break;
        } else {
            found[x%p] = true;
            cnt++;
        }
    }
    if(!cool) cout << -1;
}