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

/* -----  2017/10/02  Problem: Kotamanegi OJ 018  / Link: https://kotamanegi.com/JudgeSystem/Problems/view/index.php?page=18  ----- */
/* ------問題------

あるお土産屋ではN個の袋入りまんじゅうを売っていて、i個目の袋にはAi個のまんじゅうが入っています。
C3H5(ONO2)3君はいくつかの袋を買いたいですが、3人に配るときにまんじゅうのあまりを出したくないです。
そのように買えるとき、まんじゅうの個数の最大値を求めてください。
また、できない場合は−1を出力してください。

-----問題ここまで----- */
/* -----解説等-----

3の余剰で考えればよくて、全ての総和の余剰が0ならそれが答え、
1,2のときはそれぞれ二通りの取り除き方があるのでそれを行えばよい。

----解説ここまで---- */

ll N;
int a[100005];
ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	vector<int>v[3];
	ll sum = 0;
	cin >> N;
	FOR(i, 0, N) {
		cin >> a[i];
		v[a[i] % 3].push_back(a[i]);
		sum += a[i];
	}
	FOR(i, 0, 3)
		sort(v[i].begin(), v[i].end());

	if (sum % 3 == 0) {
		cout << sum << endl;
		return 0;
	}
	else if (sum % 3 == 1) {
		int s = INF;
		int t = INF;
		if (v[1].size() >= 1) {
			s = v[1][0];
		}
		if (v[2].size() >= 2) {
			t = v[2][0] + v[2][1];
		}
		if (s != INF or t != INF) {
			ans = max(sum - t, sum - s);
			if (ans != 0) {
				cout << ans << endl;
				return 0;
			}
		}
	}
	else {
		int s = INF;
		int t = INF;
		if (v[2].size() >= 1) {
			s = v[2][0];
		}
		if (v[1].size() >= 2) {
			t = v[1][0] + v[1][1];
		}
		if (s != INF or t != INF) {
			ans = max(sum - t, sum - s);
			if (ans != 0) {
				cout << ans << endl;
				return 0;
			}
		}
	}

	cout << -1 << endl;


	return 0;
}
