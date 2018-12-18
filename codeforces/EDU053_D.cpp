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

/* -----  2018/10/25  Problem: EDU053 D / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

2分間に合わなかった…
今いる場所から1周以上できるのなら、ムダなのでn周する。
すると、どこかで行き止まるので移動する。
これを繰り返す。

----解説ここまで---- */


template<typename Monoid>
struct SegmentTreeFastAry {
	using nd = typename Monoid::type;
	const int ARY_SIZE;
	vector<nd> node;
	int init(int n) { int sz = 1; while (sz < n) sz <<= 1; return sz; }
public:
	SegmentTreeFastAry(int n) : ARY_SIZE(init(n)), node(2 * ARY_SIZE, Monoid::id()) {}
	inline void update(int i, const nd val) {
		i += ARY_SIZE; node[i] = Monoid::upd(node[i], val);
		while (i > 1) { i >>= 1;	node[i] = Monoid::op(node[i << 1], node[(i << 1) + 1]); }
	}
	inline nd query(int l, int r) {
		if (l >= r) return nd(); nd vl = nd(), vr = nd();
		for (l += ARY_SIZE, r += ARY_SIZE; l != r; l >>= 1, r >>= 1) {
			if (l & 1) vl = Monoid::op(vl, node[l++]); if (r & 1) vr = Monoid::op(node[--r], vr);
		}	return Monoid::op(vl, vr);
	}
	nd operator[](int i) { return node[i + ARY_SIZE]; }
	void debugShow() { for (int i = ARY_SIZE; i < ARY_SIZE << 1; ++i) cerr << node[i].v << " "; cerr << "\n"; }
};

struct Monoid {
	struct type {
		LL val;
		LL mx;
		int id;
		type(LL a = 0, LL b = 0, int id = 0) :val(a), mx(b), id(id) {}
	};
	static type id() { return type(0, 0); }
	static type op(const type&l, const type&r) {
		type a;
		if (l.mx >= r.mx) {
			a.mx = l.mx;
			a.id = l.id;
		}
		else {
			a.mx = r.mx;
			a.id = r.id;
		}
		a.val = l.val + r.val;
		return a;
	}
	static type upd(const type&l, const type&r) {
		return r;
	}
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;
	cin >> N;
	LL T; cin >> T;
	VL a(N);
	LL ans = 0;
	SegmentTreeFastAry<Monoid> seg(N);
	FOR(i, 0, N) {
		cin >> a[i];
		seg.update(i, Monoid::type(a[i], a[i], i));
	}
	VI del(N, 0);
	// n回取り除けば良い
	int pos = 0;
	FOR(i, 0, N) {
		auto it = seg.query(0, N);
		DD(de(it.val, it.mx, it.id));
		LL sum = it.val;
		if (sum <= T) {
			LL div = T / sum;
			DD(de(div));
			ans += div * (N - i);
			T -= div * sum;
		}
		// 移動する
		for (;; pos++, pos %= N) {
			DD(de(pos));
			if (del[pos])continue;
			if (a[pos] <= T) {
				T -= a[pos];
				ans++;
			}
			else break;
		}
		// posで止まっているらしい
		DD(de(pos));

		// ithmaxの削除
		seg.update(it.id, Monoid::type(0, 0, 0));
		del[it.id] = 1;
		DD(de(ans));
	}

	cout << ans << "\n";

	return 0;
}
