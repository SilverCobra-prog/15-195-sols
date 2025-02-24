#include <bits/stdc++.h>
using namespace std;

bool check_seats(long long total, long long maxPeople, vector<long long> seats) {
	for(int i = 0; i < seats.size(); i++) {
		int toSeat = maxPeople - seats[i];
		total -= toSeat;
	}
	// cout << maxPeople << " " << total << endl;
	return total <= 0;
} 

int main() {
	long long n, m;
	cin >> n >> m;
	vector<long long> a(n);
	long long most = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		most = max(most, a[i]);
	}
	int lo = most;
	most += m;
	int hi = most;
	int ans = hi;
	while(lo <= hi) {
		long long mid = lo + (hi - lo + 1) / 2;
		// cout << mid << endl;
        if(check_seats(m, mid, a)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
	}
	cout << ans << " " << most;
	
}
