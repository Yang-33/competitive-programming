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
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/10/23  Problem: ARC 100 C / Link: http://arc100.contest.atcoder.jp/tasks/arc100_c  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

bitのsubst

----解説ここまで---- */

template<typename F>
vector<typename F::t> ZetaTransformSubset(const int n, const vector<typename F::t>& A) {
	using T = typename F::t;
	vector<T>a = A;
	for (int i = 0; i < n; i++) {
		for (int s = 0; s < 1 << n; s++) {
			if ((s >> i & 1) == 1)
				a[s] = F::op(a[s], a[s ^ (1 << i)]);
		}
	}
	return a;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	int M = 1 << N;
	vector<PII> a(M);
	FOR(i, 0, M) {
		cin >> a[i].first; a[i].second = 0;
	}
	struct F {
		using t = PII;
		F() {}
		static t op(const t& a, const t& b) {
			t ret;
			int x[4];
			x[0] = a.first, x[1] = a.second, x[2] = b.first, x[3] = b.second;
			sort(x, x + 4);
			ret.first = x[3], ret.second = x[2];
			return ret;
		}
	};
	vector<PII> b = ZetaTransformSubset<F>(N, a);

	int ans = 0;
	FOR(i, 1, M) {
		ans = max(ans, b[i].first + b[i].second);
		cout << ans << "\n";
	}

	return 0;
}
