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

/* -----  2018/11/04  Problem: ARC 045 D / Link: http://arc045.contest.atcoder.jp/tasks/arc045_d  ----- */
/* ------問題------

二次元座標平面上に、座標の異なる 2N+1 個の点が与えられます。
高橋君はこの点の中からたくさんの仲良しペアを作ります。
以下の条件を満たす点同士は仲良しペアになれます。
2 つの点の x 座標と y 座標のどちらかが等しい。
ただしどの点も 2 つ以上の点と仲良しペアになることはできません。
高橋君は、全ての点を仲良しペアにしたかったのですが、点の数が奇数なので不可能なことに気がつきました。
なのでどれか 1 個だけ点を削除し、そのあと N 組の仲良しペアを作れば全ての点を仲良しペアにできると考えました。
すべての点について、その点を削除すると残りの 2N 個の点から N 組の仲良しペアが作れるかどうかを判定してください。

-----問題ここまで----- */
/* -----解説等-----

lowlinkの段階で部分木のサイズを求める方法がよくわからないので、
DynamicConnectivityでやる。
iを削除した状態で残りの成分について奇数のグループサイズを求めれば良い。
これは、(x,y)について、x <-> yをマージして行く際に、+1すれば求めることができる。
すでにグループ化されている頂点郡とのマージは、差分をとってから同様に処理すればできる。

----解説ここまで---- */

struct UnionFindRollBack {
	VI par, msz;
	vector<pair<int*, int>> saved;
	int oddcounter;
	UnionFindRollBack(int n) {
		par.resize(n, -1);
		msz.resize(n, 0);
		oddcounter = 0;
	}
	int snapShotSize() {
		return saved.size();
	}
	void rollBack(int c) {
		while (c < SZ(saved)) {
			*saved.back().first = saved.back().second;
			saved.pop_back();
		}
	}
	void save(int&a) {
		saved.push_back(make_pair(&a, a));
	}
	int root(int a) {
		return par[a] == -1 ? a : root(par[a]);
	}
	void unionSet(int a, int b) {
		a = root(a);
		b = root(b);
		if (msz[a] < msz[b])swap(a, b);
		save(msz[a]);
		save(oddcounter);
		oddcounter -= (msz[a] & 1);
		if (a != b) {
			save(par[b]);
			par[b] = a;
			oddcounter -= (msz[b] & 1);
			msz[a] += msz[b];
		}
		msz[a]++;
		oddcounter += (msz[a] & 1);
	}
};

struct DCSST {
	using edge = PII;

	int n, q;
	UnionFindRollBack uf;
	vector<vector<edge> > edges;

	DCSST(int n, int q_) :n(n), q(1), uf(n) {
		while (q < q_) q <<= 1;
		edges.resize(q * 2 - 1);
	}
	void add(int a, int b, const edge &e, int k, int l, int r) {
		if (r <= a || b <= l) return;
		if (a <= l && r <= b) {
			edges[k].emplace_back(e);
			return;
		}
		int m = (l + r) >> 1;
		add(a, b, e, k * 2 + 1, l, m);
		add(a, b, e, k * 2 + 2, m, r);
	}
	void add(int l, int r, int v, int u) {
		add(l, r, PII(v, u), 0, 0, q);
	}
	void exec(const function<void(int, UnionFindRollBack&)> &f, int k = 0) {
		int c = uf.snapShotSize();
		for (auto &e : edges[k])uf.unionSet(e.first, e.second);

		if (k < q - 1) {
			exec(f, k * 2 + 1);
			exec(f, k * 2 + 2);
		}
		else {
			int x = k - (q - 1);
			f(x, uf);
		}
		uf.rollBack(c);
	}
};
LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	N = 2 * N + 1;
	DCSST seg(2 * N, N);
	FOR(i, 0, N) {
		int x, y; cin >> x >> y;
		x--, y--; y += N;
		seg.add(0, i, x, y);
		seg.add(i + 1, N, x, y);
	}
	VI ans(N, 0);
	auto f = [&](int t, UnionFindRollBack& uf) {
		if (t < N) ans[t] = uf.oddcounter == 0;
	};
	seg.exec(f);
	FOR(i, 0, N) {
		cout << (ans[i] ? "OK" : "NG") << "\n";
	}

	return 0;
}
