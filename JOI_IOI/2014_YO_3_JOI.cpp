#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)

/* -----  2017/04/24  Problem: JOI予選 2014 3  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0610  ----- */
/* ------問題------

みて

-----問題ここまで----- */
/* -----解説等-----

後ろをたどってみていけばよい。
配列外アクセスの無いようにしていけばＯ(HWW)で余裕で間に合う。

----解説ここまで---- */



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	ll H, W;
	ll ans = 0LL;
	cin >> H >> W;
	vector<string>table(100);
	FOR(i, 0, H) {
		cin >> table[i];
	}

	FOR(i, 0, H) {
		FOR(j, 0, W) {
			int aa = 0;
			if (table[i][j] == 'c') {
				cout << aa;
				if (j != W - 1) {
					cout << " ";
				}
			}
			else {
				aa++;
				bool f = false;
				while (j - aa >= 0) {
					if (table[i][j - aa] == 'c') {
						f = true;
						break;
					}

					aa++;
				}
				if (f) {
					cout << aa;
					if (j != W - 1) {
						cout << " ";
					}
				}
				else {
					cout << -1;
					if (j != W - 1) {
						cout << " ";
					}
				}
			}


		}
		cout << endl;
	}

	return 0;
}
