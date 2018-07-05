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
#define FOR(i, s, e) for(int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/07/05  Problem: AOJ 3008 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/3008  ----- */
/* ------問題------

あなたはツリーライトというツリー状の照明器具を買ってきた。
この照明器具にはn個の接点があり、それぞれ0からn−1までの番号がついている。各接点は10段階の明るさを表現できる電球と、電球の状態を切り替えるための装置で構成されている。最初、すべての接点の電球の明るさは0である。
また、接点と接点の間にはケーブル線がある。すべての接点はn−1本のケーブル線によって繋がれており、接点0を上にして吊り下げられる。ここで、接点iから下方向に0本以上のケーブル線を介して、接点iと繋がる接点の集合を、接点iを根とした部分木と呼ぶ。
あなたはこの照明器具に対し、以下のいずれかの行動をとる。
count(r,x,y): 接点rを根とした部分木に含まれる接点の電球の中で、明るさがx以上y以下になっている電球の数を数える。
change(r,x,y): 接点rを根とした部分木に含まれる接点の電球の中で、明るさがちょうどxになっているすべての電球の明るさをyに変更する。
q回の行動が与えられるので、count(r,x,y)が与えられるたびにその時点での電球の数を出力せよ。

-----問題ここまで----- */
/* -----解説等-----

なんでバグるんや…
まず部分木操作しか無いので、HLDじゃなくてeulertourでよい。
次に列のときの更新を考える。
これは写像を扱っていると気づくことができるので、写像を保持した状態で個数を移動できるようにすれば良い。
遅延型を保持できるようにいい感じにすればよい。

----解説ここまで---- */


struct Node {
	Node(long long x = 10) { FOR(i, 0, 11)val[i] = 0; val[x] = 1; }
	long long val[11];
};
struct Lazy {
	Lazy() :set(0) { FOR(i, 0, 10)lazyval[i] = i; } // lazy e

	bool set;
	long long lazyval[11];
};
long long out_range = 10; // queryの範囲外の値 , mergeを考慮


typedef long long ll;
struct LazySegTreeP {

	long long N;
	vector<Node> dat;
	vector<Lazy> lazy;

	inline Node merge(Node& a, Node& b) { // node⊕node
		Node node(10);
		FOR(i, 0, 10) {
			node.val[i] = a.val[i] + b.val[i];
		}
		return node;
	} //台数構造

	  // 命令を下のノードにpush
	void lazy_push(ll k, ll queryL, ll queryR) { // node⊕lazy
		if (lazy[k].set == 0)return; // 命令なし
		// L to N
		Node ret(10);
		FOR(i, 0, 10) {
			ret.val[lazy[k].lazyval[i]] += dat[k].val[i];
		}
		FOR(i, 0, 10) {
			dat[k].val[i] = ret.val[i];
		}

		if (k < N - 1) {
			lazy_set(2 * k + 1, lazy[k]);
			lazy_set(2 * k + 2, lazy[k]); //下にlazy[k].lazyvalをそのまま伝搬
		}

		//lazy reset
		FOR(i, 0, 10) {
			lazy[k].lazyval[i] = i;
		}


		lazy[k].set = 0; // 子に命令を伝搬させたので、命令を空にする
	}

	// ノードがクエリと一致したとき遅延命令をセット
	inline void lazy_set(ll k, const Lazy& val) { // lazy⊕lazy
		lazy[k].set = 1;
		Lazy nx;
		FOR(i, 0, 10) {
			nx.lazyval[i] = val.lazyval[lazy[k].lazyval[i]];
		}

		FOR(i, 0, 10) {
			lazy[k].lazyval[i] = nx.lazyval[i];
		}
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

	LazySegTreeP(vector<int>& a, int _N) { //なにかしらで初期化できるならする。(クエリが後でも処理できるときなど)
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
	inline void lazy_update(ll queryL, ll queryR, Lazy& val, ll k = 0, ll nodeL = 0, ll nodeR = -1) {
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

	// 区間[queryL, queryR)のクエリ
	Node query(ll queryL, ll queryR, ll k, ll nodeL, ll nodeR) {

		lazy_push(k, nodeL, nodeR);// とりあえずpushして伝播

		if (nodeR <= queryL || queryR <= nodeL) { return Node(out_range); }	// クエリ区間とノード区間が交差していない => 影響しない値を返す
		if (queryL <= nodeL && nodeR <= queryR) { return dat[k]; } // ノード区間がクエリ区間に完全に覆われた

		ll nodeM = (nodeL + nodeR) / 2;
		Node vl = query(queryL, queryR, k * 2 + 1, nodeL, nodeM);
		Node vr = query(queryL, queryR, k * 2 + 2, nodeM, nodeR);
		//fix(k); // いらん(はず)
		return merge(vr, vl);
	}
	inline Node query(int a, int b) {
		return query(a, b, 0, 0, N);
	}
};

PII et[200000]; // V: seg.query(et[v].first, et[v].second)
void calc(const vector<vector<int>>&G, int root = 0) {
	int k = 0;
	stack<PII> s;
	s.push(PII(root, -1));
	while (!s.empty()) {
		PII q = s.top(); s.pop();
		int x = q.first, p = q.second;
		if (x < 0 || (!x&&p > 0)) {
			et[-x].second = k;
			continue;
		}
		s.push(PII(-x, -p));
		et[x].first = k++;
		for (int i = 0; i < (int)G[x].size(); i++) {
			int y = G[x][i];
			if (y == p) continue;
			s.push(PII(y, x));
		}
	}
}

//

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, Q;
	cin >> N >> Q;
	VVI G(N);
	FOR(i, 0, N - 1) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	calc(G);
	//FOR(i, 0, N) {
	//	cout << et[i].first << "," << et[i].second << endl;
	//}
	//cout << "euler" << endl;
	VI na(N, 0);
	LazySegTreeP seg(na, N); //default :0
	//FOR(i, 0, 100) {
	//	int a; cin >> a;
	//	Node nd = seg.query(et[a].first, et[a].second);
	//	FOR(k, 0, 11) {
	//		cout << k << ":=" << nd.val[k] << " ";
	//	}cout << endl;
	//}


	FOR(q, 0, Q) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a == 1) { // query
			Node nd = seg.query(et[b].first, et[b].second);
			int ans = 0;
			FOR(k, c, d + 1) {
				//cout << k << ":=" << nd.val[k] << " ";
				ans += nd.val[k];
			}//cout << endl;
			cout << ans << endl;
		}
		else { // change
			Lazy fromto;
			fromto.lazyval[c] = d;
			//cout << "insert:";
			//FOR(i, 0, 10)cout << fromto.lazyval[i] << " ";
			//cout << endl;
			seg.lazy_update(et[b].first, et[b].second, fromto);
		}
		//cout << "deb" << endl;
		//FOR(i, 0, N) {
		//	Node nd = seg.query(i, i + 1);
		//	FOR(k, 0, 11)cout << nd.val[k] << " ";
		//	cout << endl;
		//}

	}


	return 0;
}
