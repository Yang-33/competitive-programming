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

/* -----  2019/05/26  Problem: ABC 128 E / Link: http://abc128.contest.atcoder.jp/tasks/abc128_e  ----- */
using ll = long long;
template <typename M>
class dynamic_lazy_segment_tree {
	using T1 = typename M::t1;
	using T2 = typename M::t2;
	const ll n;
	class node {
	public:
		T1 val; T2 lazy;
		node *l, *r;
		node() {}
		node(T1 val_, T2 lazy_, node* l_ = nullptr, node* r_ = nullptr) : val(val_), lazy(lazy_), l(l_), r(r_) {}
		void init(T1 val_, T2 lazy_, node* l_ = nullptr, node* r_ = nullptr) {
			val = val_;
			lazy = lazy_;
			l = l_;
			r = r_;
		}
	};
	node* root;
	vector<node> pool;
	int it;
	ll size(ll n) {
		ll res = 1;
		while (res < n) res <<= 1;
		return res;
	}
	node *new_node() {
		pool[it].init(M::id1(), M::id2());
		if (it > 2e7)assert(0);
		return &pool[it++];
	}
	node *push(node *t, ll lb, ll ub) {
		if (t == nullptr || t->lazy == M::id2()) return t;
		if (lb + 1 < ub) {
			if (t->l == nullptr) t->l = new_node();
			if (t->r == nullptr) t->r = new_node();
			t->l->lazy = M::op3(t->l->lazy, t->lazy);
			t->r->lazy = M::op3(t->r->lazy, t->lazy);
		}
		t->val = M::op2(t->val, t->lazy, lb, ub);
		t->lazy = M::id2();
		return t;
	}
	node *suc(ll l, ll r, node *t, ll lb, ll ub, T2 val) {
		if (ub <= l || r <= lb) return t;
		if (t == nullptr) t = new_node();
		if (l <= lb && ub <= r) {
			t->lazy = M::op3(t->lazy, val);
			return t;
		}
		t = push(t, lb, ub);
		ll c = (lb + ub) / 2;
		t->l = suc(l, r, t->l, lb, c, val);
		t->r = suc(l, r, t->r, c, ub, val);
		t->val = M::op1(t->l == nullptr ? M::id1() : M::op2(t->l->val, t->l->lazy, lb, c), t->r == nullptr ? M::id1() : M::op2(t->r->val, t->r->lazy, c, ub));
		return t;
	}
	T1 sub(ll l, ll r, node *t, ll lb, ll ub) {
		if (t == nullptr || ub <= l || r <= lb) return M::id1();
		t = push(t, lb, ub);
		if (l <= lb && ub <= r) return t->val;
		ll c = (lb + ub) / 2;
		return M::op1(sub(l, r, t->l, lb, c), sub(l, r, t->r, c, ub));
	}
public:
	dynamic_lazy_segment_tree(ll n_, int PMAX = 4e7)
		: n(size(n_)), root(nullptr), pool(PMAX), it(0) {}
	void update(ll l, ll r, T2 val) {
		root = suc(l, r, root, 0, n, val);
	}
	T1 query(ll l, ll r) {
		return sub(l, r, root, 0, n);
	}
};

// fill min
struct Monoid {
	using ll = long long;
	using t1 = ll;
	using t2 = ll;
	static t1 id1() { return LINF; }
	static t2 id2() { return -LINF; }
	static t1 op1(const t1& l, const t1& r) { return min(l, r); }
	static t1 op2(const t1& l, const t2& r, ll Ls, ll Rs) { return r != id2() ? r : l; }
	static t2 op3(const t2& l, const t2& r) { return r != id2() ? r : l; }
};

dynamic_lazy_segment_tree<Monoid> seg(1e18);


// 安心信頼のね
#include<chrono>
#include<random>
struct randgen {
	mt19937_64 rng;
	randgen() :rng((int)std::chrono::steady_clock::now().time_since_epoch().count()) {}
	LL getrand(LL s, LL t) { //[s,t)の乱数を得る
		return rng() % (t - s) + s;
	}
};


void test() {
	int N = 100;
	int Q = 10000;
	cout << N << " " << Q << endl;
	randgen r;
	FOR(i, 0, N) {
		int s = r.getrand(0, 1000000);
		int t = s + r.getrand(1, 1000000);
		int x = r.getrand(0, 1000000);
		cout << s << " " << t << " " << x << endl;
	}
	FOR(i, 0, Q) {
		int x = r.getrand(0, 100000);
		cout << x << endl;
	}
}
const LL geta = 5LL * INF;
void naive() {
	LL N, Q; cin >> N >> Q;

	using tp = tuple<LL, LL, LL>;
	vector<tp>a(N);
	vector<tp>b;
	FOR(i, 0, N) {
		// xがあれ．
		LL s, t, x; cin >> s >> t >> x;
		s -= x + 1;
		t -= x + 1;
		a[i] = tp(s, t, x);
		DD(de(s, t, x));
		s += geta;
		t += geta;
		b.push_back(tp(x, s, t));
	}
	RSORT(b);
	FOR(i, 0, N) {
		LL x, s, t;
		tie(x, s, t) = b[i];
		seg.update(s, t + 1, x);
	}
	FOR(i, 0, Q) {
		LL d; cin >> d;
		LL res1 = LINF;
		FOR(j, 0, N) {
			LL s, t, x;
			tie(s, t, x) = a[j];
			if (s <= d && d <= t)res1 = min(res1, x);
		}
		d += geta;
		LL res = seg.query(d, d + 1);
		if (res1 != res) {
			DD(de(d, res1, res));
		}
		assert(res1 == res);
		if (res1 == LINF)cout << -1 << endl;
		else cout << res << endl;

	}

}

// カス
int main() {
	//DD(test(); return 0;)
	//DD(naive(); return 0;)
		cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, Q; cin >> N >> Q;

	// 区間． fill min
	using tp = tuple<LL, LL, LL>;
	vector<tp>b;
	FOR(i, 0, N) {
		// xがあれ．
		LL s, t, x; cin >> s >> t >> x;
		s -= x ;
		t -= x ;
		DD(de(s, t));
		s += geta;
		t += geta;
		b.push_back(tp(x, s, t));
	}
	RSORT(b);
	FOR(i, 0, N) {
		LL x, s, t;
		tie(x, s, t) = b[i];
		seg.update(s, t, x);
	}

	FOR(i, 0, Q) {
		LL d; cin >> d;
		d += geta;
		LL res = seg.query(d, d + 1);
		//DD(de(res));
		if (res == LINF)cout << -1 << endl;
		else cout << res << endl;

	}

	return 0;
}
