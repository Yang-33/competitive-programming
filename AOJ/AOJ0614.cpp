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

/* -----  2017/07/07  Problem: AOJ 0614 JOI 2014 (NU contest 14 C) / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0614  ----- */
/* ------問題------

みて

-----問題ここまで----- */
/* -----解説等-----

何回鉄道を利用したかによって紙切符かICカードのいづれかを使うかを変更したい。
これは累積和をとれば高速に区間の利用回数を求めることができる。
移動位置が大きい番号の駅から小さい番号の駅を示している場合があるのでこれは反転させればよい。
その後は運賃をもとに旅費を計算すればよい。
添え字でちょっと時間を費やした。

----解説ここまで---- */
ll N, M;
int p[100005];
ll sum[100005];
ll ans = 0LL;
int a[100005];
int b[100005];
int c[100005];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	FOR(i, 0, M) {
		cin >> p[i];
		p[i]--;
	}

	FOR(i, 0, M - 1) {
		int a = p[i];
		int b = p[i + 1];
		if (a > b)swap(a, b);
		sum[a]++;
		sum[b]--;
	}

	FOR(i, 1, 100005) {
		sum[i] += sum[i - 1];
	}

	FOR(i, 0, N - 1) {
		cin >> a[i] >> b[i] >> c[i];
	}
	FOR(i, 0, N) {
		ans += min(a[i] * sum[i], c[i] + b[i] * sum[i]);
	}


	cout << ans << endl;

	return 0;
}
