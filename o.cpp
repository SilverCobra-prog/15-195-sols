#include <bits/stdc++.h>
using namespace std;

int main() {
	int a; cin >> a;
	while(a--) {
		int n; cin >> n;
		string s; cin >> s;
		string t; cin >> t;
		bool works = false;
		for(int i = 0; i < n; i++) {
			if(t[i]=='o') {
				works = true;
			} 
		}
		if(works) cout << "YES" << endl; 
		else cout << "NO"  << endl;
	}
}
