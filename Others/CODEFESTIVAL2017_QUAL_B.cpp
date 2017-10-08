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

/* -----  2017/10/08  Problem: codefestival2017_qual B  / Link: http://code-festival-2017-qualb.contest.atcoder.jp/tasks/code_festival_2017_qualb_b  ----- */
/* ------問題------

りんごさんは CODEFESTIVAL の予選の問題セットを組もうとしています。

りんごさんは N 個の問題案を持っており、i 個目の問題案の難易度は Di です。

予選の問題セットには M 問の問題が必要で、i 問目の問題に使う問題案の難易度はちょうど Ti でなければなりません。ただし、1 つの問題案を複数の問題に使うことはできません。

りんごさんが新しく問題案を作ることなく予選の問題セットを完成させることができるかを判定して下さい。

-----問題ここまで----- */
/* -----解説等-----

数字がでかいのでmapで管理すればよい。

----解説ここまで---- */

ll N,M;

ll ans = 0LL;
ll d[200002];
ll t[200002];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	map<ll, ll>ma;
	cin >> N;
	FOR(i, 0, N) {
		cin >> d[i];
		ma[d[i]]++;
	}
	cin >> M;
	bool f = 1;
	FOR(i, 0, M) {
		cin >> t[i];
		if (ma[t[i]] >= 1) {
			ma[t[i]]--;
		}
		else {
			f = 0;
		}
	}


	if (f) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}
