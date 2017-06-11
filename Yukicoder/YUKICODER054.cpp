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

/* -----  2017/06/11  Problem: yukicoder054 / Link: http://yukicoder.me/problems/no/54  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

順序が大事で、bitdpはできないので順序を自分で考える。
x番目とy番目で、どちらが先に訪れるのがうれしいかを考える。
x番目に先に訪れることでy番目を先に訪れた時よりも確実に良い結果を残すとき、
片側ではキャンディーを獲得できて片側では獲得できない状況が存在し、現在のキャンディー所持数をKとすると
K+v[x]<t[y], K+v[y]≧t[x]、と表現できる。
Kについて、t[x]-v[y]≦K<t[y]-v[x]、はさんでいる式について整理すれば
t[x]+v[x]<t[y]+v[y]のとき、xに先に訪れるのが最適といことになる。

したがってv+tが小さい順番に訪問していけばよく、これをdpで回していけばよい。
具体的にはある値Vについて、今までの情報から作成可能かつt[i]未満ならばV+v[i]も作成可能であるとすればよい。
dp[ 現在作成可能なキャンディー保持数 ]:=　作成可能/作成不可能

----解説ここまで---- */

ll N;
ll v[10100];
ll t[10100];
pll p[10100];
ll dp[30010];
ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 0, N) {
		cin >> v[i] >> t[i];
		p[i] = mp(v[i] + t[i], i);
	}

	sort(p, p + N);

	dp[0] = 1;
	FOR(i, 0, N) {
		int s = p[i].second;
		FORR(j, t[s]-1, -1) {
			if (dp[j]) {
				dp[j + v[s]]++;
			}
		}
	}
	FOR(i, 0, 20000 + 1) {
		if (dp[i])
			ans = max(ans, i);
	}
	cout << ans << endl;

	return 0;
}
