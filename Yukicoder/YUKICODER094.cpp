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

/* -----  2018/04/19  Problem: yukicoder 094  / Link: http://yukicoder.me/problems/no/094  ----- */
/* ------問題------

太郎君と二郎君は、無線機を使って会話をしています。

二人が使用している無線機は、電波を使ってお互いに直接通信し、
1kmの距離まで会話をすることができます。
またそれ以外にも、中継局を1つ以上間に挟むことで通信距離を延長することもできます。

無線機と中継局の間は、1km以内までしか通信できませんが、
中継局と中継局の間は、10km以内まで通信することができます。
(それぞれ1kmちょうど、10kmちょうどを含みます。)

2次元平面上に N本の中継局が立っており、
その位置は Xi,Yi (1≤i≤N)で表されます。

太郎君と二郎君はこれらの中継局をすべて自由に使用することができ、
また、太郎君と二郎君は無線機を持って2次元平面上を自由に移動できるとするとき、
太郎君と二郎君が、「直接」または「中継局を用いて間接的に」会話ができる
太郎君と二郎君の直線距離(ユークリッド距離)の最大を求めてください。

-----問題ここまで----- */
/* -----解説等-----

group分けして、グループ内の最長距離+2が答え。  
答えの最小は1

----解説ここまで---- */

struct UnionFind {
	vector<int> data; int N;
	UnionFind(int n) { data.assign(n, -1); N = n; }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
			N--;
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

	LL N; cin >> N;
	VI x(N), y(N);
	FOR(i, 0, N) {
		cin >> x[i] >> y[i];
	}
	UnionFind uf(N);
	FOR(i, 0, N) {
		FOR(j, 0, i) {
			int dist = pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2);
			if (dist <= 10 * 10) {
				uf.unionSet(i, j);
			}
		}
	}
	double ans = 1;
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			if (uf.same(i, j)) {
				int dist = pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2);
				ans = max(ans, sqrt(dist) + 2);
			}
		}
	}

	cout <<fixed<<setprecision(10)<< ans << "\n";

	return 0;
}
