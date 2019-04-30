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

/* -----  2019/04/21  Problem: google_kickstart2019_roundb B / Link: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050eda/00000000001198c3  ----- */
// Evergy Stones

// 比較基準が必要そうなのは分かる．
// 時刻t以降にx,yという選択をする際にどうするのが良いかを式にすると，
// code中の比較関数ができる．
// 貪欲で良いかわからないので一応dpをしておく

void solve(int testcasenum) {

	int N; cin >> N;
	vector<LL>S(N), E(N), L(N);
	for (int i = 0; i < N; ++i) {
		cin >> S[i] >> E[i] >> L[i];
	}

	vector<int> idx(N, 0);
	iota(ALL(idx), 0);
	// t以降にx,yかy,xを使うとして比較するとでてくる
	sort(ALL(idx), [&](int a, int b) {
		return L[a] * S[b] > L[b] * S[a];
	});
	auto chmax = [](LL& a, const LL b) {
		a = max(a, b);
	};

	VL dp(10004, 0);
	for (auto i : idx) {
		FORR(t, SZ(dp) - S[i] - 1, 0 - 1) {
			chmax(dp[t + S[i]], dp[t] + max(0LL, E[i] - L[i] * t));
		}
	}

	LL ans = *max_element(ALL(dp));

	cout << "Case #" << testcasenum << ": " << ans << endl;
}

int main() {

	LL T; cin >> T;
	FOR(_, 0, T) {
		solve(_ + 1);
	}

	return 0;
}
