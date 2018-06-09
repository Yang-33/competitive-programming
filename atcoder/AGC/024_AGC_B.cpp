#include <bits/stdc++.h>
using namespace std;

#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)

// これちょっとむずい
// LISっぽいなあとは思うけどなんかうまくいかない。
// 単調増加でない部分は移動させなければならないことに気がつくと、最大の長さの増加列を残して他の部分は移動させなければならないことに気がつく。
// 考察10割

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	
	int ans = 0;

	vector<long long> a(N);
	vector<long long> p(N);
	FOR(i, 0, N) {
		cin >> a[i];
		a[i] --;
		p[a[i]] = i;
	}

	int r = 1;
	ans = 1;
	FOR(i, 1, N) {
		if (p[i] > p[i - 1]) {
			r++;
		}
		else {
			r = 1;
		}
		ans = max(ans, r);
	}
	cout << N - ans << endl;
	return 0;
}
