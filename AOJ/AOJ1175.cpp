#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/06/27  Problem: ICPC2012国内予選D / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1175&lang=jp  ----- */
/* ------問題------

様々な色の円盤が盤面上に立体的に積み重なっている。
一番上でかつ色の同じ円盤のみを取り出すことを考えたときに取り出せる円盤の最大の枚数は。

-----問題ここまで----- */
/* -----解説等-----

bitDP.各円盤の情報に上にある円盤の数値を二進数bitで持たせると管理が楽。
dp[ 使用した円板の集合 ]:= 最大の取り出した円板の数　として計算する。
自分より若い番号の円盤しか乗っからないので、b[i]:= i番目の円盤の上にある円板(2進数表現)をもつことで
Ｏ(2^N*N^2)ぐらいになる。
AOJ上では int dp[1<<24]のメモリが足りないので、short int にする。char でもOK.
bitDPでは２進表現の値を別で持てる場合があるので気をつけれるといい。(グラフを持とうとしてどはまりした)ex:yukicoder 復元DPのやつ

----解説ここまで---- */


ll N;
short int dp[1 << 24];
short int ans = 0;
int x[25], y[25], r[25], c[25], b[25];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	while (1) {
		FOR(i, 0, 1 << 24)dp[i] = -1;
		cin >> N;
		if (N == 0)break;
		FOR(i, 0, N) {
			cin >> x[i] >> y[i] >> r[i] >> c[i];
			b[i] = 0;
			FOR(j, 0, i) {
				if ((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]) < (r[i] + r[j])*(r[i] + r[j])) b[i] |= (1 << j);
			}
		}

		dp[0] = 0;
		FOR(i, 0, 1 << N) {
			if (dp[i] < 0)continue;
			for (int j = 0; j < N - 1; j++) {
				if (((i >> j) & 1) == 0 && (i & b[j]) == b[j]) {
					for (int k = j + 1; k < N; k++) {
						if (c[j] == c[k] && ((i >> k) & 1) == 0 && (i & b[k]) == b[k]) {
							dp[i | (1 << j) | (1 << k)] = max(dp[i | (1 << j) | (1 << k)], (short int)(dp[i] + 2));
						}
					}
				}
			}
		}
		ans = 0;
		FOR(i, 0, 1 << N) {
			ans = max(ans, dp[i]);
		}
		cout << ans << endl;

	}
	return 0;
}
