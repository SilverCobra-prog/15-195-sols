#include <bits/stdc++.h>
using namespace std;

int main() {
	int r, c, k;
	cin >> r >> c >> k;
	vector<string> led(r); 
	vector<string> pattern(r); 
	bool works = true;
	vector<bool> missing(r, false);
	for(int i = 0; i < r; i++) {
		cin >> led[i];
		cin >> pattern[i];
		for(int j = 0; j < c; j++) {
			if(led[i][j]=='-') missing[i]=true;
		}
		for(int j = 0; j < k; j++) {
			if(pattern[i][j]=='*' && missing[i]) works = false;
		}
	}
	if(works) cout << "Y";
	else cout << "N";
}
