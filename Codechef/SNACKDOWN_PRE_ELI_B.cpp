#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << " "
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/05/28  Problem:  / Link:   ----- */
/* ------問題------

It is snack


-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

ll N;
ll ans = 0LL;
char s[2][600];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int _T; cin >> _T;
	FOR(_t, 0, _T) {
		bool f = 1;
		int w; cin >> w;
		string S[2];
		FOR(i, 0, 2)cin >> S[i];
		
		FOR(i, 0, 2)FOR(j, 0, 600)s[i][j] = 0;
		FOR(i, 0, 2)FOR(j, 0, S[i].size())s[i][j] = S[i][j];

		int sum = 0;
		FOR(i, 0, 2)FOR(j, 0, S[i].size())if (s[i][j] == '#')sum++;

		int pos1 = INF;
		int pos2 = INF;
		FORR(i, S[0].size() - 1, -1)if (s[0][i] == '#')pos1 = i;
		FORR(i, S[1].size() - 1, -1)if (s[1][i] == '#')pos2 = i;
		int cnt1 = 0;
		int cnt2 = 0;
		if (pos1 == INF)cnt1 = INF;
		if (pos2 == INF)cnt2 = INF;

		//debug(pos1); debug(pos2) << endl;
		/* 片方でもいっしょになればOK  */
		/* pos1から */
		int bef;//0:=上  1:=下

		if (pos1 != INF) {
			cnt1++;
			if (s[1][pos1] == '#')bef = 1, cnt1++;
			else bef = 0;

			FOR(i, pos1 + 1, S[0].size()) {
				if (s[bef][i] == '#') {
					cnt1++;
					if (s[!bef][i] == '#') {
						cnt1++; bef = !bef;
					}
				}
				else break;
			}
		}
		/* pos2から */
		if (pos2 != INF) {
			cnt2++;
			if (s[0][pos2] == '#')bef = 0, cnt2++;
			else bef = 1;
			FOR(i, pos2 + 1, S[1].size()) {
				if (s[bef][i] == '#') {
					cnt2++;
					if (s[!bef][i] == '#') {
						cnt2++; bef = !bef;
					}
				}
				else break;
			}
		}

//		debug(cnt1); debug(cnt2); debug(sum) << endl;
		if (cnt1 == sum || cnt2 == sum)f = 1;
		else f = 0;




		if (f)
			cout << "yes" << endl;
		else
			cout << "no" << endl;

	}
	return 0;
}
