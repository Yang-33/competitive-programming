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

/* -----  2017/06/12  Problem: AOJ 1167  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1167&lang=jp ----- */
/* ------問題------

F(n)=n(n+1)(n+2) ⁄ 6と現わせる。
与えらえたNに対して最小のF(n)どうしのの組み合わせは？
また奇数のF(n)だけで作る際の最小の組み合わせは？

-----問題ここまで----- */
/* -----解説等-----

DP.
dp[ 数字 ] := この数字を作る際の最小のF()の個数
dp2[ 数字 ] := この数字を作る際の最小の奇数のF()の個数
としてまわしていけばよい。
最大の値をとるF(k)はK≦200なので、
Ｏ(K*(max(N)))でまにあう。

----解説ここまで---- */

ll N;

ll ans = 0LL;
ll ans2 = 0LL;
vector<ll>v;
ll dp[1000010];
ll dp2[1000010];

void calc() {
	FOR(i, 0, 1000010)dp[i] = INF;
	FOR(i, 0, 1000010)dp2[i] = INF;
	ll part = 0;
	for (int i = 1; part < 1e6 + 1; i++) {
		part = i*(i + 1)*(i + 2) / 6;
		v.push_back(part);
	}

	dp[0] = dp2[0] = 0;
	FOR(i, 0, v.size()) {
		FOR(j, v[i], 1000010) {
			dp[j] = min(dp[j], dp[j - v[i]] + 1);
			if (v[i]%2==1) {
				dp2[j] = min(dp2[j], dp2[j - v[i]] + 1);
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	calc();
	while (1) {
		cin >> N;
		if (N == 0)break;
		ans = ans2 = 0;
		ans = dp[N];
		ans2 = dp2[N];



		cout << ans << " " << ans2 << endl;
	}
	return 0;
}
