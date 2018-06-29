#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/06/30  Problem: AOJ 2575 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2575  ----- */
/* ------問題------

アナグラム

-----問題ここまで----- */
/* -----解説等-----

頑張る

----解説ここまで---- */


void solve() {
	const string str = "AIDUNYAN";
	int key[26] = { 0 };
	for (auto c : str) {
		key[c - 'A']++;
	}
	string D; cin >> D;
	vector<vector<int>> cusum(D.length() + 1, vector<int>(26));
	for (int i = 0; i < D.length(); i++) {
		for (int j = 0; j < 26; j++) {
			cusum[i + 1][j] += cusum[i][j];
		}
		cusum[i + 1][D[i] - 'A']++;
	}
	string ans;
	for (int i = 0; i < D.length(); i++) {
		int j = i + str.length();
		if (j > D.length()) {
			ans += D[i];
			continue;
		}
		else {
			bool ok = true;
			for (int k = 0; k < 26; k++) {
				if (cusum[j][k] - cusum[i][k] == key[k]) continue;
				ok = false;
			}
			if (ok) {
				ans += "AIZUNYAN";
				i += str.length() - 1;
			}
			else {
				ans += D[i];
			}
		}
	}
	cout << ans << endl;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	solve();

	return 0;
}