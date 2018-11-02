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

/* -----  2018/11/03  Problem: ARC 029 C / Link: http://arc029.contest.atcoder.jp/tasks/arc029_c  ----- */
/* ------問題------

高橋君はゲーム内で国家を運営している。
国家には N 個の都市と、M 本の道がある。それぞれの道は 2 つの異なる都市を直接結んでおり、道の途中に他の都市がない。また、どの 2 つの都市についても、それらの都市を直接結ぶ道は高々 1 つである。
最初、どの道も舗装されておらず、どの都市にも交易所が設置されていない。
高橋君は国家の発展のため、道路の舗装および交易所の設置を行うことにした。
どの都市についても以下のいずかの条件が満たされていれば、国家は「良い状態」であると呼ぶことにする。
その都市には交易所が設置されている。
その都市には交易所が設置されていないものの、その都市から舗装された道のみを経由して、交易所が設置されている別の都市に移動できる。
都市には 1 から N まで、道には 1 から M までの番号がつけられている。都市 i に交易所を設置するのには金貨が ci 枚必要である。また、道 i を舗装するのには金貨が ri 枚必要である。
あまり金貨を多く持ち合わせていないので、国家を「良い状態」にするのに必要な金貨の枚数をできるだけ少なくしたい。
必要な金貨の枚数として考えられる最小値を求めるプログラムを作成せよ。

-----問題ここまで----- */
/* -----解説等-----

クラスカル法っぽくやる。
また、頂点集合ごとに交易所を作成する際の最小値を持つ。
道路を作成する際に、A,Bをくっつけるか検討するとする。
A,Bの両方が、交易所を作成するコストのほうが道路の作成コストよりも小さいならば道路をつくる意味はない。
また、A,Bの少なくともどちらかのコストよりも道路を作成した方が安く済むなら、道路を作ったほうがよい。
(A+C or B+C ≦ A+B (AorB>C)だから)
ついでにufも一般化した演算を載せられるようにした。

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
	int query(int x) { return Mdata[root(x)]; }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;
	
	struct info {
		using t = int;
		static t op(const t& a, const t& b) { return min(a, b); }
		static t id() { return 0; }
	};
	UnionFind<info> uf(N);

	FOR(i, 0, N) {
		LL c; cin >> c;
		uf.Mdata[i] = c;
	}
	using tp = tuple<LL, int, int>;
	vector<tp>events;
	FOR(i, 0, M) {
		int a, b; LL c; cin >> a >> b >> c;
		a--, b--;
		events.push_back(tp(c, a, b));
	}
	SORT(events);
	LL ans = 0;
	for (auto ev : events) {
		int a, b; LL c;
		tie(c, a, b) = ev;
		if (uf.same(a, b))continue;
		a = uf.root(a), b = uf.root(b);
		if (uf.query(a) > c || uf.query(b) > c) {
			uf.unionSet(a, b);
			ans += c;
		}
	}

	FOR(i, 0, N) {
		if (uf.root(i) == i) {
			ans += uf.query(i);
		}
	}
	cout << ans << "\n";

	return 0;
}