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

/* -----  2018/11/14  Problem: EDU033_F / Link: http://codeforces.com/contest/893/problem/F  ----- */
/* ------問題------

vから深さkまでの部分木のうち、最小値

-----問題ここまで----- */
/* -----解説等-----

いつもの二次元クエリに帰着可能
†フラクショナルカスケーディング†で4000msとなった。

----解説ここまで---- */

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
		//DD(de("build end", SZ(v)));
	}
	// [l, r)
	inline T query(int l, int r) {
		int b = 32 - __builtin_clz(r - l) - 1;
		return (MeetSemilattice::op(st[b][l], st[b][r - (1 << b)]));
	}
};

struct M {
	using t = int;
	static t op(const t&l, const t&r) { return min(l, r); }
};

int N, R, V[100000];
vector< int > g[100000];
int in[100000], out[100000], dep[100000], ptr;

void dfs(int idx, int depth, int par)
{
	in[idx] = ptr++;
	dep[idx] = depth;
	for (auto &to : g[idx]) {
		if (to == par) continue;
		dfs(to, depth + 1, idx);
	}
	out[idx] = ptr;
}

int main()
{
	scanf("%d %d", &N, &R);
	--R;
	for (int i = 0; i < N; i++) {
		scanf("%d",&V[i]);
	}
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		--a, --b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	dfs(R, 0, -1);
	vector<	vector< pair< int, int > >> vs(N);
	vector< int > us(N);

	for (int i = 0; i < N; i++) {
		vs[in[i]].push_back({ dep[i], i });
		us[i] = V[i];
	}
	SegmentTreeFractionalCascading seg(vs, us); // ref:lib/datastructure/segmenttree2DStaticRangeQuery

	int M;
	scanf("%d", &M);
	int last = 0;
	for (int i = 0; i < M; i++) {
		int P, Q;
		scanf("%d %d", &P, &Q);
		int X = (P + last) % N;
		int K = (Q + last) % N;
		DD(de(X, K));
		printf("%d\n", last = seg.query(in[X], out[X], dep[X], dep[X] + K + 1));
	}
}