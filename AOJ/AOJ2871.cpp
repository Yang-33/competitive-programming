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

/* -----  2018/07/05  Problem: AOJ 2871 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2871  ----- */
/* ------問題------

n 頂点からなる根つき木 T が与えられる。ここで、 n は奇数であり、 T の根は頂点番号が 1 である。 さらに、それぞれの頂点 v に対して G もしくは W のラベルが与えられ、頂点 v と v の子孫からなる部分木を v の部分木 Tv と呼ぶ。
次の操作が q 回行われる。それぞれの操作終了時に、 T 中の全ての頂点で、G のラベルを持つ頂点が過半数をこえる場合は “broccoli”、そうでない場合は “cauliflower” と出力せよ。
頂点 v が与えられる。部分木 Tv 中の頂点 u がラベル G を持つならば u のラベルを W に、W を持つならば u のラベルを G にする。

-----問題ここまで----- */
/* -----解説等-----

オイラツアーでできるのは明らか。
HLDでverifyを試みた。

----解説ここまで---- */

struct HLD {
	int n, pos;
	vector<vector<int>> G;
	vector<int> vid, head, sub, hvy, par, dep, inv, type, ps, pt;
	HLD(int nn) :
		n(nn), pos(0), G(n),
		vid(n, -1), head(n), sub(n, 1), hvy(n, -1),
		par(n), dep(n), inv(n), type(n), ps(n), pt(n) {}

	void add_edge(int u, int v) {
		G[u].push_back(v);
		G[v].push_back(u);
	}
	void build(int root = 0) { // 根を乱択したい、森である場合には適宜変更
		int c = 0;
		dfs(root);
		bfs(root, c++);
	}

	// Path構築のために必要なアレを集める(subtree & et)
	void dfs(int rt) {
		using T = pair<int, int>;
		stack<T> st;
		par[rt] = -1;
		dep[rt] = 0;
		st.emplace(rt, 0);
		while (!st.empty()) {
			int v = st.top().first;
			int &i = st.top().second;
			if (i < (int)G[v].size()) {
				int u = G[v][i++];
				if (u == par[v]) continue;
				par[u] = v;
				dep[u] = dep[v] + 1;
				st.emplace(u, 0);
			}
			else {
				st.pop();
				for (int j = 0; j < (int)G[v].size(); j++) {
					int &u = G[v][j];
					if (u == par[v]) swap(u, G[v].back());
					if (u == par[v]) continue;
					sub[v] += sub[u];
					if (sub[u] > sub[G[v].front()]) swap(u, G[v].front());
				}
			}
		}
	}

	// Pathの構築 (subtree & et)
	void bfs(int r, int c) {
		using T = tuple<int, int, int>;
		stack<T> st;
		st.emplace(r, r, 0);
		while (!st.empty()) {
			int v, h;
			tie(v, h, ignore) = st.top();
			int &i = get<2>(st.top());
			if (!i) {
				type[v] = c;
				ps[v] = vid[v] = pos++;
				inv[vid[v]] = v;
				head[v] = h;
				hvy[v] = (G[v].empty() ? -1 : G[v][0]);
				if (hvy[v] == par[v]) hvy[v] = -1;
			}
			if (i < (int)G[v].size()) {
				int u = G[v][i++];
				if (u == par[v]) continue;
				st.emplace(u, (hvy[v] == u ? h : u), 0);
			}
			else {
				st.pop();
				pt[v] = pos;
			}
		}
	}

	// [l, r] 
	void for_each_vertex(int u, int v, const function<void(int, int)>& f) {
		while (1) {
			if (vid[u] > vid[v])swap(u, v);
			f(max(vid[head[v]], vid[u]), vid[v]);
			if (head[u] != head[v]) v = par[head[v]];
			else break;
		}
	}

	// 頂点属性の for_each （有向)
	// fの3番目の引数には順方向なら0、逆方向なら1が渡される
	void for_each_directed(int u, int v, const function<void(int, int, int)>& f) {
		if (vid[u] > vid[v]) {
			f(max(vid[head[u]], vid[v]), vid[u], 1);
			if (head[u] != head[v]) for_each_directed(par[head[u]], v, f);
		}
		else {
			f(max(vid[head[v]], vid[u]), vid[v], 0);
			if (head[u] != head[v]) for_each_directed(u, par[head[v]], f);
		}
	}

	// [l, r] 辺は根から見たときの深い方の頂点に対応する
	void for_each_edge(int u, int v, const function<void(int, int)>&f) {
		while (1) {
			if (vid[u] > vid[v])swap(u, v);
			if (head[u] != head[v]) {
				f(vid[head[v]], vid[v]);
				v = par[head[v]];
			}
			else {
				if (u != v)f(vid[u] + 1, vid[v]);
				break;
			}
		}
	}
	// directed edge 未実装



	// k-th upper ancestor：未確認
	int kth_up(int u, int k) {
		while (1) {
			if (dep[head[u]] > dep[u] - k) {
				k -= dep[u] - dep[head[u]] + 1;
				if (head[u] == 0) return 0;
				u = par[head[u]];
			}
			else {
				return inv[vid[u] - k];
			}
		}
	}

	// LCA
	int lca(int u, int v) {
		while (1) {
			if (vid[u] > vid[v])swap(u, v);
			if (head[u] == head[v])return u;
			v = par[head[v]];
		}
	}

	// u,v間の距離
	int distance(int u, int v) {
		return dep[u] + dep[v] - 2 * dep[lca(u, v)];
	}
};

struct Node {
	Node() :val(0) {} // e
	Node(long long x) :val(x) {}
	long long val;
};
struct Lazy {
	Lazy() :set(0), lazyval(0) {} // lazy e

	bool set;
	long long lazyval;
};
long long out_range = 0; // queryの範囲外の値 , mergeを考慮


typedef long long ll;
struct LazySegTreeP {

	long long N;
	vector<Node> dat;
	vector<Lazy> lazy;

	inline Node merge(Node& a, Node& b) { // node⊕node
		Node node;

		node.val = (a.val + b.val);

		return node;
	} //台数構造

	  // 命令を下のノードにpush
	void lazy_push(ll k, ll queryL, ll queryR) { // node⊕lazy
		if (lazy[k].set == 0)return; // 命令なし
		if (lazy[k].lazyval)dat[k].val = (queryR - queryL) - dat[k].val; //値の塗りつぶし += とかかも
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
		lazy[k].lazyval ^= val; // += ?
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

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, Q;
	scanf("%d%d", &N, &Q);
	HLD hld(N);
	FOR(i, 1, N) {
		int p; scanf("%d", &p);
		p--;
		hld.add_edge(p, i);
	}
	hld.build();

	LazySegTreeP seg(N);
	FOR(i, 0, N) {// 頂点iを0->1
		char c[2];
		scanf("%s", c);
		if (c[0] == 'G') {
			seg.lazy_update(hld.ps[i], hld.ps[i] + 1, 1);
		}
	}
	FOR(i, 0, Q) {
		int v; scanf("%d", &v);
		v--;
		seg.lazy_update(hld.ps[v], hld.pt[v],1);
		LL Wsum = seg.query(0, N).val;
		puts(2 * Wsum > N ? "broccoli" : "cauliflower");
	}


	return 0;
}


