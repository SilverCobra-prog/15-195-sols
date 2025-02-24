#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
	int n;  cin >> n;
	int count = 0;
	int total = 0;
	unordered_map<string, int> socks; 
	unordered_map<string, bool> any; 
	vector<string> types;
	while(n--){
		string i, j; cin >> i >> j;
		int k; cin >> k;
		if(j=="any"){
			count++;
			any[i] = true;
		} 
		else {
			if(socks[i]==0) {
				types.push_back(i);
			}
			if(k > socks[i]) {
				socks[i] = k;
			}
		}
		total += k;
	}
	for(int i = 0; i < types.size(); i++) {
		count += socks[types[i]];
		if(any[types[i]]) count--;
	}
	if(count==total) cout << "impossible";
	else cout << count+1;
}
