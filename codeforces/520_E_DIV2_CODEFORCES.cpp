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

/* -----  __MAKE_TIME__  Problem: __PROBLEM__ / Link: __CONTEST_URL__  ----- */
/* ------問題------

木上で、頂点[L..R]を必ず含むLCAをQ回求める。
ただし、1頂点だけ消す事ができる。消して、LCAを根から深い位置にしたい。
この際の削除する頂点とLCAの根の深さを求めよ。

-----問題ここまで----- */
/* -----解説等-----

区間のLCAはlcaについての二項演算ができるのでOK
1つ削除する場所が決まったときも、区間を2つに分割するだけなので問題はない。
よって問題は削除するものをどのように決定するかになる。
これは、v->lca<-subtreeとなっている場合のみ、vを削除してsubtreeのtopをみることで良いと言える。
なぜなら、v以外にあるならばlcaは変化しないためである。
さて、これをどのように発見するかだが、二項演算で気合をする必要はない。
オイラーツアーを行ったときに、区間のはじめと最後だけを対象とすれば良い。
というのは、最も端のもの以外が候補となる場合は絶対にLCAが変わらないパターンだし、枝が可換であるならば、
結局端で良いと言えるからである。
ライブラリがいい感じなのでキレイにかけた。特にLCAのsparseTable.

----解説ここまで---- */



// O(1)
struct LCAT {
	int N;
	int it;
	vector<vector<PII>>table;
	vector<int>id;
	vector<vector<int>>G;
	LCAT(int N) :N(N), it(0), table(18, vector<PII>(2 * N)), id(N), G(N) {}
	void add_edge(int a, int b) {
		G[a].push_back(b);
		G[b].push_back(a);
	}
	void build(int root) {
		dfs(root, -1, 0);
		int m = (N << 1) - 1;
		int h = 31 - __builtin_clz(m);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j + (1 << i) < m; j++) {
				table[i + 1][j] = min(table[i][j], table[i][j + (1 << i)]);
			}
		}
	}
	void dfs(int v, int p, int d) {
		id[v] = it;
		table[0][it++] = { d, v };
		for (auto to : G[v]) {
			if (to == p)continue;
			dfs(to, v, d + 1);
			table[0][it++] = { d, v };
		}
	}
	int lca(int u, int v) {
		u = id[u], v = id[v];
		if (u > v) swap(u, v);
		int b = 31 - __builtin_clz(v + 1 - u);
		return min(table[b][u], table[b][v + 1 - (1 << b)]).second;
	}
};
PII et[100005];
void calc(const vector<vector<int>>&G, int root = 0) {
	int k = 0;
	stack<PII> s;
	s.push(PII(root, -1));
	while (!s.empty()) {
		PII q = s.top(); s.pop();
		int x = q.first, p = q.second;
		if (x < 0 || !x&&p>0) {
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

template< typename MeetSemilattice>
struct SparseTable {
	using T = typename MeetSemilattice::t;
	vector<vector<T>> st;

	SparseTable() {}

	SparseTable(const vector<T> &v) {
		int b = 0;
		while ((1 << b) <= v.size()) ++b;
		st.assign(b, vector<T>(1 << b));
		for (int i = 0; i < v.size(); i++) {
			st[0][i] = v[i];
		}
		for (int i = 1; i < b; i++) {
			for (int j = 0; j + (1 << i) <= (1 << b); j++) {
				st[i][j] = MeetSemilattice::op(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
			}
		}
	}
	// [l, r)
	inline T query(int l, int r) {
		int b = 32 - __builtin_clz(r - l) - 1;
		return (MeetSemilattice::op(st[b][l], st[b][r - (1 << b)]));
	}
};

struct Min {
	using t = int;
	static t op(const t&l, const t&r) { return min(l, r); }
};
struct Max {
	using t = int;
	static t op(const t&l, const t&r) { return max(l, r); }
};

int read() { int x; scanf("%d", &x); return x; }
void dfs(int v, int p, const VVI& G, VI& depth) {
	if (p == -1) {
		depth[v] = 0;
	}
	else {
		depth[v] = depth[p] + 1;
	}
	for (int nx : G[v]) {
		if (nx != p) {
			dfs(nx, v, G, depth);
		}
	}
}
int main() {

	int N = read(); int Q = read();
	static LCAT tree(N);
	VVI G(N);
	FOR(i, 0, N - 1) {
		int p = read() - 1;
		int c = i + 1;
		tree.add_edge(p, c);
		G[p].push_back(c);
		G[c].push_back(p);
	}
	tree.build(0);
	calc(G, 0);
	VI depth(N, 0);
	dfs(0, -1, G, depth);
	// 指定区間のin[v]の値,min/maxがほしい
	// in[v]に対する、vがほしい
	VI rev(N);
	FOR(i, 0, N) {
		rev[et[i].first] = i;
	}
	// 区間の端のin[v]がわかった。
	// これを除いたin[v]たちの、LCAがほしい
	VI etin(N);
	FOR(i, 0, N)etin[i] = et[i].first;
	SparseTable<Min>preOrderMin(etin);
	SparseTable<Max>preOrderMax(etin);
	struct lcatable {
		using t = int;
		static t op(const t&l, const t&r) { return tree.lca(l, r); }// これができるの最高すぎる
	};
	VI aa(N, 0);
	iota(ALL(aa), 0);
	SparseTable<lcatable> LcaTable(aa);

	FOR(_, 0, Q) {
		auto f = [&](int l, int v, int r) {// 区間が1つになりうるので場合分け
			if (l == v) {
				return LcaTable.query(v + 1, r + 1);
			}
			else if (v == r) {
				return LcaTable.query(l, v);
			}
			return tree.lca(LcaTable.query(l, v), LcaTable.query(v + 1, r + 1));
		};
		int L = read() - 1, R = read() - 1;
		// [L,R]
		int MinIn = preOrderMin.query(L, R + 1);
		int remV1 = rev[MinIn];
		int tops1 = f(L, remV1, R);
		int MaxIn = preOrderMax.query(L, R + 1);
		int remV2 = rev[MaxIn];
		int tops2 = f(L, remV2, R);
		if (depth[tops1] > depth[tops2]) {
			printf("%d %d\n", remV1 + 1, depth[tops1]);
		}
		else {
			printf("%d %d\n", remV2 + 1, depth[tops2]);
		}
	}



	return 0;
}