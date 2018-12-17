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

/* -----  2018/12/15  Problem: EDU056 G / Link: __CONTEST_URL__  ----- */
/* ------問題------

k次元ベクトルがN個ある。2点間の距離はマンハッタン距離とする。以下のクエリをさばけ。
1. 区間[l..r]のうち最も距離の大きい差
2. 点iのupdate

-----問題ここまで----- */
/* -----解説等-----

これ45度回転事情にあったやつじゃん...
2点間の距離は、2^k個の符号を+-全部やったときのそれぞれのmax-minのうち、最大値.
列の距離の最大値も同様。
知っていればやるだけ…

seg.buildと定数倍の差はない。
**ただし**、PLLとPIIでは二倍の差がある。(まあそれはそうなんですが)

----解説ここまで---- */

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

int read() { int in; scanf("%d", &in); return in; }
int main() {
	int N = read(), K = read();

	static const PII UI = PLL(INF, -INF);
	struct Monoid {
		using type = PII;
		static type id() { return UI; }
		static type op(const type&l, const type&r) {
			return PII(min(l.first, r.first), max(l.second, r.second));
		}
		static type upd(const type&l, const type&r) {
			return r;
		}
	};
	using Seg = SegmentTreeFastAry<Monoid>;
	vector<Seg>segs;
	const int S = 1 << K;
	FOR(i, 0, S) {
		segs.push_back(Seg(N));
	}
	VVI a(N, VI(K));
	FOR(i, 0, N) {
		FOR(k, 0, K) {
			a[i][k] = read();
		}
	}
	FOR(state, 0, S) {
		FOR(i, 0, N) {
			LL val = 0;
			FOR(k, 0, K) {
				if (state & 1 << k) {
					val += a[i][k];
				}
				else {
					val -= a[i][k];
				}
			}
			
			segs[state].update(i, PLL(val, val));
		}
	}
	int Q = read();
	VI b(K);
	FOR(_, 0, Q) {
		int c = read();
		if (c == 1) {
			int pos = read() - 1;
			FOR(i, 0, K) {
				b[i] = read();
			}
			FOR(state, 0, S) {
				LL val = 0;
				FOR(k, 0, K) {
					if (state & 1 << k) {
						val += b[k];
					}
					else {
						val -= b[k];
					}
				}
				segs[state].update(pos, PLL(val, val));
			}
		}
		else {
			int L = read() - 1, R = read();
			int ans = 0;
			FOR(state, 0, S) {
				auto it = segs[state].query(L, R);
				ans = max(ans, it.second - it.first);
			}
			printf("%d\n", ans);
		}
	}


	return 0;
}
