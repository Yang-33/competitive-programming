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

/* -----  2017/10/28  Problem:  SnackDown Online Qualifier 2017  » Temple Land / Link: https://www.codechef.com/SNCKQL17/problems/TEMPLELA  ----- */
/* ------問題------

数列が1から始まって1で終わる階段かを調べる。
ただしちゃんと頂上が1点のみ存在しなくてはならない

-----問題ここまで----- */
/* -----解説等-----

実際に見る。

----解説ここまで---- */

ll N;

ll ans = 0LL;

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	int S; cin >> S;

	for (int i = 0; i < S; i++) {
		int N; cin >> N;
		vector<int> H(N + 1);
		for (int j = 1; j <= N; j++) cin >> H[j];

		if (N % 2 == 0) { cout << "no" << endl; continue; }

		bool f = false;
		for (int k = 1; k < N / 2 + 1; k++) {
			if (H[k] != k || H[N + 1 - k] != k) {
				f = true;
			}
		}
		if (!f) { cout << "yes" << endl; }
		else {
			cout << "no" << endl;
		}
	}
}