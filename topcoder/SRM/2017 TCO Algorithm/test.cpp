

#include <iostream>
#include <vector>
#include <string.h>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;
ll dp[100010];

ll rec(ll n, vector<ll>& v) {
	if (dp[n] >= 0) { return dp[n]; }
	if (n == v.size() - 1) {
		dp[n] = v[n];
		return v[n];
	}
	ll ans = 0;
	ll res1 = v[n];
	for (int i = n + 1; i < v.size(); i++) {
		ll a = 1 << (v.size() - i - 1);
		ans += res1*(1 << (v.size() - 1 - i)) + rec(i, v);
		ans %= MOD;
		res1 *= v[i];
	}

	ans += res1;
	ans %= MOD;

	return dp[n] = ans;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(dp, -1, sizeof(dp));
		int n; cin >> n;
		vector<ll> v(n);
		for (int i = 0; i < n; i++) cin >> v[i];
		ll ans;
		ans = rec(0, v);
		ans %= MOD;

		/*
		for (int i = 0; i < n;i++) {
		cout << dp[i] << " ";
		}
		cout << endl;
		*/

		cout << ans << endl;
	}
}