#include "bits/stdc++.h"
 
using namespace std;

bool yes (long long k, vector<long long> &a, int cow) {
	long long last_cow = a[1];
	--cow;
	for (int i = 2; i < (int) a.size(); ++i) {
		if (a[i] - last_cow >= k) {
			last_cow = a[i];
			--cow;
		}
	}
	return cow <= 0;
}
 
int main () {
	 ios::sync_with_stdio(false);
	 cin.tie(nullptr);
	 cout.tie(nullptr);
	 int T;
	 cin >> T;
	 for (int test_case = 1; test_case <= T; ++test_case) {
		 int n, c;
		 cin >> n >> c;
		 vector<long long> a(n + 1);
		 for (int i = 1; i <= n; ++i) {
			 cin >> a[i];
		 }
		 sort (a.begin() + 1, a.end());
		 long long  l = 0, r = 1e15, res = 0;
		 while (l <= r) {
			 long long mid = l + (r - l) / 2;
			 if (yes(mid, a, c)) {
				 res = mid;
				 l = mid + 1;
			 } else {
				 r = mid - 1;
			 }
		 }
		 cout << res << '\n';
	 }
}
