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

/* -----  2017/05/01  Problem: JOI本戦 2012 1 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0603  ----- */
/* ------問題------

01でできた列がある、このうちの連続した区間を指定し、01をひっくりかえす。
最大で一回ひっくり返すことができるとして、このときの0101010...の最大の長さは。

-----問題ここまで----- */
/* -----解説等-----

01が連続している部分を圧縮して、0010111011010を14134みたいにする。
圧縮後の数字について隣り合うものは片方をひっくり返したときに連続した部分になるので、
この圧縮後の数列をBとしたときに B[i]+B[i+1]+B[i+2] を求めればいいことになる。
これをもう少し考えずに書いたので汚い感じになった。

----解説ここまで---- */

ll N;

int ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	int masu[100010];
	FOR(i, 1, N + 1)cin >> masu[i];
	int r[100010];
	FORR(i, N, 0) {
		if (masu[i] == masu[i + 1])r[i] = 1;
		else r[i] = r[i + 1] + 1;
	}
	int l = 0;
	FOR(i, 1, N + 1) {
		ans = max(ans, l + r[i] + r[i + r[i]]);
		if (masu[i] == masu[i - 1])l = 1;
		else l = l + 1;
	}
	cout << ans << endl;

	return 0;
}
