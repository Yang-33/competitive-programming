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

/* -----  2017/10/02  Problem: CS academy 33 B / Link:  https://csacademy.com/contest/round-33/task/numbers-tournament/ ----- */
/* ------問題------

N人がNこの数字を持っている。
全員と戦う。
二人で共通でもっている値のうち、最小と最大のものをa,bとしたとき、[a,b]に含まれない数の個数がその人の値になる。
その得点で勝てば2、引き分けなら1、負けなら0である。
この得た得点順に人をならべて。

-----問題ここまで----- */
/* -----解説等-----

愚直に実装。

----解説ここまで---- */

ll N;
int point[105];
ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	int a[105][105];
	set<int>s[105];
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			cin >> a[i][j];
			s[i].insert(a[i][j]);
		}
	}


	FOR(i, 0, N) {
		FOR(j, i + 1, N) {

			int m = INF; int M = -INF;

			FOR(k, 0, N) {
				if (s[j].count(a[i][k]) != 0) {
					m = min(m, a[i][k]);
					M = max(M, a[i][k]);
				}
			}

			int cnti = 0;
			FOR(k, 0, N) {
				if (a[i][k]<m || a[i][k]>M)cnti++;
			}
			int cntj = 0;
			FOR(k, 0, N) {
				if (a[j][k]<m || a[j][k]>M)cntj++;
			}
			if (cnti > cntj) {
				point[i] += 2;
			}
			else if (cnti == cntj) {
				point[i]++;
				point[j]++;
			}
			else {
				point[j] += 2;
			}

		}
	}
	pii b[105];
	FOR(i, 0, N) {
		b[i] = pii(-point[i],i);
	}

	sort(b, b + N);


	FOR(i, 0, N) {
		cout << b[i].second+1 << endl;
	}

	return 0;
}
