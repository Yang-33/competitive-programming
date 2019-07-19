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

/* -----  2019/07/20  Problem: AOJ 0099 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0099  ----- */
inline int readint() { int in; scanf("%d", &in); return in; }
inline void outint(int out, bool endl = 1) { printf("%d%c", out, " \n"[endl]); }

template<typename Monoid>
struct SegmentTreeFastAry {
	using nd = typename Monoid::type;
	const int ARY_SIZE;
	vector<nd> node;
public:
	SegmentTreeFastAry(int n) : ARY_SIZE(n), node(2 * ARY_SIZE, Monoid::id()) {}
	void set_val(int i, const nd val) {
		i += ARY_SIZE; node[i] = val;
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

struct Monoid {
	using type = PLL;
	static type id() { return PLL(-1, INF); }
	static type op(const type&l, const type&r) {
		PLL ret;
		if (l.first == r.first) {
			ret.first = l.first;
			ret.second = min(l.second, r.second);
		}
		else if (l.first > r.first) {
			ret = l;
		}
		else {
			ret = r;
		}
		return ret;
	}
};

int main() {
	int N = readint(), Q = readint();
	SegmentTreeFastAry<Monoid> seg(N);
	FOR(i, 0, N)seg.set_val(i, PLL(0, i));
	FOR(_, 0, Q) {
		int a = readint() - 1, b = readint();
		auto it = seg[a];
		it.first += b;
		seg.set_val(a, it);
		auto ans = seg.query(0, N);
		cout << ans.second+1 << " " << ans.first << "\n";
	}

	return 0;
}
