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

/* -----  2019/05/25  Problem: ABC 127 C / Link: http://abc127.contest.atcoder.jp/tasks/abc127_c  ----- */

using T = LL;
pair<T, T>common_range(vector<pair<T, T>> seg) {
	T L = seg.front().first;
	T R = seg.front().second;
	for (auto &&it : seg) {
		L = max(L, it.first);
		R = min(R, it.second);
	}
	return pair<T, T>(L, R);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;
	vector<LL> L(M), R(M);
	vector<PLL>s;
	for (int i = 0; i < M; ++i) {
		cin >> L[i] >> R[i];
		s.push_back(PLL(L[i], R[i]));
	}
	auto it = common_range(s);
	LL ans = it.second - it.first + 1;
	if (ans < 0)ans = 0;


	cout << (ans) << "\n";

	return 0;
}
