#include <bits/stdc++.h>
using namespace std;

vector<int> getdivisor(int n) {
	vector<int> res;
	for (long long  i = 1; i*i <= n; i++) {
		if (n%i == 0) {
			res.push_back(i);
			if (n / i != i)res.push_back(n / i);
		}
	}
	sort(res.begin(), res.end());
	return res;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	long long N, M; cin >> N >> M;
	vector<int> divs = getdivisor(M);
	int ans = 0;
	for (int div : divs) {
		long long x = M / div;
		if (x >= N) {
			ans = max(ans, div);
		}
	}
	
	
	
	cout << ans << "\n";

	return 0;
}
