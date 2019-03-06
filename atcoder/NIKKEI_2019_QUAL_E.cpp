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

/* -----  2019/01/27  Problem: nikkei_2019_qual E / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

逆からつなげていくと良さそう．このとき，何個の辺を残せるか?と言い換える事ができる．

あるyをcheckにかけるとき，その連結成分のwの総和が超えていれば残せる．
ダメなときは，一旦その連結成分でedge++としておく．
追加していって，あるy'でOKだったとき，その連結成分のedgeも答えに足す．
この辻褄を合わせるのいろいろなとこで使えそう(というかそういった思考に慣れるべきで)

逆から見れていたのに通せないねん...悔しい．


----解説ここまで---- */

template<typename M>
struct UnionFind {
	using t = typename M::t;
	vector<int> data;
	vector<t>Mdata;
	UnionFind(int n) { data.assign(n, -1); Mdata.assign(n, M::id()); }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			Mdata[x] = M::op(Mdata[x], Mdata[y]);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	t query(int x) { return Mdata[root(x)]; }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
	void add(int x, const t val) { x = root(x); Mdata[x] = M::op(Mdata[x], val); }
	void update(int x, const t val) { x = root(x); Mdata[x] = M::upd(Mdata[x], val); }
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;
	VL W(N);
	FOR(i, 0, N) {
		cin >> W[i];
	}
	using tp = tuple<LL, int, int>;
	vector<tp>edges(M);
	FOR(i, 0, M) {
		int a, b, y;
		cin >> a >> b >> y;
		a--, b--;
		edges[i] = tp(a, b, y);
	}


	struct D {
		using t = struct A { LL wsum; int edgesum; A(LL w, int e) :wsum(w), edgesum(e) {} };
		static t id() { return A(0, 0); }
		static t op(const t& a, const t& b) {
			return A(a.wsum + b.wsum, a.edgesum + b.edgesum);
		}
		static t upd(const t& a, const t& b) {
			return A(a.wsum + b.wsum, b.edgesum);
		}
	};
	UnionFind<D>uf(N);
	FOR(i, 0, N) {
		uf.update(i, D::A(W[i], 0));
	}
	sort(ALL(edges), [](const tp &a, const tp &b) {
		return get<2>(a) < get<2>(b);
	});

	LL cnt = 0;
	FOR(i, 0, M) {
		int a, b; LL y;
		tie(a, b, y) = edges[i];
		uf.unionSet(a, b);
		uf.add(a, D::A(0, 1));
		D::A uniona = uf.query(a);
		if (uniona.wsum >= y) {
			cnt += uniona.edgesum;
			uf.update(a, D::A(0, 0));
		}
	}


	LL ans = M - cnt;
	cout << ans << "\n";

	return 0;
}
