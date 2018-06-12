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

/* -----  2018/06/13  Problem: AOJ 1350 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1350  ----- */
/* ------問題------

連結グラフGにおいて、最小全域木を作るときに必ず必要な辺と、そのコストの和は?

-----問題ここまで----- */
/* -----解説等-----

数が少ないので愚直でよい。mstに使う辺を使わないで作ったときに、もとと同じサイズでなければ絶対に使う。(大きくなるのは自明にダメで小さくなるときはinput1みたいなやつ)
HL分解だと最強でN,M<=10^5とかでも解ける

----解説ここまで---- */

struct UnionFind {
	vector<int> data;
	UnionFind(int n) { data.assign(n, -1); }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, E;

	cin >> N>>E;
	using tp = tuple<int, int, int>;
	vector<tp>edges;
	FOR(i, 0, E) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		edges.push_back(tp(c, a, b));
	}
	SORT(edges);
	UnionFind ufa(N);
	LL mstmin = 0;
	vector<tp>useq;
	FOR(i, 0, E) {
		LL c, a, b;
		tie(c, a, b) = edges[i];
		if (!ufa.same(a, b)) {
			ufa.unionSet(a, b);
			mstmin += c;
			useq.push_back(edges[i]);
		}
	}
	int cnt = 0; LL sum = 0;
	FOR(j, 0, SZ(useq)) {
		LL cc, aa, bb;
		tie(cc, aa, bb) = useq[j];
		LL mst = 0;
		UnionFind uf(N);
		FOR(i, 0, E) {
			LL c, a, b;
			tie(c, a, b) = edges[i];
			if (!uf.same(a, b)&& !(aa==a&&bb==b)) {
				uf.unionSet(a, b);
				mst += c;
			}
		}
		if (mst != mstmin) {
			cnt++;
			sum += cc;
		}
	}
	cout << cnt << " " << sum << "\n";

	return 0;
}
