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

/* -----  2018/05/19  Problem: GCJ2018_R2 B / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

ｄｐ

----解説ここまで---- */


int solve(int A,int B) {

	/*int A, B;
	cin >> A >> B;*/
	int dp[501][501];
	fill(*dp, *dp + 501 * 501, 0);
	vector<PII> nap;
	FOR(a, 0, (A + 10) / 2) {
		FOR(b, 0, (B + 10) / 2) {
			if (a + b&&a <= A&&b <= B) {
				nap.push_back(PII(a, b));
				//cout << a << "," << b << endl;
			}
		}
	}
	dp[0][0] = 1;
	FOR(i, 0, SZ(nap)) {
		FORR(a,A,nap[i].first-1){
//		FOR(a, nap[i].first, A + 1) {
			FORR(b,B,nap[i].second-1){
			//FOR(b, nap[i].second, B + 1) {
				if (dp[a - nap[i].first][b-nap[i].second]) {
					dp[a][b] = max(dp[a][b], dp[a - nap[i].first][b-nap[i].second] + 1);
				}
			}
		}
	}
	int ans = 0;
	FOR(a, 0, A + 1) {
		FOR(b, 0, B + 1) {
			ans = max(ans, dp[a][b]);
			//cout << "dp[" << a << "][" << b << "]:=" << dp[a][b] << endl;
		}
	}
	return ans - 1;
	//cout << ans - 1 << endl;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cout << "int dp[501][501] = {" << endl;
	int x;
	cin >> x;
	cout << "DELETE!!!!<<thisis" << x << endl;
	FOR(a, x, x+50) {
		cout << "{";
		FOR(b, 0, 501) {
			cout << solve(a, b);
			if (b != 500)cout << ",";
			else cout << "}," << endl;
		}
		debug(a);
	}
	cout << "}" << endl;
	/*int T; cin >> T;
	FOR(cx, 1, T + 1) {
		cout << "Case #" << cx << ": ";
		solve();
	}*/

	return 0;
}
