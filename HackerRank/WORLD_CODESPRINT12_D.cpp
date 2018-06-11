#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const LL MOD = 1000000000;

/* -----  2017/12/15  Problem: world_codesprint12 D / Link: https://www.hackerrank.com/contests/world-codesprint-12/challenges/factorial-array  ----- */
/* ------問題------

数列aがある。以下のクエリをさばけ。
1: A[l,r] ++
2: A[l,r] sum of A[i]! mod 10^9
3: A[i] = v

-----問題ここまで----- */
/* -----解説等-----

40!の値が10^9で割り切れるので、A[i]>=40ならば実質0となる。
後はセグ木でできそう。
1:遅延値だけ値が大きくなる。これは一回保存して、resetしてもとの値を遅延値だけずらせば良い。
2:queryするだけ
3:resetして根まで持ち上げれば良い(ということがsubmitするとわかる)

----解説ここまで---- */

LL N;
LL factmemo[100] = { 0,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,227020800,178291200,674368000,789888000,428096000,705728000,408832000,176640000,709440000,607680000,976640000,439360000,984000000,584000000,768000000,504000000,616000000,480000000,880000000,160000000,280000000,520000000,200000000,200000000,400000000,200000000,800000000,0,0,0,0 };
LL ans = 0LL;
inline LL calcfact(LL val) {//hash的な速いものがいる、ただし40以上は0である
	if (val <= 40)return factmemo[val];
	else return 0;
}


struct Node {
	Node(){fill(val, val + 41, 0); } // e
	Node(long long x){
		fill(val, val + 41, 0);
		if(x>=0&&x<=40)val[x] = 1;
	}
	LL val[41];
};
struct Lazy {
	Lazy() :set(0), lazyval(0) {} // lazy e

	bool set;
	long long lazyval;
};
//long long out_range = 1e18; // queryの範囲外の値 , mergeを考慮


typedef long long ll;
struct LazySegTreeP {

	long long N;
	vector<Node> dat;
	vector<Lazy> lazy;

	inline Node merge(Node& a, Node& b) { // node⊕node
		Node node;
		FOR(i, 0, 41) {
			node.val[i] = a.val[i] + b.val[i];
		}
		return node;
	} //台数構造

	  // 命令を下のノードにpush
	void lazy_push(ll k, ll queryL, ll queryR) { // node⊕lazy
		if (lazy[k].set == 0)return; // 命令なし

		// lazyvalだけ移動させる
		Node temp = dat[k];
		int pval = lazy[k].lazyval;
		FOR(i, 0, 40) {
			dat[k].val[i] = 0;
		}
		FOR(i, 0, 40) {
			if(i+pval <=40)dat[k].val[i + pval] = temp.val[i];
		}
		// dat[k].val += lazy[k].lazyval; //値の塗りつぶし += とかかも
		if (k < N - 1) {
			lazy_set(2 * k + 1, lazy[k].lazyval);
			lazy_set(2 * k + 2, lazy[k].lazyval); //下にlazy[k].lazyvalをそのまま伝搬
		}
		lazy[k].lazyval = 0;
		lazy[k].set = 0; // 子に命令を伝搬させたので、命令を空にする
	}

	// ノードがクエリと一致したとき遅延命令をセット
	inline void lazy_set(ll k, ll val) { // lazy⊕lazy
		lazy[k].set = 1;
		lazy[k].lazyval += val; // += ?
	}


	//--------------setting--------------//

	inline void fix(ll k) { // ノードkに対応する　値に修正 merge的な
		dat[k] = merge(dat[k * 2 + 1], dat[k * 2 + 2]);
	}

	LazySegTreeP(int _N) {
		N = 1;
		while (N < _N)N *= 2;
		dat = vector<Node>(N * 2 - 1);	// max値を入れておく、書き換えupdateはいいが加算addに注意
		lazy = vector<Lazy>(N * 2 - 1);	// 遅延評価管理フラグ、遅延評価値にならない値をNILにする
	}

