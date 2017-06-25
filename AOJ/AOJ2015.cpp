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

/* -----  2017/06/12  Problem: AOJ 2015  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2015&lang=jp ----- */
/* ------問題------

長方形に分割された土地の交差点の位置が与えらえる。
この土地の中に正方形はいくつあるか。

-----問題ここまで----- */
/* -----解説等-----

全ての差分をとることができるので縦と横の累積和から、値の組み合わせを考えればよい。

----解説ここまで---- */

int H, W;
int h[1505];
int w[1505];
int wid[1500100];
int ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	for (;;) {
		ans = 0;
		FOR(i, 0, 1500100)wid[i] = 0;
		cin >> H >> W;
		if (H == 0 && W == 0)break;
		FOR(i, 1, H + 1)cin >> h[i], h[i] += h[i - 1];
		FOR(i, 0, H) {
			FOR(j, 0, i+1) {
				wid[h[1 + i] - h[ j]]++;
			}
		}
		FOR(i, 1, W + 1)cin >> w[i], w[i] += w[i - 1];
		FOR(i, 0, W) {
			FOR(j, 0, i + 1) {
				int num = w[1 + i] - w[j];
				if (num <= 0)continue;
				if (wid[num])ans+=wid[num];
			}
		}
		cout << ans << endl;
	}
	return 0;
}
