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

/* -----  2019/07/02  Problem: square869120Contest02 H / Link: https://atcoder.jp/contests/s8pc-2/tasks/  ----- */
template <typename M>
class lazy_segment_tree {
	using T1 = typename M::t1;
	using T2 = typename M::t2;
	const int h, n;
	vector<T1> data;
	vector<T2> lazy;
	void push(int node) {
		if (lazy[node] == M::id2()) return;
		if (node < n) {
			lazy[node * 2] = M::op3(lazy[node * 2], lazy[node]);
			lazy[node * 2 + 1] = M::op3(lazy[node * 2 + 1], lazy[node]);
		}
		data[node] = M::op2(data[node], lazy[node]);
		lazy[node] = M::id2();
	}
	void update(int node) {
		data[node] = M::op1(M::op2(data[node * 2], lazy[node * 2]), M::op2(data[node * 2 + 1], lazy[node * 2 + 1]));
	}
public:
	lazy_segment_tree(int n_)
		: h(ceil(log2(n_))), n(1 << h), data(n * 2, M::id1()), lazy(n * 2, M::id2()) {}
	lazy_segment_tree(int n_, T1 v1)
		: h(ceil(log2(n_))), n(1 << h), data(n * 2, v1), lazy(n * 2, M::id2()) {}
	lazy_segment_tree(const vector<T1>& data_)
		: h(ceil(log2(data_.size()))), n(1 << h), data(n * 2, M::id1()), lazy(n * 2, M::id2()) {
		init(data_);
	}
	void init() {
		for (int i = n - 1; i >= 1; i--) data[i] = M::op1(data[i * 2], data[i * 2 + 1]);
	}
	void init(const vector<T1>& data_) {
		for (int i = 0; i < (int)data_.size(); i++) data[i + n] = data_[i];
		init();
	}
	void update(int l, int r, T2 val) {
		r--;
		l += n, r += n;
		for (int i = h; i > 0; i--) push(l >> i), push(r >> i);
		int tl = l, tr = r;
		r++;
		while (l < r) {
			if (l & 1) lazy[l] = M::op3(lazy[l], val), l++;
			if (r & 1) r--, lazy[r] = M::op3(lazy[r], val);
			l >>= 1; r >>= 1;
		}
		while (tl >>= 1, tr >>= 1, tl) {
			if (lazy[tl] == M::id2()) update(tl);
			if (lazy[tr] == M::id2()) update(tr);
		}
	}
	T1 query(int l, int r) {
		r--;
		l += n, r += n;
		for (int i = h; i > 0; i--) push(l >> i), push(r >> i);
		r++;
		T1 res1 = M::id1(), res2 = M::id1();
		while (l < r) {
			if (l & 1) res1 = M::op1(res1, M::op2(data[l], lazy[l])), l++;
			if (r & 1) r--, res2 = M::op1(M::op2(data[r], lazy[r]), res2);
			l >>= 1; r >>= 1;
		}
		return M::op1(res1, res2);
	}
};

void solve_s8pc_2H() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	struct XOR_FLIP {
		using ll = long long;
		using t1 = struct st {
			ll sz, val;
			st(ll a = 1, ll b = 0) :sz(a), val(b) {}
		};
		using t2 = ll;
		static t1 id1() { return st(0, 0); }
		static t2 id2() { return 0; }
		static t1 op1(const t1& l, const t1& r) {
			return t1(l.sz + r.sz, l.val + r.val);
		}
		static t1 op2(const t1& l, const t2& r) {
			if (r) {
				return t1(l.sz, l.sz - l.val);
			}
			else {
				return l;
			}
		}
		static t2 op3(const t2& l, const t2& r) {
			return l ^ r;
		}
	};
	vector<XOR_FLIP::t1>init_data(N);
	lazy_segment_tree<XOR_FLIP> seg(init_data);
	FOR(i, 0, Q) {
		int c, x, y;
		scanf("%d%d%d", &c, &x, &y);
		if (c == 1) { // upd
			seg.update(x, y, 1);
		}
		else { // query
			printf("%lld\n", seg.query(x, y).val);
		}
	}
}
int main() {
	solve_s8pc_2H();

	return 0;
}
