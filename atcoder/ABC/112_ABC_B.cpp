#include <bits/stdc++.h>
using namespace std;
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, T; cin >> N >> T;
	int ans = 100000;
	FOR(i, 0, N) {
		int a, b; cin >> a >> b;
		if (b <= T) {
			ans = min(ans, a);
		}
	}
	if (ans == 100000) {
		cout << "TLE" << endl;
	}else 
	cout << ans << "\n";

	return 0;
}
