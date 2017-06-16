#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)

/* -----  2017/04/24  Problem: JOI予選 2014 2  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0609  ----- */
/* ------問題------

みて

-----問題ここまで----- */
/* -----解説等-----

いわれたとおりにやっていく。
与えられた問題サイズと同等な時間で解ける。

----解説ここまで---- */



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	ll N, M;
	ll a[105];
	ll b[105][105];
	ll ans[105];
	FOR(i, 0, 105)ans[i] = 0;

	cin >> N >> M;

	FOR(i, 0, M) {
		cin >> a[i];
	}
	FOR(i, 0, M) {
		FOR(j, 0, N) {
			cin >> b[i][j];
		}
	}

	FOR(i, 0, M) {
		int tar = a[i];
		int haz = 0;
		FOR(j, 0, N) {
			if (tar == b[i][j]) {
				ans[j + 1]++;
			}
			else haz++;
		}
		ans[tar] += haz;

	}


	FOR(i, 1, N + 1) {
		cout << ans[i] << endl;
	}
	return 0;
}