	LazySegTreeP(vector<long long >& a, int _N) { //なにかしらで初期化できるならする。(クエリが後でも処理できるときなど)
		N = 1;
		while (N < _N)N *= 2;
		dat = vector<Node>(N * 2 - 1);
		lazy = vector<Lazy>(N * 2 - 1);	// 遅延評価管理フラグ、遅延評価値にならない値をNILにする
		for (int i = 0; i < _N; ++i)dat[i + N - 1] = (Node{ a[i] });
		build();
	}
	void build() { for (int i = N - 2; i >= 0; i--) dat[i] = merge(dat[2 * i + 1], dat[2 * i + 2]); }//mergeして木の作成

	~LazySegTreeP() { vector<Node>().swap(dat); vector<Lazy>().swap(lazy); }


	// 区間[queryL,queryR)をvalで塗りつぶす
	inline void lazy_update(ll queryL, ll queryR, ll val, ll k = 0, ll nodeL = 0, ll nodeR = -1) {
		if (nodeR == -1)nodeR = N;
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

	// 区間[queryL,queryR)をvalで塗りつぶす
	inline void lazy_change(ll queryL, ll queryR, ll val, ll k = 0, ll nodeL = 0, ll nodeR = -1) {
		if (nodeR == -1)nodeR = N;
		lazy_push(k, nodeL, nodeR);// とりあえず遅延評価分を下のノードに伝播


		if (nodeR <= queryL || queryR <= nodeL) { return; }// クエリ区間とノード区間が交差していないなら、これ以上、処理する意味はない
		if (queryL <= nodeL && nodeR <= queryR) {// ノード区間がクエリ区間に完全に覆われたら、遅延命令をセットして、さっさと帰る
			//lazy_set(k, val); // 命令をセット
			dat[k] = Node(val);
			lazy_push(k, nodeL, nodeR); // 命令をpush
			return;
		}

		// 中途半端に区間が被るときは下のノードにお任せ ノードが下がるときには命令をpushする

		ll nodeM = (nodeL + nodeR) / 2;
		lazy_change(queryL, queryR, val, k * 2 + 1, nodeL, nodeM);
		lazy_change(queryL, queryR, val, k * 2 + 2, nodeM, nodeR);

		fix(k);	// 下のノードの処理が終了して ノードが上がるときにはその前に情報をfixする
		return;
	}


	// 区間[queryL, queryR)のクエリ
	Node query(ll queryL, ll queryR, ll k, ll nodeL, ll nodeR) {

		lazy_push(k, nodeL, nodeR);// とりあえずpushして伝播

		if (nodeR <= queryL || queryR <= nodeL) { return Node(); }	// クエリ区間とノード区間が交差していない => 影響しない値を返す
		if (queryL <= nodeL && nodeR <= queryR) { return dat[k]; } // ノード区間がクエリ区間に完全に覆われた

		ll nodeM = (nodeL + nodeR) / 2;
		Node vl = query(queryL, queryR, k * 2 + 1, nodeL, nodeM);
		Node vr = query(queryL, queryR, k * 2 + 2, nodeM, nodeR);
		//fix(k); // いらん(はず)
		return merge(vr, vl);
	}
	inline LL query(int a, int b) {
		Node x = query(a, b, 0, 0, N);
		LL ret = 0;
		FOR(i, 0, 40 + 1) {
			ret += (factmemo[i] * (x.val[i]%MOD))%MOD;
			ret %= MOD;
		}
		return ret;
	}
};


// 1: [l,r] ++
// 2: [l,r] sum factorial mod 10^9
// 3: [i] = v

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, Q; cin >> N >> Q;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	LazySegTreeP seg(a,N);
	int com, l, r;
	FOR(i, 0, Q) {
		cin >> com >> l >> r;
		if (com == 1) {
			l--, r--;
			seg.lazy_update(l, r + 1, 1);
		}
		else if (com == 2) {
			l--, r--;
			cout << seg.query(l, r + 1) << endl;
		}
		else {
			l--;
			seg.lazy_change(l, l + 1, r);
		}

	}
	return 0;
}
