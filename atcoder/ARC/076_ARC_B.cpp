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
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/02/27  Problem: 076_arc_b / Link: https://arc076.contest.atcoder.jp/tasks/arc076_b?lang=en  ----- */
/* ------問題------

平面上に、N 個の街があります。i 個目の街は、座標 (xi,yi) にあります。同じ座標に、複数の街があるかもしれません。
座標 (a,b) にある街と座標 (c,d) にある街の間に道を造るのには、min(|a−c|,|b−d|) 円かかります。街と街の間以外に、道を造ることはできません。
任意の 2 つの街の間を、道を何本か通って行き来できるようにするためは、最低で何円必要でしょうか。

-----問題ここまで----- */
/* -----解説等-----

あとで最小全域木をつくるならx,y別の辺を貼ればよい。
最小を選択すれば良いのでx,yは独立して考えることができる。
各軸について最小化するとき、明らかに近いものに辺をつなげたほうが良い。
従って各軸について独立にsortしてやる

----解説ここまで---- */

LL N;

LL ans = 0LL;

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

	cin >> N;

	using tp = tuple<LL, int, int>;
	vector<PII>a(N);
	vector<PII>b(N);
	UnionFind uf(N);
	vector<tp> edge;

	FOR(i, 0, N) {
		int x, y;
		cin >> x >> y;
		a[i] = PII(x, i);
		b[i] = PII(y, i);
	}


	SORT(a);
	SORT(b);
	FOR(i, 0, N - 1) {
		edge.push_back(tp(abs(a[i].first - a[i + 1].first), a[i].second, a[i + 1].second));
		edge.push_back(tp(abs(b[i].first - b[i + 1].first), b[i].second, b[i + 1].second));
	}

	SORT(edge);

	FOR(i, 0, SZ(edge)) {
		LL a, b, c;
		tie(a, b, c) = edge[i];
		if (!uf.same(b, c)) {
			ans += a;
			uf.unionSet(b, c);
		}
	}


	cout << ans << "\n";

	return 0;
}
