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

/* -----  2019/03/05  Problem: ABC 095 D / Link: http://abc095.contest.atcoder.jp/tasks/abc095_d  ----- */

template<typename Monoid>
struct SegmentTreeFastAry {
	using nd = typename Monoid::type;
	const int ARY_SIZE;
	vector<nd> node;
public:
	SegmentTreeFastAry(int n) : ARY_SIZE(n), node(2 * ARY_SIZE, Monoid::id()) {}
	inline void update(int i, const nd val) {
		i += ARY_SIZE; node[i] = Monoid::upd(node[i], val);
		while (i > 1) { i >>= 1;	node[i] = Monoid::op(node[i << 1], node[(i << 1) + 1]); }
	}
	inline nd query(int l, int r) {
		if (l >= r) return Monoid::id(); nd vl = Monoid::id(), vr = Monoid::id();
		for (l += ARY_SIZE, r += ARY_SIZE; l != r; l >>= 1, r >>= 1) {
			if (l & 1) vl = Monoid::op(vl, node[l++]); if (r & 1) vr = Monoid::op(node[--r], vr);
		}	return Monoid::op(vl, vr);
	}
	nd operator[](int i) { return node[i + ARY_SIZE]; }
	void debugShow() { for (int i = ARY_SIZE; i < ARY_SIZE << 1; ++i) cerr << node[i] << " "; cerr << "\n"; }
};


struct Cumusum {
	vector<LL>csum;
	Cumusum(vector<LL>&a) {
		csum.assign((int)a.size() + 1, 0);
		for (int i = 0; i < (int)a.size(); i++) {
			csum[i + 1] = csum[i] + a[i];
		}
	}
	LL query(int l, int r) {
		return csum[r] - csum[l];
	}
};
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	struct MaxUpd {
		using type = LL;
		static type id() { return 0; }
		static type op(const type&l, const type&r) {
			return max(l, r);
		}
		static type upd(const type&l, const type&r) {
			return r;
		}
	};

	LL N, C; cin >> N >> C;
	vector<LL> x(N + 2), add(N + 2);
	for (int i = 0; i < N; ++i) {
		cin >> x[i + 1] >> add[i + 1];
	}
	VL a(N + 1); {
		FOR(i, 1, N + 1) {
			a[i] = add[i] - (x[i]-x[i-1]);
		}
	}
	Cumusum cumToR(a);
	SegmentTreeFastAry<MaxUpd>segToR(N + 10); {
		FOR(i, 0, N + 1) {
			segToR.update(i, cumToR.query(0, i + 1) - x[i]);
		}
	}
	{ // rev
		FOR(i, 1, N + 1) {
			x[i] = C - x[i];
		}
		reverse(ALL(x));
		reverse(ALL(add));
	}
	VL b(N + 1); {
		FOR(i, 1, N + 1) {
			b[i] = add[i] - (x[i]-x[i-1]);
		}
	}
	Cumusum cumToL(b);
	SegmentTreeFastAry<MaxUpd> segToL(N + 10); {
		FOR(i, 0, N + 1) {
			segToL.update(i, cumToL.query(0, i + 1) - x[i]);
		}
	}

	LL ans = 0;
	FOR(i, 0, N + 1) {
		{
			LL sub = cumToR.query(0, i + 1);
			sub += max(0LL, segToL.query(0, N - i+1));
			ans = max(ans, sub);
		}
		{
			LL sub = cumToL.query(0, i + 1);
			sub += max(0LL, segToR.query(0, N - i+1));
			ans = max(ans, sub);
		}
	}



	cout << (ans) << "\n";

	return 0;
}
