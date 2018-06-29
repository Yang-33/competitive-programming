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
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/06/30  Problem: AOJ 2580 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2580  ----- */
/* ------問題------

二次元平面上にN個の都市がある。都市1からNは左から右へ一直線上に並んでおり、都市iは位置(pi,0)にある。pi<pi+1 (1≤i<N)を満たす。
また、この二次元平面上にはM人の敵がおり、敵jは当初、位置(aj,bj)にいる。敵jは左方向について、上下45°の範囲を見張っている。すなわち、直線 y=x−aj+bj 以上で、かつ、直線y=−x+aj+bj 以下の領域に含まれる全ての都市が視界に入っている。また、すべての敵は1日ごとにちょうどXだけ右方向に移動する。すなわち、d日目の敵jの位置は(aj+X(d−1),bj)である。
ここで、d日目における都市iの監視度wd,iは、d日目において都市iを視界に入れている敵の総数により定義される。このとき、d日目の都市iから都市kへの移動は、wd,i×|pi−pk|のリスクを負う。1日に1度しか移動できないとするとき、D日後までに都市1から都市Nまで移動する際のリスクの総和を最小化せ

-----問題ここまで----- */
/* -----解説等-----

DP + CHT(live performanceと一緒の形)で、
O(DN^2) -> O(DNlogN+DM+N)で解ける。
まず位置はD回情報を作るとする。この位置からW_di的なものを作るが、これはsortすれば二分探索とかimos方で監視している緑のアレの数がわかる。
あとは愚直DPを式変形して、dpのseedもCHTの定数項に打ち込めば良い。(ここがlive performanceと一緒)
よって解けた。
単調CHTと速度比較をしたが同じ速度だった。

----解説ここまで---- */

struct LiChao_min {
	struct line {
		LL m, c;
		line(LL _m = 0, LL _c = 0) { m = _m; c = _c; }
		LL eval(LL x) { return m * x + c; }
	};
	struct node {
		node *l, *r; line f;
		node(line v) { f = v; l = r = NULL; }
	};
	typedef node* pnode;
	pnode root; int sz;
#define mid ((l+r)>>1)
	void insert(line &v, int l, int r, pnode &nd) {
		if (!nd) { nd = new node(v); return; }
		LL trl = nd->f.eval(l), trr = nd->f.eval(r);
		LL vl = v.eval(l), vr = v.eval(r);
		if (trl <= vl && trr <= vr) return;
		if (trl > vl && trr > vr) { nd->f = v; return; }
		if (trl > vl) swap(nd->f, v);
		if (nd->f.eval(mid) < v.eval(mid)) insert(v, mid + 1, r, nd->r);
		else swap(nd->f, v), insert(v, l, mid, nd->l);
	}
	LL query(int x, int l, int r, pnode &nd) {
		if (!nd) return LLONG_MAX;
		if (l == r) return nd->f.eval(x);
		if (mid >= x) return min(nd->f.eval(x), query(x, l, mid, nd->l));
		return min(nd->f.eval(x), query(x, mid + 1, r, nd->r));
	}
	/* -sz <= query_x <= sz */
#undef mid
	void init(int _sz) { sz = _sz + 1; root = NULL; }
	void add_line(LL m, LL c) { line v(m, c); insert(v, -sz, sz, root); }
	LL query(LL x) { return query(x, -sz, sz, root); }
};


int abs(int x) {
	return x < 0 ? -x : x;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M, D, X;
	cin >> N >> M >> D >> X;
	VL p(N);
	FOR(i, 0, N) {
		cin >> p[i];
	}
	VL xs(M);
	FOR(i, 0, M) {
		int x, y; cin >> x >> y;
		x -= abs(y);
		xs[i] = x;
	}
	VVL imosD(D);
	FOR(d, 0, D) {
		vector<PLL>za;
		FOR(i, 0, N) {
			za.push_back(PLL(p[i], 0));
		}
		FOR(i, 0, M) {
			za.push_back(PLL(xs[i] + X*d, 1));
		}
		SORT(za);
		VL imos(N + 1, 0);
		int Stacksize = 0;
		int cityidx = 0;
		FOR(i, 0, SZ(za)) {
			if (za[i].second == 0) {
				imos[cityidx++] -= Stacksize;
				Stacksize = 0;
			}
			else {
				if (cityidx) {
					imos[0]++;
					Stacksize++;
				}
			}
		}
		FOR(i, 0, N) {
			imos[i + 1] += imos[i];
		}
		imosD[d] = imos;
	}

	VVL dp(D + 1, VL(N, LINF));
	dp[0][0] = 0;
	FOR(d, 0, D) {
		LiChao_min CHT; CHT.init(1e6 + 1e2);
		FOR(i, 0, N) {
			if (CHT.root != NULL)
				dp[d + 1][i] = min(dp[d+1][i] , CHT.query(p[i]));
			dp[d + 1][i] = min(dp[d + 1][i], dp[d][i]);
			CHT.add_line(imosD[d][i], -imosD[d][i] * p[i] + dp[d][i]);
		}
	}
	cout << dp[D][N - 1] << endl;


	return 0;
}
