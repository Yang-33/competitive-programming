#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/08/02  Problem: hourrank29 A / Link: https://www.hackerrank.com/hourrank-29  ----- */
/* ------問題------

CHESS盤の判定

-----問題ここまで----- */
/* -----解説等-----

する

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	FOR(_, 0, T) {

		int N; cin >> N;
		VVI a(N, VI(N));
		FOR(i, 0, N) {
			FOR(j, 0, N) {
				cin >> a[i][j];
			}
		}
		int ok = 1;
		FOR(i, 0, N) {
			FOR(j, 0, N) {
				FOR(k, 0, 4) {
					int ny = i + DY[k];
					int nx = j + DX[k];
					if (0 <= ny&&ny < N && 0 <= nx&&nx < N) {
						ok &= (a[i][j] != a[ny][nx]);
					}
				}
			}
		}
		cout << (ok ? "Yes" : "No") << endl;
	}

	return 0;
}
