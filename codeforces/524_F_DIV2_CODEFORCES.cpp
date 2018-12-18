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

/* -----  2018/11/24  Problem: CodeForces524 F div2 / Link: http://codeforces.com/contest/1080/problem/F  ----- */
/* ------問題------

みて

-----問題ここまで----- */
/* -----解説等-----

これ解けなかったの痛すぎる。やっぱり2Dに置き換えるのが常套手段すぎる。すぐ書くことが必要そう。
色の区間が連続しているのでこれをsegtreeにのせる。
また、Onlineクエリなので永続セグ木になる。
クエリの内容は[a..b]のそれぞれの色について[x..y]に収まる線分が存在するを確かめれば良いので、
あるxをキーにしてそれ以降に含まれる線分の右側の値が、y以下であるかを見れば良い。
連続する色については、すべてy以下である必要があるので、最大値がy以下と言い換えることができる。
あとは永続セグ木に右から線分を追加していけば良い。

----解説ここまで---- */

const int PMAX = 1e7;

template <typename M>
class persistent_segment_tree {
	using T = typename M::type;
	struct node {
		T val;
		node *l, *r;
		node() {}
		node(T val) : val(val), l(nullptr), r(nullptr) {}
		void init(T v, node *left, node *right) {
			val = v;
			l = left;
			r = right;
		}
	};
	const long long n;
	vector<node> pool;
	int it;
	vector<node*> root;
	long long size(long long n) {
		long long res = 1;
		while (res < n) res <<= 1;
		return res;
	}
	T get(node *p) {
		return p == nullptr ? M::id() : p->val;
	}
	node *new_node(T val = M::id(), node *l = nullptr, node *r = nullptr) {
		pool[it].init(val, l, r);
		return &pool[it++];
	}
	node *fix(node *x, int p, T val, int lb, int ub) {
		if (p < lb || ub <= p) return x;
		if (lb + 1 == ub) return new_node(val);
		if (x == nullptr) x = new_node(M::id());
		else x = new_node(x->val, x->l, x->r);
		int c = (lb + ub) / 2;
		x->l = fix(x->l, p, val, lb, c);
		x->r = fix(x->r, p, val, c, ub);
		x->val = M::op(get(x->l), get(x->r));
		return x;
	}
	T sub(node *x, int l, int r, int lb, int ub) {
		if (x == nullptr || ub <= l || r <= lb) return M::id();
		if (l <= lb && ub <= r) return x->val;
		int c = (lb + ub) / 2;
		return M::op(sub(x->l, l, r, lb, c), sub(x->r, l, r, c, ub));
	}
public:
	persistent_segment_tree(long long n_) : n(size(n_)), pool(PMAX), it(0) {
		root.push_back(nullptr);
	}
	void update(int p, T val, int rt = -1) {
		if (rt == -1) rt = root.size() - 1;
		assert(0 <= rt && rt < (int)root.size());
		root.push_back(fix(root[rt], p, val, 0, n));
	}
	T query(int l, int r, int rt = -1) {
		if (rt == -1) rt = root.size() - 1;
		assert(0 <= rt && rt < (int)root.size());
		return sub(root[rt], l, r, 0, n);
	}
	int getversion() {
		return root.size() - 1;
	}
};

struct Monoid {
	using type = int;
	static type id() { return 0; } //type()
	static type op(const type& l, const type & r) {
		return max(l, r);
	}
};



int read() { int in; scanf("%d", &in); return in; }

int main() {


	int n = read(), Q = read(), K = read();
	using tp = tuple<int, int, int>;
	vector<tp>line(K);
	FOR(i, 0, K) {
		int x = read(), y = read(), p = read() - 1;
		line[i] = tp(x, y, p);
	}
	SORT(line);
	persistent_segment_tree<Monoid> seg(n + 10);
	FOR(i, 0, n) {
		seg.update(i, INT_MAX);
	}
	FORR(k, K - 1, 0 - 1) {
		DD(de(get<2>(line[k]), get<1>(line[k])));
		int val = min(get<1>(line[k]),seg.query(get<2>(line[k]), get<2>(line[k]) + 1));
		seg.update(get<2>(line[k]), val);
	}
	FOR(_, 0, Q) {
		int a = read() - 1, b = read() - 1, x = read(), y = read();
		int id = (lower_bound(ALL(line), tp(x, -1, -1)) - line.begin());
		int f = 0;
		if (id == K) {
			f = 0;
		}
		else {
			int res = seg.query(a, b + 1, K+n - id);
			DD(de(a, b, x, y, res, K +n	- id, id));
			if (res <= y)f = 1;
		}
		cout << (f ? "yes" : "no") << endl;
	}


	return 0;
}
