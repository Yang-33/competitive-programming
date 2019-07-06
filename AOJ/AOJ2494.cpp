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

/* -----  2019/07/07  Problem: AOJ 2494 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2494  ----- */


vector<int>divs(int n) {
	vector<int>a;
	for (LL i = 1; i*i <= n; i++) {
		if (n%i != 0)continue;
		int d = n / i;
		a.push_back(i);
		if (n%i == 0 && i != d) {
			a.push_back(d);
		}
	}
	return a;
}

template <typename Monoid>
struct SegmentTree {
	using nd = typename Monoid::type;
	const int ARY_SIZE;
	vector<nd>node;
public:
	SegmentTree(int n) :ARY_SIZE(n), node(2 * ARY_SIZE, Monoid::id()) {}
	inline void update(int i, const nd val) {
		i += ARY_SIZE; node[i] = (val);
		while (i > 1) {
			i >>= 1; node[i] = Monoid::op(node[i << 1], node[(i << 1) + 1]);
		}
	}
	inline nd query(int l, int r) {
		if (l >= r)return Monoid::id();
		nd vl = Monoid::id(), vr = Monoid::id();
		for (l += ARY_SIZE, r += ARY_SIZE; l != r; l >>= 1, r >>= 1) {
			if (l & 1) {
				vl = Monoid::op(vl, node[l++]);
			}
			if (r & 1) {
				vr = Monoid::op(node[--r], vr);
			}
		}
		return Monoid::op(vl, vr);
	}
	nd operator[](int i) { return node[i + ARY_SIZE]; }
};

struct Monoid {
	using type = PII;
	static type id() { return PII(0, 0); };
	static type op(const type&l, const type &r) {
		int la = l.first;
		int lb = r.first;
		int cnt = (la >= 2) + (lb >= 2);
		return PII(0, cnt + l.second + r.second);
	}
};

inline int readint() { int in; scanf("%d", &in); return in; }
inline void outint(int out, bool endl = 1) { printf("%d%c", out, " \n"[endl]); }

int main() {
	int N = readint(), W = readint();
	SegmentTree<Monoid> seg(N + 1); // !!!!!!!!!!!!!!!
	if (W == 1) {
		FOR(i, 0, N) {
			outint(1, i == N - 1);
		}
		return 0;
	}

	vector<int>IQ1;
	IQ1.push_back(W);
	FOR(i, 1, W + 1) {
		auto vecs = divs(i);
		for (auto it : vecs) {
			auto a = seg[it];
			seg.update(it, PII(a.first + 1, 0));
		}
	}
	FOR(R, W + 1, N + 1) {
		int L = R - W;
		// dec of L element
		for (auto it : divs(L)) {
			auto a = seg[it];
			seg.update(it, PII(a.first - 1, 0));
		}
		// add R into set
		for (auto it : divs(R)) {
			auto a = seg[it];
			seg.update(it, PII(a.first + 1, 0));
		}

		auto res = seg.query(0, L + 1);
		int cnt = res.second;
		IQ1.push_back(cnt + W);
	}

	FOR(i, 0, SZ(IQ1)) {
		outint(IQ1[i], (i + 1) == SZ(IQ1));
	}
}
