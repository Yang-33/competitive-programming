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
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);

/* -----  2019/07/13  Problem: AOJ 0042 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0042  ----- */
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
	LL W;
	while (cin >> W, W) {
		auto chmax = [](LL& a, const LL b) {
			a = max(a, b);
		};

		int N; cin >> N;
		vector<LL> v(N), w(N);
		for (int i = 0; i < N; ++i) {
			string in; cin >> in;
			auto input = deletecommma(in);
			input >> v[i] >> w[i];
		}
		VL dp(W + 1, 0);
		FOR(i, 0, N) {
			FORR(ww, W - w[i] + 1, 0 - 1) {
				chmax(dp[ww + w[i]], dp[ww] + v[i]);
			}
		}
		LL mx = 0;
		int idx = 0;
		FORR(ww, W, 0 - 1) {
			if (mx <= dp[ww]) {
				mx = dp[ww];
				idx = ww;
			}
		}
		static int id = 1;
		cout << "Case " << id++ << ":\n";
		cout << mx << "\n";
		cout << idx << "\n";
	}

	return 0;
}
