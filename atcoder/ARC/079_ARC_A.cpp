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

/* -----  2017/07/29  Problem: ARC 079 A / Link: http://arc079.contest.atcoder.jp/tasks/arc079_a  ----- */
/* ------問題------

高橋キングダムには、高橋諸島という、N 個の島からなる諸島があります。 便宜上、これらの島を島 1、島 2、 ...、島 N と呼ぶことにします。
これらの諸島の間では、船の定期便が M 種類運行されています。 定期便はそれぞれ 2 つの島の間を行き来しており、i 種類目の定期便を使うと、 島 ai と島 bi の間を行き来する事ができます。
すぬけくんは今島 1 にいて、島 N に行きたいと思っています。 しかし、島 1 から島 N への定期便は存在しないことがわかりました。
なので、定期便を 2 つ使うことで、島 N に行けるか調べたいと思っています。
これを代わりに調べてあげてください。

-----問題ここまで----- */
/* -----解説等-----

INPOSSIBLEにして悲しい思いになった。
M辺以下の辺しか見ないので1->v->Nを直接探して見ればよい。

----解説ここまで---- */

ll N;
vector<int>G[200010];
ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll M;
	cin >> N>>M;
	FOR(i, 0, M) {
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	FOR(i, 0, G[1].size()) {
		int v = G[1][i];
		FOR(j, 0, G[v].size()) {
			if (G[v][j] == N) {
				cout << "POSSIBLE" << endl;
				return 0;
			}
		}
	}
	cout <<"IMPOSSIBLE" << endl;

	return 0;
}
