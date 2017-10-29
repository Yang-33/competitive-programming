#include "bits/stdc++.h"
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

/* -----  2017/10/04  Problem: Nagoya_univ_contest_17_a  / Link: http://abc073.contest.atcoder.jp/tasks/abc073_d  ----- */
/* ------問題------

Atcoder国には N 個の町があり、M 本の双方向に移動可能な道で結ばれています。
また、 i 本目の道は町 Ai と町 Bi の間を距離 Ci で結んでいます。
joisinoお姉ちゃんは、この国の R 個の町 r1,r2..rR を訪れることとなりました。
最初に訪れる町までの移動と、最後に訪れる町からの移動は空路で行うが、それ以外は道を使わなければなりません。
町を訪れる順番を、道での移動距離が最小となるように決めた時の移動距離を答えてください。

-----問題ここまで----- */
/* -----解説等-----

ワーシャルフロイド法をして全点間の最短距離を出してから、
指定された点のbitDPをすればよい。
無向グラフなので両方に辺を張るのを忘れないように！
FORってたくさんでてきてウケた

----解説ここまで---- */

LL N,R,M;
int msvisit[10];
LL ans = 0LL;
LL d[202][202];
LL dp[1 <<10 ][10];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>M>>R;
	FOR(i, 0, R) {
		cin >> msvisit[i];
		msvisit[i]--;
	}
	FOR(i, 0, 202) {
		FOR(j, 0, 202) {
			d[i][j] = LINF;
		}
		d[i][i] = 0;
	}
	FOR(i, 0, M) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		d[a][b] = min(d[a][b], (LL)c);
		d[b][a] = min(d[b][a], (LL)c);
	}
	FOR(k, 0, N) {
		FOR(i, 0, N) {
			FOR(j, 0, N) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	FOR(i, 0, (1 << R))FOR(j, 0, 10)dp[i][j] = LINF;
	FOR(i, 0, R) {
		dp[(1<<i)][i] = 0;
	}
	//うめる
	FOR(i, 0, (1 << R)) {
		FOR(j, 0, R) {
			if(i&(1<<j))
			FOR(k, 0, R) {
				if (i&(1 << k))continue;
				dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k],dp[i][j]+d[msvisit[j]][msvisit[k]] );
			}
		}
	}


	ans = LINF;
	FOR(i, 0, R) {
		ans = min(ans, dp[(1<<R)-1][i]);
	}

	cout << ans << "\n";

	return 0;
}