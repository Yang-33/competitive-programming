#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const ll INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
ll dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
ll dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/04/19  Problem:  / Link:   ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

到達駅について考えると、急行の停車駅が遠いときは到達可能な点から一個遠い点を、
準急の駅にすればよい。ただしそうできるのはK-M個の駅だけなので、
感覚が最大になるような駅をとりたくなる。すべて列挙し大きいものだけを見ればよい。
ans-1はs[M]を作った分。実装が楽になるので

----解説ここまで---- */

ll N, M, K, A, B, C, T;

ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> K >> A >> B >> C >> T;
	ll s[3010];

	FOR(i, 0, M) {
		cin >> s[i];
	}
	s[M] = N + 1;
	vector<ll> v;
	FOR(i, 0, M) {
		ll c = (s[i] - 1)*B;
		ll cv = max(0LL, (T - c) / A + 1);
		ll ss = s[i];
		ll pos = s[i] + cv;
		if (c > T)break;
		if (pos > s[i + 1])pos = s[i + 1];
		ans += pos - ss;
		FOR(j, 0, K - M) {
			if (pos >= s[i + 1])break;
			c += (pos - ss)*C;
			if (c > T)break;
			cv = max(0LL, (T - c) / A + 1);
			ss = pos;
			pos += cv;
			if (pos > s[i + 1])pos = s[i + 1];
			v.pb(pos - ss);

		}

	}

	sort(v.rbegin(), v.rend());
	FOR(i, 0, K - M) {
		if (i < (ll)v.size()) {
			ans += v[i];
		}
	}

	cout << ans - 1 << endl;
	return 0;
}
