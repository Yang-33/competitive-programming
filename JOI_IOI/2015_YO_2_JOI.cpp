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

/* -----  2017/04/17  Problem: JOI予選 2015 2  / Link:  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0620 ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

必ず隣の人にバトンを渡すので順にみていけばよい。
a[i] % k > a[i+1] % k　を満たせば交換すればいい。

----解説ここまで---- */



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	ll N, M;
	int a[105];

	ll ans = 0LL;

	cin >> N >> M;
	FOR(i, 0, N) {
		cin >> a[i];
	}


	FOR(k, 1, M+1) {
		FOR(i, 0, N-1) {
			if (a[i] % k > a[i+1] % k)swap(a[i], a[i + 1]);
		}
	}
	FOR(i, 0, N) {
		cout << a[i] << endl;
	}
	return 0;
}
