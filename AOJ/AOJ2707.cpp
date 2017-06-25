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

/* -----  2017/06/25  Problem: AOJ 2707  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2707  ----- */
/* ------問題------

Jail
Kの倍数番目の値を削除し、さらにこれを詰めなおしてK番目の値を削除する。
N回目に削除する際に最初に消える数字は。

-----問題ここまで----- */
/* -----解説等-----

数字の対応を見たときに、削除後の列は前の列についてK-1この塊になっている。
0->× 1->0 2->1 .... k-2->k-3 k-1->k-2 k->× k+1->k-1 k+2->k ....
削除後の値を見たときに削除前の数字はnum/k-1にK倍し、箱の中についてnum%(K-1)+1したものが答えになっている。
これをN-1回繰り返し、頭の数字が解答になる。

----解説ここまで---- */


ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	ll N, K;
	cin >> N >> K;

	FOR(i, 0, N - 1) ans = K * (ans / (K - 1)) + ans % (K - 1) + 1;

	cout << ans << endl;

	return 0;
}
