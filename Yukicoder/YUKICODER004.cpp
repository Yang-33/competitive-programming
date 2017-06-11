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

/* -----  2017/06/11  Problem: yukicoder004 / Link: http://yukicoder.me/problems/no/4  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

全部使うので全部の総和が偶数でなければならない。
おもりを置く順序を固定しなければこれは重さについてのｄｐに帰着できる。
dp[ 現在作成可能なおもさ ]:= 作成可能/作成不可能
として重さを遷移していけばよい・

dp[sum/2]が存在すれば使用していないおもりでもsum/2を作ることができ、
したがってこれは作成可能だが、sumが奇数である場合は作成できない。

----解説ここまで---- */

ll N;

ll ans = 0LL;
ll w[105];
bool dp[10050];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	bool f = 0;
	ll sum = 0;
	FOR(i, 0, N) {
		cin >> w[i];
		sum += w[i];
	}
	FOR(i, 0, 10050)dp[i] = 0;

	dp[0] = 1;

	FOR(i, 0, N) {
		for (int j = 10000; j - w[i] >= 0; j--) {
			if (dp[j - w[i]])
				dp[j] |= dp[j - w[i]];
		}
	}
	if (dp[sum / 2])f = 1;
	if (sum % 2 == 1)f = 0;
	if(f)
		cout << "possible" << endl;
	else cout <<"impossible" << endl;

	return 0;
}
