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

/* -----  2018/07/05  Problem: AOJ 3004 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/3004  ----- */
/* ------問題------

とある会社のネットワーク上にはn台のコンピュータと、それらをつなぐm本の通信ケーブルがある。コンピュータは0からn−1までの識別子で区別され、通信ケーブルもまた0からm−1までの識別子をもつ。
現在この会社にある任意の異なる2台のコンピュータは、いくつかの通信ケーブルを介して相互に通信することができるが、通信経路がただ一つに定まるとは限らない。
このネットワークには、通信ケーブルが多すぎて絡まってしまうという問題がある。そこであなたは、任意の通信について通信経路がただ一つになるようにいくつかの通信ケーブルを取り除くことにした。
通信ケーブルiはコンピュータaiとbiを双方向につなぎ、その長さはciである。また、あなたが通信ケーブルiを取り除く際にかかる労力はdiである。
作業を始める前に、あなたは取り除く通信ケーブルの長さの和に対する、作業を終えるまでにかかる労力の和の比を「おっくう感」とし、最小のおっくう感を見積もることにした。
ただし、一つも取り除けない場合のおっくう感は0である。

-----問題ここまで----- */
/* -----解説等-----

平均値最小化をしたい。選び方は全域木側に正の値をなるべく割り振れれば嬉しい。

----解説ここまで---- */


struct UnionFind {
	vector<int> data;
	UnionFind(int n) { data.assign(n, -1); }
	bool unite(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};

using vc = const vector<int>&;
bool f(vc a, vc b, vc c, vc d, double X, int N) {
	using tp = tuple<double, int, int>;
	vector<tp>edge;
	FOR(i, 0, SZ(a)) {
		edge.push_back(tp((double)d[i] - X * (double)c[i], a[i], b[i]));
	}
	sort(edge.rbegin(), edge.rend());
	double sum = 0.0;
	UnionFind uf(N);
	FOR(i, 0, SZ(a)) {
		int A, B; double D;
		tie(D, A, B) = edge[i];
		if (!uf.same(A, B)) {
			uf.unite(A, B);
		}
		else {
			sum += D;
		}
	}
	return sum <= 0.0;
}



void solve() {
	int N, M;
	cin >> N >> M;
	vector<int> a(M), b(M), c(M), d(M);
	FOR(i, 0, M) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	double L = 0; double R = INF;
	FOR(i, 0, 100) {
		double mid = (L + R) / 2.0;
		if (f(a, b, c, d, mid, N)) {
			R = mid;
		}
		else {
			L = mid;
		}
	}
	cout << fixed << setprecision(10) << R << endl;

}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	solve();

	return 0;

}