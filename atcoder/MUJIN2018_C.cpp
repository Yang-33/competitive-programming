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

/* -----  2018/08/04  Problem: mujin2018 C / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M; cin >> N >> M;
	VS vs(N);
	FOR(i, 0, N) {
		cin >> vs[i];
	}
	int H = N, W = M;

	VVI ri(H, VI(W, 0)); // このマスを含む右側に何点行けるか
	VVI le(H, VI(W, 0)); // このマスを含む左側に何点行けるか
	VVI up(H, VI(W, 0)); // このマスを含む上側に何点行けるか
	VVI dw(H, VI(W, 0)); // このマスを含む下側に何点行けるか

	// H*W*4
	{

		FOR(i, 0, H) { // ri 
			int cnt = 0;
			FORR(j, W - 1, 0 - 1) {
				if (vs[i][j] == '.') {
					cnt++;
					ri[i][j] = cnt;
				}

				else cnt = 0;
			}
		}
		FOR(j, 0, W) { //dw 
			int cnt = 0;
			FORR(i, H - 1, 0 - 1) {
				if (vs[i][j] == '.') {
					cnt++;
					dw[i][j] = cnt;
				}
				else cnt = 0;
			}
		}
		FOR(i, 0, H) {// le
			int cnt = 0;
			FOR(j, 0, W) {
				if (vs[i][j] == '.') {
					cnt++;
					le[i][j] = cnt;
				}
				else cnt = 0;
			}
		}
		FOR(j, 0, W) { // up
			int cnt = 0;
			FOR(i, 0, H) {
				if (vs[i][j] == '.') {
					cnt++;
					up[i][j] = cnt;
				}
				else cnt = 0;
			}
		}
	}

	LL ans = 0;
	{
		FOR(i, 0, H) {
			FOR(j, 0, W) {
				if (vs[i][j] == '.') {
					LL fromL = le[i][j] - 1;
					LL toD = dw[i][j] - 1;
					ans += fromL*toD;

					LL fromU = up[i][j] - 1;
					LL toL = le[i][j] - 1;
					ans += fromU*toL;
					
					LL fromR = ri[i][j] - 1;
					LL toU = up[i][j] - 1;
					ans += fromR*toU;

					LL fromD = dw[i][j] - 1;
					LL toR = ri[i][j] - 1;
					ans += fromD*toR;
				}
			}
		}



	}

	cout << ans << "\n";

	return 0;
}
