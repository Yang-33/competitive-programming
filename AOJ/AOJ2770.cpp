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

/* -----  2018/06/09  Problem: AOJ 2770 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2770  ----- */
/* ------問題------

湖に浮かぶ N 個の小島からなるビワコという村がある．
ビワコ村には N−1 本の簡単な作りの橋がある．
島には 0 から N−1 まで，橋には 0 から N−2 までの番号が付けられている．
i 番の橋は i+1 番の島と pi 番の島を直接つなぎ，長さは wi である．
村人はどの島の間もいくつかの橋を通って相互に移動できるようになっている．
ある村人の提案により，ビワコ村でリレー大会が開催されることとなった．
しかし，ビワコ村には閉路がなくトラックを用意できないため， 現在ある橋を 1 つだけ掛け替えることによって閉路を作ろうと考えた．
この操作によって用意できる閉路のうち，長さが最大となるものの長さを求めなさい．

-----問題ここまで----- */
/* -----解説等-----

segtreeでごにょればイケルと思ったけど全然ダメだった。(判例ありすぎ)
直径を考える。直径だけではダメそう。
直径の両端のどちらかを根にする。
直径に含まれない辺ならば、直径+その辺、のmaxを取れば良い
直径に含まれる辺のとき、直径を切ったときの長い方+辺->場合分けが大変なので両側からやれば良い。
これは部分木にアクセスできない感じにして、pathの最大値を選択すれば良いことになる。
部分木を扱うので、eulartourなどすればいい感じにできる。

引数にいろいろ書くのがめんどくさいので、ライブラリ以外はまたglobalに置こうかという気持ちになった。

----解説ここまで---- */

struct nd {
	long long v;
	nd(long long v = 0) :v(v) {} // ! e
};
struct SegmentTreeFastAry {
	nd merge(nd& l, nd& r) {
		nd ret;
		ret.v = max(l.v, r.v);
		return ret;
	}
	void updatepoint(nd& node, nd& nx) { // point update 
		node.v = nx.v;
	}
	void addpoint(nd& node, nd& nx) { // point add
		node.v += nx.v;
	}
	// -- setting -- // 
	int ARY_SIZE; nd node[1<<19];
	void init(int n) { ARY_SIZE = 1; while (ARY_SIZE < n) ARY_SIZE <<= 1; }
	SegmentTreeFastAry(int n) : ARY_SIZE(1) { init(n); }
	inline void update(int i, nd& val) {
		i += ARY_SIZE; updatepoint(node[i], val);
		while (i > 1) { i >>= 1;	node[i] = merge(node[i << 1], node[(i << 1) + 1]); }
	}
	inline void add(int i, nd& val) {
		i += ARY_SIZE; addpoint(node[i], val);
		while (i > 1) { i >>= 1; node[i] = merge(node[i << 1], node[(i << 1) + 1]); }
	}
	inline nd query(int l, int r) {
		if (l >= r) return nd(); nd vl = nd(), vr = nd();
		for (l += ARY_SIZE, r += ARY_SIZE; l != r; l >>= 1, r >>= 1) {
			if (l & 1) vl = merge(vl, node[l++]); if (r & 1) vr = merge(node[--r], vr);
		}	return merge(vl, vr);
	}
	nd operator[](int i) { return node[i + ARY_SIZE]; }
	void debugShow() { for (int i = ARY_SIZE; i < ARY_SIZE << 1; ++i) cerr << node[i].v << " "; cerr << "\n"; }
};

PLL didfs(int v, int p, const vector<vector<PLL>>&G) {
	PLL ret = PLL(0, v);
	FOR(i, 0, SZ(G[v])) {
		if (G[v][i].first == p)continue;
		PLL temp = didfs(G[v][i].first, v, G);
		temp.first += G[v][i].second;
		ret = max(ret, temp);
	}
	return ret;
}

PLL diamiter(const vector<vector<PLL>>& G) {
	PLL p = didfs(0, -1, G);
	PLL q = didfs(p.second, -1, G);
	return PLL(p.second, q.second);
}
void dfs(int v, int p, LL dep, VL& depth, const vector<vector<PLL>>& G) {
	depth[v] = dep;
	FOR(i, 0, SZ(G[v])) {
		if (G[v][i].first == p)continue;
		dfs(G[v][i].first, v, dep + G[v][i].second, depth, G);
	}
}

int idx = 0;
void eulartour(int v, int p, VL& b, VL& e, const vector<vector<PLL>>& G) {
	b[v] = idx++;
	FOR(i, 0, SZ(G[v])) {
		if (G[v][i].first == p)continue;
		eulartour(G[v][i].first, v, b, e, G);
	}
	e[v] = idx;
}

LL solve(LL root, const vector<vector<PLL>>& G) {
	idx = 0;
	int N = SZ(G);
	VL depth(N, 0);
	dfs(root, -1, 0, depth, G);
	VL begin(N, 0), end(N, 0);
	eulartour(root, -1, begin, end, G);
	SegmentTreeFastAry seg(N);
	FOR(i, 0, N) {
		nd val(depth[i]);
		seg.update(begin[i], val);
	}
	LL ret = 0;
	FOR(i, 0, N) {
		FOR(j, 0, SZ(G[i])) {
			int nx = G[i][j].first;
			int pos = (depth[i] < depth[nx] ? nx : i);
			LL longest = max(seg.query(0, begin[pos]).v, seg.query(end[pos], N).v);
			ret = max(ret, longest + G[i][j].second);
		}
	}
	return ret;
}



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;	cin >> N;
	vector<vector<PLL>>G(N);
	FOR(i, 1, N) {
		int p, c;
		cin >> p >> c;
		G[p].emplace_back(i, c);
		G[i].emplace_back(p, c);
	}
	PLL di = diamiter(G);
	LL ans = max(solve(di.first, G), solve(di.second, G));

	cout << ans << "\n";

	return 0;
}
