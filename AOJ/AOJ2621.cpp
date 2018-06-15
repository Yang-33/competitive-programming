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

/* -----  2018/06/16  Problem: AOJ 2621 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2621  ----- */
/* ------問題------

k点選択して、その長方形領域の面積で重みを割る。
この平均重み的なものを最大化せよ。

-----問題ここまで----- */
/* -----解説等-----

面積1から広げることを考える。
広げたときに平均的なものが大きくなったとすると、a<bみたいな関係になる。
これは面積を増やしても平均的なものを大きくはできないことを示したことになる。
したがって面積1を最大化すれば良い。
ある点の8方をみればよい。

----解説ここまで---- */


// H
void solve() {
	int N;
	cin >> N;
	using PLL = pair<LL, LL>;
	map<PLL, LL>Map;

	VL y(N), x(N);
	FOR(i, 0, N) {
		LL w;
		cin >> x[i] >> y[i] >> w;
		Map[PLL(y[i], x[i])] = w;
	}
	LL ans = 0;
	int dy[] = { -1, -1, 0, 1, 1, 1 , 0, -1, };
	int dx[] = { 0 , 1 , 1, 1, 0, -1,-1, -1, };
	FOR(i, 0, N) {
		FOR(k, 0, 8) {
			if (k % 2 == 0) {
				LL val = Map[PLL(y[i], x[i])];
				FOR(p, 0, 3) {
					int state = (k + p) % 8;
					LL ny = y[i] + dy[state];
					LL nx = x[i] + dx[state];
					if (Map.find(PLL(ny, nx)) == Map.end())continue;
					val += Map[PLL(ny, nx)];
				}
				ans = max(ans, val);
			}
		}
	}
	cout << ans << " / 1" << endl;

}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	solve();
	return 0;
}
