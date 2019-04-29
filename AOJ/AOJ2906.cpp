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

/* -----  2019/04/29  Problem: AOJ 2906 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2906  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL C, N, M; cin >> C >> N >> M;
	vector<LL> s(N), p(N);
	for (int i = 0; i < N; ++i) {
		cin >> s[i] >> p[i];
	}
	auto chmax = [](LL& a, const LL b) {
		a = max(a, b);
	};

	// dp(s):=サイズがsのときの重さの最大値
	VL dp(C + 1, 0);
	FOR(i, 0, N) {
		VL nx = dp;
		FORR(pr, C - s[i], 0 - 1) {
			chmax(nx[pr + s[i]], dp[pr] + p[i]);
		}
		DD(De(nx))
		nx.swap(dp);
	}

	// パラメータをちょうど⇨以下に変更
	FOR(i, 0, C) {
		chmax(dp[i + 1], dp[i]);
	}
	FOR(k, 1, M + 1) {
		int p = C / k;
		DD(de(dp[p],k,p))
		cout << dp[p] * k << endl;
	}


	return 0;
}
