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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e7;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);

/* -----  2019/07/19  Problem: AOJ 0089 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0089  ----- */

stringstream deletecommma(string line) {
	istringstream ss(line);
	string s;
	stringstream input;
	while (getline(ss, s, ',')) {
		input << s; input << " ";
	}
	return input;
}
int main() {
	vector<string> vs; {
		string s;
		while (cin >> s) {
			vs.push_back(s);
		}
	}
	int h = (int)vs.size();
	int w = (h + 1) / 2;
	vector<vector<int>> v(h, vector<int>(w, -INF));
	FOR(i, 0, (int)vs.size()) {
		int j = 0;
		auto input = deletecommma(vs[i]);
		int num;
		while (input >> num) {
			v[i][j++] = num;
		}
	}
	vector<vector<int>> dp(h, vector<int>(w, -INF));
	dp[0][0] = v[0][0];

	for (int i = 1; i < h; i++) {
		if (i <= w - 1) {
			FOR(j, 0, w) {
				int t = dp[i - 1][j];
				if (j - 1 >= 0)t = max(t, dp[i - 1][j - 1]);
				dp[i][j] = t + v[i][j];
			}
		}
		else {
			FOR(j, 0, w) {
				int t = dp[i - 1][j];
				if (j + 1 < w)t = max(t, dp[i - 1][j + 1]);
				dp[i][j] = t + v[i][j];
			}
		}
	}
	cout << dp[h - 1][0] << endl;
	return 0;
}
