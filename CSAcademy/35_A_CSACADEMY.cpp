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

/* -----  2017/10/02  Problem: CS academy 35 A / Link: https://csacademy.com/contest/round-35/task/refrigerator-letters/  ----- */
/* ------問題------

現在所有しているアルファベット列がある。
必要な文字列が与えられるので、不足分を求めよ

-----問題ここまで----- */
/* -----解説等-----

愚直に調べる。

----解説ここまで---- */

ll N;
char c[104];
int a[30];
int b[30];
ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 0, N) {
		cin >> c[i];
		a[c[i] - 'a']++;
	}
	string s;
	cin >> s;
	FOR(i, 0, s.size()) {
		b[s[i] - 'a']++;
	}

	FOR(i, 0, 30) {
		int x = 0;
		if (b[i] - a[i] >= 0) {
			ans += b[i] - a[i];
		}
	}
	cout << ans << endl;

	return 0;
}
