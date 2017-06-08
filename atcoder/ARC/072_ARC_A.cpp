#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
const ll LINF = 1e16;

/* -----  2017/04/22  Problem: ARC 072 A / Link: http://arc072.contest.atcoder.jp/tasks/arc072_a  ----- */
/* ------問題------

みて

-----問題ここまで----- */
/* -----解説等-----

最初を＋にするかーにするかを全部試す。

----解説ここまで---- */

ll N;

ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll a[100010];
	cin >> N;
	FOR(i, 0, N) {
		cin >> a[i];
	}
	ans = LINF;
	ll cnt = 0;
	ll sum = 0;
	FOR(i, 0, N) {
		if (i == 0) {
			sum += a[i];
			if (sum < 0) {
				cnt = (-sum + 1);
				sum = 1;
			}
			else if (sum == 0) {
				cnt++;
				sum = 1;
			}
			continue;
		}
		if (sum > 0) {
			sum += a[i];
			if (sum >= 0) {
				cnt += (sum + 1);
				sum = -1;
			}
		}
		else {
			sum += a[i];
			if (sum <= 0) {
				cnt += (-sum + 1);
				sum = 1;
			}
		}
	}
	ans = min(ans, cnt);
	sum = 0;
	cnt = 0;
	FOR(i, 0, N) {
		if (i == 0) {
			sum += a[i];
			if (sum > 0) {
				cnt = (sum + 1);
				sum = -1;
			}
			else if (sum == 0) {
				cnt++;
				sum = -1;
			}
			continue;
		}
		if (sum > 0) {
			sum += a[i];
			if (sum >= 0) {
				cnt += (sum + 1);
				sum = -1;
			}
		}
		else {
			sum += a[i];
			if (sum <= 0) {
				cnt += (-sum + 1);
				sum = 1;
			}
		}
	}

	ans = min(ans, cnt);

	return 0;
}
