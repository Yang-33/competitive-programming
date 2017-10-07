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

/* -----  2017/10/07  Problem: DDCC2017_qual A  / Link: http://ddcc2017-qual.contest.atcoder.jp/tasks/ddcc2017_qual_a  ----- */
/* ------問題------

長さ 4 の文字列がDDCC型文字列であるのは、文字列の 1 文字目と 2 文字目が等しく、 2 文字目と 3 文字目が異なり、 3 文字目と 4 文字目が等しいときです。
4 文字の文字列 S が与えられるので、DDCC型文字列ならば Yes 、そうでなければ No を出力してください。

-----問題ここまで----- */
/* -----解説等-----

.

----解説ここまで---- */

ll N;
string S;
ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> S;
	if ((S[0] == S[1]) && (S[2] == S[3]) && (S[1] != S[2])) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}



	return 0;
}
