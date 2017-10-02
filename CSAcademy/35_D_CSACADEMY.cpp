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

/* -----  2017/10/02  Problem: CS academy 35 D / Link: https://csacademy.com/contest/round-35/task/least-even-digits/  ----- */
/* ------問題------

整数Xがある。
の整数の各桁が偶数である数よりも小さい数Yが含まれている連続した区間について、この区間の選択は何通りあるか。
-----問題ここまで----- */
/* -----解説等-----

X≦10^9であり、どのような数字があっても区間の幅は10^8ぐらいにおさまる
組み合わせはXの両端を別々に見ればよいので、O(1)でわかる
あとは気合で全探索+若干の高速化

----解説ここまで---- */

ll N;

ll ans = 0LL;
int fd(ll num,ll t) {
	int cnt = 0;
	while (num != 0) {
		if (num % 2 == 0)cnt++;
		if (cnt >= t)return 1;
		num /= 10;
	}
	return cnt>=t ;
}
int main() {
	//cin.tie(0);
	//ios_base::sync_with_stdio(false);

	scanf("%lld", &N);
//	cin >> N;
	ll x = N;
	int cnt = 0;
	while (x != 0) {
		if (x % 2 == 0)cnt++;
		x /= 10;
	}
	if (cnt == 0) {
		cout << -1 << endl;
		return 0;
	}
	//up
	ll maxn = N;
	for (;;) {
		if (!fd(maxn,cnt)) {
			maxn--;
			break;
		}
		maxn++;
	}

	//down
	ll minn = N-1;
	for (;;) {
		if (!fd(minn,cnt)) {
			minn++;
			break;
		}
		minn--;
	}
	ans = (N - minn + 1)*(maxn - N + 1);
	
	printf("%lld\n", ans);
	//cout << ans << endl;

	return 0;
}
