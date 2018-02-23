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

/* -----  2018/02/15  Problem: 073_abc_d / Link: https://abc073.contest.atcoder.jp/tasks/abc073_d?lang=en  ----- */
/* ------問題------

Atcoder国には N 個の町があり、M 本の双方向に移動可能な道で結ばれています。
また、 i 本目の道は町 Ai と町 Bi の間を距離 Ci で結んでいます。
joisinoお姉ちゃんは、この国の R 個の町 r1,r2..rR を訪れることとなりました。
最初に訪れる町までの移動と、最後に訪れる町からの移動は空路で行うが、それ以外は道を使わなければなりません。
町を訪れる順番を、道での移動距離が最小となるように決めた時の移動距離を答えてください。

-----問題ここまで----- */
/* -----解説等-----

巡回セールスマン的なbitDPをすればいいね

----解説ここまで---- */

LL N, M, R;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> R;
	VI r(R);
	FOR(i, 0, R) {
		cin >> r[i];
		r[i]--;
	}

	VI a(M), c(M), b(M);
	VVL dist(N, VL(N, LINF));

	FOR(i, 0, M) {
		cin >> a[i] >> b[i] >> c[i];
		a[i]--, b[i]--;
		dist[a[i]][b[i]] = dist[b[i]][a[i]] = min((LL)c[i], dist[a[i]][b[i]]);
	}
	FOR(i, 0, N)dist[i][i] = 0;
	FOR(k, 0, N) {
		FOR(i, 0, N) {
			FOR(j, 0, N) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	VVL d(1 << R, VL(R, LINF));
	FOR(i, 0, R) {
		d[1 << i][i] = 0;
	}

	FOR(state, 0, 1 << R) {
		FOR(k, 0, R) {
			if(state&(1<<k))
			FOR(i, 0, R) {
				if (!(state&(1 << i)))
					d[state | 1 << i][i] = min(d[state | 1 << i][i], d[state][k] + dist[r[k]][r[i]]);
			}
		}
	}
	ans = LINF;
	FOR(i, 0, R) {
		ans = min(ans, d[(1 << R) - 1][i]);
	}

	cout << ans << "\n";

	return 0;
}
