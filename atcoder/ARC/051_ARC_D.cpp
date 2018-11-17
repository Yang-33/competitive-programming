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

/* -----  2018/11/17  Problem: ARC 051 D / Link: http://arc051.contest.atcoder.jp/tasks/arc051_d  ----- */
/* ------問題------

長さ W の数列 a1,a2,…,aW と、長さ H の数列 b1,b2,…,bH が与えられます。
左から i 番目、上から j 番目のマス目には ai+bj が書き込まれた、W×H のマス目を考えます。
Q 個の以下のようなクエリが与えられるので、処理してください。
A,B が与えられるので、左から A 番目以内、上から B 番目以内のマス目たちの中から、選んだ部分が長方形になるように幾つかマス目を選んだ時の、選んだマス目の値の総和の最大値を出力。
なお、マス目を 1 つも選ばないことはできません。

-----問題ここまで----- */
/* -----解説等-----

解法までの式変形に時間がかかりすぎた

まず問題はlenb*sumA+lena*sumBを最大化する事がわかる。
適当に累積和maxをするとO(QWH)になる。
lenbを全探索すると、
lenb(sumA+lena/lenb*sumB)みたいになる。
sumA+lena/lenb*sumBの候補はHW個あるが、更に式をみる。
lenbの変更によってsumB,lenbに影響が出る。
ということは、sumA+lena*X , X = sumB/lenbという風に見ることができ、
一次式の集合になるためこれはCHTでmaxを求める事ができる。
結局O(Q(W+HlogMAX))ぐらいで求めることができる。

roundは(LL)にキャストしないと死ぬことがわかった。

----解説ここまで---- */



struct LiChao_min {
	using T = long double;
	struct line {
		T m, c;
		line(T _m = 0, T _c = 0) { m = _m; c = _c; }
		T eval(T x) { return m * x + c; }
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
		T trl = nd->f.eval(l), trr = nd->f.eval(r);
		T vl = v.eval(l), vr = v.eval(r);
		if (trl <= vl && trr <= vr) return;
		if (trl > vl && trr > vr) { nd->f = v; return; }
		if (trl > vl) swap(nd->f, v);
		if (nd->f.eval(mid) < v.eval(mid)) insert(v, mid + 1, r, nd->r);
		else swap(nd->f, v), insert(v, l, mid, nd->l);
	}
	T query(T x, int l, int r, pnode &nd) {
		if (!nd) return LLONG_MAX;
		if (l == r) return nd->f.eval(x);
		if (mid >= x) return min(nd->f.eval(x), query(x, l, mid, nd->l));
		return min(nd->f.eval(x), query(x, mid + 1, r, nd->r));
	}
#undef mid
	void init(int _sz) { sz = _sz + 1; root = NULL; }
	void add_line(T m, T c) { line v(m, c); insert(v, -sz, sz, root); }
	T query(T x) { return query(x, -sz, sz, root); }
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int W, H; cin >> W >> H;
	VL a(W), b(H);
	FOR(i, 0, W) {
		cin >> a[i];
	}
	FOR(i, 0, H) {
		cin >> b[i];
	}
	//key boxを作成
	auto f = [](const VL& a) {
		int N = SZ(a);
		VL sum(N + 1, 0);
		FOR(i, 0, N) {
			sum[i + 1] = sum[i] + a[i];
		}
		VVL res(N + 1, VL(N, -LINF));
		// res(i,j)幅iのとき、[0,j]のどれかを右端にしたときの最大値
		FOR(len, 1, N + 1) {
			FOR(i, 0, N) {
				int j = i + len - 1;// [i,j]
				if (j < N)
					res[len][j] = max(res[len][j], sum[j + 1] - sum[i]);
				if (j&&j < N)
					res[len][j] = max(res[len][j], res[len][j - 1]);
			}
		}
		return res;
	};

	VVL A = f(a);// W
	VVL B = f(b);// H

	int Q; cin >> Q;
	FOR(i, 0, Q) {
		int a, b; cin >> a >> b;
		a--, b--;
		LiChao_min cht; cht.init(1e5+5);
		auto add_line = [&cht](long double a, long double b) {
			cht.add_line(-a, -b);
		};
		auto max_query = [&cht](long double x) {
			return -cht.query(x);
		};
		// クエリ毎{a,b}をinsert
		FOR(w, 1, W + 1) {
			if (w <= a + 1) {
				add_line(w, A[w][a]);
			}
		}
		// 各hについて全部調べれば良い
		long double ans = -LINF;
		FOR(h, 1, H + 1) {
			if (h <= b + 1) {
				long double val = 1.0*B[h][b] / (1.0*h);
				ans = max(ans, (((long double)h)*max_query(val)));
			}
		}
		cout << (LL)round(ans) << endl;
	}


	return 0;
}