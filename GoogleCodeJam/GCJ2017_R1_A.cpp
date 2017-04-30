#include "bits/stdc++.h"
#include "unordered_set"
using namespace std;

typedef long long ll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl

/* -----  2017/04/30  Problem: GCJ 2017 Round1A A / Link: https://code.google.com/codejam/contest/dashboard?c=5304486#s=p1  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

盤面のケーキに書かれている各子どもたちのイニシャルは、
1度しか登場しないので、与えられた盤面から横に伸ばしきり、
その後縦に伸ばせば必ず伸ばした要素どうしは連結しているのでこれが求めるケーキの分割の盤面になる。
？のみの行も存在するのでそれはあとで上下が埋められているものをそのままコピーした。

----解説ここまで---- */

void solve(int t) {
	int R, C;
	cin >> R >> C;
	vector<string>S(R);
	FOR(i, 0, R) {
		cin >> S[i];
	}
	FOR(i, 0, R) {
		FOR(j, 0, C - 1) {
			if (S[i][j] != '?'&&S[i][j + 1] == '?') {
				S[i][j + 1] = S[i][j];
			}
		}
		FORR(j, C - 1, 0) {
			if (S[i][j] != '?'&&S[i][j - 1] == '?') {
				S[i][j - 1] = S[i][j];
			}
		}
	}

	FOR(i, 0, R - 1) {
		if (S[i][0] != '?'&&S[i + 1][0] == '?')S[i + 1] = S[i];
	}
	FORR(i, R - 1, 0) {
		if (S[i][0] != '?'&&S[i - 1][0] == '?')S[i - 1] = S[i];
	}



	cout << "Case #" << t + 1 << ":" << endl;
	FOR(i, 0, R) {
		cout << S[i] << endl;
	}
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	FOR(i, 0, t) {
		solve(i);
	}

	return 0;
}
