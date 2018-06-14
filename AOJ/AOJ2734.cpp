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

/* -----  2018/06/14  Problem: AOJ 2734 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2734  ----- */
/* ------問題------

N個のドーナツが並んでいて、T回操作を行う。1-Kまでの順番を守って操作されたものの個数は。
Q:[l,r]に操作xを行う。

-----問題ここまで----- */
/* -----解説等-----

遅延評価セグメントツリーでできる。
ルールは以下
対応する一点について[1:K]を目指す。
遅延評価される縦の区間に対してmerge則を作れば良い。
mergeできないときはもうその区間は正しいものを作れないので、-2とかにしておく。
構造は同じものを使えば良い。同じものを使ったので単位元とかがぐちゃくちゃになった。

----解説ここまで---- */

using Node = PII;
using Lazy = PII;

typedef long long ll;
struct LazySegTreeP {

	long long N;
	vector<Node> dat;
	vector<Lazy> lazy;

	Node merge(const Node& a, const Node& b) { // node⊕node
		if (a == PII(-1,-1))return b;
		if (b== PII(-1,-1))return a;
		if (a == PII(-2, -2) || b == PII(-2, -2))return PII(-2, -2);
		return (a.second == b.first? PII(a.first,b.second) : PII(-2,-2));
	} //台数構造

	  // 命令を下のノードにpush
	void lazy_push(ll k, ll queryL, ll queryR) { // node⊕lazy
		if (lazy[k]==PII(-1,-1))return; // 命令なし
		dat[k] = merge(dat[k], lazy[k]);
		if (k < N - 1) {
			lazy_set(2 * k + 1, lazy[k]);
			lazy_set(2 * k + 2, lazy[k]); //下にlazy[k].lazyvalをそのまま伝搬
		}
		lazy[k] = PII(-1,-1);
	}

	// ノードがクエリと一致したとき遅延命令をセット
	inline void lazy_set(ll k, const Lazy& val) { // lazy⊕lazy
		lazy[k] = merge(lazy[k], val);
	}

	//--------------setting--------------//
	inline void fix(ll k) { // ノードkに対応する　値に修正 merge的な
		dat[k] = merge(dat[k * 2 + 1], dat[k * 2 + 2]);
	}
	LazySegTreeP(int _N) {
		N = 1;
		while (N < _N)N *= 2;
		dat = vector<Node>(N * 2 - 1,PII(0,0));	// max値を入れておく、書き換えupdateはいいが加算addに注意
		lazy = vector<Lazy>(N * 2 - 1, PII(-1,-1));	// 遅延評価管理フラグ、遅延評価値にならない値をNILにする
	}

	void build() { for (int i = N - 2; i >= 0; i--) dat[i] = merge(dat[2 * i + 1], dat[2 * i + 2]); }
	~LazySegTreeP() { vector<Node>().swap(dat); vector<Lazy>().swap(lazy); }
	void lazy_update(ll queryL, ll queryR, const Lazy& val, ll k, ll nodeL, ll nodeR) {
		lazy_push(k, nodeL, nodeR);// とりあえず遅延評価分を下のノードに伝播


		if (nodeR <= queryL || queryR <= nodeL) { return; }// クエリ区間とノード区間が交差していないなら、これ以上、処理する意味はない
		if (queryL <= nodeL && nodeR <= queryR) {// ノード区間がクエリ区間に完全に覆われたら、遅延命令をセットして、さっさと帰る
			lazy_set(k, val); // 命令をセット
			lazy_push(k, nodeL, nodeR); // 命令をpush
			return;
		}

		// 中途半端に区間が被るときは下のノードにお任せ ノードが下がるときには命令をpushする

		ll nodeM = (nodeL + nodeR) / 2;
		lazy_update(queryL, queryR, val, k * 2 + 1, nodeL, nodeM);
		lazy_update(queryL, queryR, val, k * 2 + 2, nodeM, nodeR);

		fix(k);	// 下のノードの処理が終了して ノードが上がるときにはその前に情報をfixする
		return;
	}
	void lazy_update(ll a, ll b, const Lazy val) {
		lazy_update(a, b, val, 0, 0, N);
	}
	Node query(ll queryL, ll queryR, ll k, ll nodeL, ll nodeR) {

		lazy_push(k, nodeL, nodeR);// とりあえずpushして伝播

		if (nodeR <= queryL || queryR <= nodeL) { return Node(-1,-1); }	// クエリ区間とノード区間が交差していない => 影響しない値を返す
		if (queryL <= nodeL && nodeR <= queryR) { 
			return dat[k]; } // ノード区間がクエリ区間に完全に覆われた

		ll nodeM = (nodeL + nodeR) / 2;
		Node vl = query(queryL, queryR, k * 2 + 1, nodeL, nodeM);
		Node vr = query(queryL, queryR, k * 2 + 2, nodeM, nodeR);
		return merge(vr, vl);
	}
	Node query(int a, int b) {
		return query(a, b, 0, 0, N);
	}
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, K; cin >> N >> K;
	int Case; cin >> Case;

	LazySegTreeP seg(N);
	FOR(i, 0, Case) {
		int l, r, x; cin >> l >> r >> x;
		seg.lazy_update(l - 1, r, PII(x - 1, x));
	}
	int ans = 0;
	FOR(i, 0, N) {
		Node a = seg.query(i, i + 1);
		if (a == PII(0, K))ans++;
	}

	cout << ans << endl;

	return 0;
}
