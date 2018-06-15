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

/* -----  2018/06/16  Problem: AOJ 2536 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2536  ----- */
/* ------問題------

全域木を作ったときの中央値の最小化。

-----問題ここまで----- */
/* -----解説等-----

全域木をつくったとき、中央値を下げるためには最小全域木にしていくしかない。
最小全域木でおわり

----解説ここまで---- */


struct UnionFind {
	VI data;
	UnionFind(int n) { data.assign(n, -1); }
	int rt(int x) {
		return data[x] < 0 ? x : data[x] = rt(data[x]);
	}
	bool same(int x, int y) {
		return rt(x) == rt(y);
	}
	bool merge(int x, int y) {
		x = rt(x), y = rt(y);
		if (x != y) {
			if (data[y] < data[x]) {
				swap(x, y);
			}
			data[x] += data[y];
			data[y] = x;
		}
		return x != y;
	}

};

// H
void solve() {
	int N, M;
	while (cin >> N >> M) {
		using tp = tuple<int, int, int>;
		vector<tp>edges;
		FOR(i, 0, M) {
			int a, b, c;
			cin >> a >> b >> c;
			a--, b--;
			edges.push_back(tp(c, a, b));
		}
		sort(edges.begin(), edges.end());
		UnionFind uf(N);
		int cnt = 0;
		FOR(i, 0, M) {
			int a, b, c;
			tie(c, a, b) = edges[i];
			if (!uf.same(a, b)) {
				uf.merge(a, b);
				if (cnt == (N - 1) / 2) {
					cout << c << endl;
				}
				cnt++;
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	solve();
	return 0;
}