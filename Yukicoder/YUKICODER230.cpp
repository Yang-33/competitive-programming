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

/* -----  2018/08/24  Problem: yukicoder 230  / Link: http://yukicoder.me/problems/no/230  ----- */
/* ------問題------

Splarraay ｽﾌﾟﾗﾚｪｰｲは配列を塗りつぶすだけの簡単なゲームです。
プレイヤーはチームAとチームBに分かれ、それぞれのチームを表す色で1つの配列を塗りつぶし合います。
最終的なスコアはそのチームの色で塗りつぶされた要素の数と、後述するボーナスポイントの和で決まり、スコアが高いチームがゲームの勝者となります。
ルール

長さNの、何色にも塗られていない配列が与えられる
2つのチームは配列のある区間[l,r]をそのチームの色で塗りつぶしていく。塗りつぶそうとした場所に既に色が塗られていた場合、後から塗られた色で上書きされる
不定期にボーナスチャンスが与えらる。ボーナスチャンスでは区間[l,r]が与えられ、その時点でチームAによって塗られている区間[l,r]の要素の数をAl,r 、チームBによって塗られている区間[l,r]の要素の数を Bl,r としたとき、この値が大きい方のチームに max(Al,r,Bl,r) のボーナスポイントが与えられる。 Al,r と Bl,r が等しい場合、どちらにもボーナスポイントは与えられない
時間制限が訪れゲームが終了したとき、配列の全区間[0,N−1]の、そのチームの色で塗られている要素の数と、それまでに得たボーナスポイントの和がそのチームのスコアとなる
既にゲームは終了し、後はスコアを計算するだけです。各チームの行動の履歴とボーナスチャンスの詳細が時系列順に与えられるので、最終スコアを算出してください。

-----問題ここまで----- */
/* -----解説等-----

やっと230だけど遠すぎる
僕の遅延セグ木遅くない?

----解説ここまで---- */

struct Node {
	Node() :A(0), B(0) {} // e
	Node(long long x) :A(x), B(x) {}
	LL A, B;
};
struct Lazy {
	Lazy() :set(0), lazyval(0) {} // lazy e
	bool set;
	long long lazyval;
};

long long out_range = 0;

typedef long long ll;
struct LazySegTreeP {

	long long N;
	vector<Node> dat;
	vector<Lazy> lazy;

	inline Node merge(Node& a, Node& b) {
		Node node;
		node.A = a.A + b.A;
		node.B = a.B + b.B;
		return node;
	}

	void lazy_push(ll k, ll queryL, ll queryR) {
		if (lazy[k].set == 0)return;
		if (lazy[k].lazyval == 1) {
			dat[k].A = (queryR - queryL);
			dat[k].B = 0;
		}
		else if (lazy[k].lazyval == 2) {
			dat[k].A = 0;
			dat[k].B = (queryR - queryL);
		}
		if (k < N - 1) {
			lazy_set(2 * k + 1, lazy[k].lazyval);
			lazy_set(2 * k + 2, lazy[k].lazyval);
		}
		lazy[k].lazyval = 0;
		lazy[k].set = 0;
	}

	inline void lazy_set(ll k, ll val) {
		lazy[k].set = 1;
		lazy[k].lazyval = val;
	}

	inline void fix(ll k) {
		dat[k] = merge(dat[k * 2 + 1], dat[k * 2 + 2]);
	}

	LazySegTreeP(int _N) {
		N = 1;
		while (N < _N)N *= 2;
		dat = vector<Node>(N * 2 - 1);
		lazy = vector<Lazy>(N * 2 - 1);
	}

	~LazySegTreeP() { vector<Node>().swap(dat); vector<Lazy>().swap(lazy); }

	inline void lazy_update(ll queryL, ll queryR, ll val, ll k = 0, ll nodeL = 0, ll nodeR = -1) {
		if (nodeR == -1)nodeR = N;
		lazy_push(k, nodeL, nodeR);

		if (nodeR <= queryL || queryR <= nodeL) { return; }
		if (queryL <= nodeL && nodeR <= queryR) {
			lazy_set(k, val);
			lazy_push(k, nodeL, nodeR);
			return;
		}
		ll nodeM = (nodeL + nodeR) / 2;
		lazy_update(queryL, queryR, val, k * 2 + 1, nodeL, nodeM);
		lazy_update(queryL, queryR, val, k * 2 + 2, nodeM, nodeR);

		fix(k);
		return;
	}

	Node query(ll queryL, ll queryR, ll k, ll nodeL, ll nodeR) {

		lazy_push(k, nodeL, nodeR);

		if (nodeR <= queryL || queryR <= nodeL) { return Node(out_range); }
		if (queryL <= nodeL && nodeR <= queryR) { return dat[k]; }

		ll nodeM = (nodeL + nodeR) / 2;
		Node vl = query(queryL, queryR, k * 2 + 1, nodeL, nodeM);
		Node vr = query(queryL, queryR, k * 2 + 2, nodeM, nodeR);
		return merge(vr, vl);
	}
	inline Node query(int a, int b) {
		return query(a, b, 0, 0, N);
	}
};


int main() {
	int N, Q; scanf("%d%d", &N, &Q);
	LazySegTreeP seg(N);
	LL A = 0, B = 0;
	int x, l, r;
	FOR(_, 0, Q) {
		scanf("%d%d%d", &x, &l, &r);
		if (x == 0) {
			Node res = seg.query(l, r + 1);
			if (res.A != res.B) {
				(res.A > res.B ? A : B) += max(res.A, res.B);
			}
		}
		else if (x == 1) {
			seg.lazy_update(l, r + 1, 1);
		}
		else if (x == 2) {
			seg.lazy_update(l, r + 1, 2);
		}
	}
	// A,Bの最後の加算
	Node res = seg.query(0, N);
	A += res.A, B += res.B;

	cout << A << " " << B << "\n";

	return 0;
}
