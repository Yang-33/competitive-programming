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

/* -----  2018/05/05  Problem: GCJ2018_R1_C B / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

頻度の小さいものから売っていくと通った。
(頻度の大きいものを売っても通ったみたいな情報をみたので何をしても通りそう)

----解説ここまで---- */

void solve() {
	int N; cin >> N;
	VI orders(N, 0);
	VI sold(N, 0);
	FOR(c, 0, N) {
		int D; cin >> D;
		VI cw(D);
		FOR(d, 0, D) {
			cin >> cw[d];
		}
		int id = -1;
		int val = INF;
		FOR(d, 0, D) {
			orders[cw[d]]++;
		}
		FOR(d, 0, D) {
			if (sold[cw[d]] == 0) {
				if (val > orders[cw[d]]) {
					val = orders[cw[d]];
					id = cw[d];
				}
			}
		}
		if (id >= 0) {
			sold[id] = 1;
			cout << id << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
}

int main() {
	/*cin.tie(0);
	ios_base::sync_with_stdio(false);*/

	int Case; cin >> Case;
	FOR(ccaassee, 0, Case) {
		solve();
		//cout << "Case #" << ccaassee + 1 << ": " << solve() << "\n";
	}

	return 0;
}
