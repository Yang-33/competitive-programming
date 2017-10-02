#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define debug(x) cout << #x << ": " << x << endl
#define ALL(x) (x).begin(),(x).end()

const int INF = 1e9;
const ll LINF = 1e16;

/* -----  2017/10/02  Problem: ICPC国内2015 B / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1601  ----- */
/* ------問題------

任意の文字列からの575が存在するかの判定

-----問題ここまで----- */
/* -----解説等-----

与えられた文字列の中に、57577にできるものがるかを判定する。
ただしそれらの文字列は連続している必要がある。文字列の数が少ないので、インデックスをずらしていって
価が出てきたところで答えとすればよい。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	while (1) {
		int N;
		cin >> N;
		if (N == 0)break;
		string S[50];
		int s[50];
		FOR(i, 0, 50)s[i] = 0;
		FOR(i, 0, N) {
			cin >> S[i];
			s[i] = (int)S[i].size();
		}

		int a[5];
		FOR(i, 0, 5)a[i] = 0;
		int a57577[5] = { 5,7,5,7,7 };
		int ans = 1000000;
		FOR(id, 0, N) {
			int ix = 0;

			FOR(i, id, N) {
				a[ix] += s[i];
				if (a[ix] == a57577[ix]) {
					ix++;
					if (ix == 5) { ans = min(ans,id); break; }
				}
				else if (a[ix] > a57577[ix]) {
					ix = 0;
					FOR(i, 0, 5)a[i] = 0;
					break;
				}
			}
		}
		cout << ans + 1 << endl;
	}

	return 0;
}
