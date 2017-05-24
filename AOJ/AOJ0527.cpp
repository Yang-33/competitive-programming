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

/* -----  2017/05/24  Problem:  / Link:   ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

ll N;
int a[100010];
ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	while (1) {
		ans = 0;
		cin >> N;
		if (N == 0)break;
		pii s[100010];
		int go, k = 1, ans = 0;
		for (int i = 1; i <= N; ++i) {
			cin >> go;

			if (i == 1) {
				s[k++] = pii(i, go);
				continue;
			}

			if (s[k - 1].second != go) {
				if (i % 2) {
					s[k++] = pii(i, go);
				}
				else {
					if (k == 2)
						s[k - 1].second = go;
					else
						k--;
				}
			}
		}

		s[k] = pii(N + 1, 0);
		for (int i = 1; i < k; ++i) {
			if (s[i].second == 0)
				ans += s[i + 1].first - s[i].first;
		}

		cout << ans << endl;
	}
	return 0;
}
