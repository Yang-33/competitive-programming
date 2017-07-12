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
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

/* -----  2017/07/12  Problem: AOJ 2745  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2745  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

後から水をいれれば必ず薄くなるので、取りあえず濃度をC以上になるようにルーをどんどん入れていけばいい。

----解説ここまで---- */


ll R, C, W, R0;

ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	while (1) {
		cin >> R0 >> W >> C >> R;
		ans = 0;
		if (!(R0 || W || C || R))break;
		while (1) {
			if (R0 / W >= C) {
				cout << ans << endl;
				break;
			}
			R0 += R;
			ans++;
		}
	}

	return 0;
}