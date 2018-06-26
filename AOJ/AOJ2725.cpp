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

/* -----  2018/06/27  Problem: AOJ 2725 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2725  ----- */
/* ------問題------

t[i]秒、p[i]得点、f[i]の影響度を持った曲がある。適当にT秒間演奏して(1回が限度)
得点を最大化せよ。ただしi>=2回目以降は p[i] - (f[i]-f[j])^2 : j:過去のj
とする。

-----問題ここまで----- */
/* -----解説等-----

起きたらわかった
まずfの関係から、バラバラであるよりかは昇順か降順で並んでいたほうが嬉しく、ここから部分列を選択すれば良い。
次に式を見る。これはもうCHT待ったなし。
あとはdpをすればよい。
dpの式からCHTがT個いることが分かる。(パラメータTを個別に含むので)
dp[i][j+t[j]] = max(dp[i][j+t[i]], FOR(k,0,i)max(dp[k][j]+ p[i]-f[i]^2 -2*f[k]*f[i] - f[k]^2));
なので、dpと一緒にやれば良い。

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

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, T;
	cin >> N >> T;
	using tp = tuple<int, int, int>;
	vector<tp>a(N);
	FOR(i, 0, N) {
		int t, p, f;
		cin >> t >> p >> f;
		a[i] = tp(f, p, t);
	}
	SORT(a);
	VL f(N), p(N), t(N);
	FOR(i, 0, N) {
		tie(f[i], p[i], t[i]) = a[i];
	}
	vector<LiChao_min> CHT(T + 1);
	FOR(i, 0, T + 1)CHT[i].init(1e4 + 100);

	VVL dp(N, VL(T+1, -LINF));
	FOR(i, 0, N) {
		dp[i][t[i]] = p[i];
		FOR(j, 0, T - t[i] + 1) {
			if (CHT[j].root == NULL)continue;
			dp[i][j + t[i]] = max(dp[i][j + t[i]], p[i] - f[i]*f[i] - CHT[j].query(f[i]));
		}
		FOR(j, 0, T + 1) {
			if (dp[i][j] == -LINF)continue;
			CHT[j].add_line(-2*f[i] , -(dp[i][j] - f[i]*f[i]));
		}
	}

	LL ans = 0;
	FOR(i, 0, N) {
		FOR(j, 0, T + 1) {
			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans << endl;

	return 0;
}
