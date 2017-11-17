#include "bits/stdc++.h"
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
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

/* -----  2017/11/15  Problem: AOJ 2162 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2162  ----- */
/* ------問題------

周期dの列Ad(i)が複数与えられる。(d<=24)
各列の初期値はi=tのときである。
周期列を前から見ていったときの、和の最大値は？

-----問題ここまで----- */
/* -----解説等-----

全周期をみたいがLCM(1 to 24)は5*10^9overなのできびしい。
3,7だけ見ると3maxと7maxをとって足しても答えになる。これは互いに素の時のみできる
つまり2,4は無理
先の考察から互いに素なものは別でやっていい。
今回はmaxが24なので13以上の素数を取り除くと、これらのLDMは 55440でこっちは全探索をしてあとは
独立にやってもよいから適当にやる。

----解説ここまで---- */

LL N;

LL ans = 0LL;
bool doku(int a) { return (a == 13 || a == 17 || a == 19 || a == 23); }

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	map<int, int>m;
	while (cin >> N, N) {
		VL a(55440 + 1, 0);
		VVL b(24 + 1, VL(24, 0));
		FOR(_, 0, N) {
			int d; cin >> d;
			int t; cin >> t;
			VL in(d);
			FOR(j, 0, d) {
				cin >> in[j];
				b[d][(j - t + d) % d] += in[j];
			}
		}
		ans = 0;
		FOR(i, 1, 24 + 1) {
			if (doku(i)) {
				ans += *max_element(ALL(b[i]));
			}
			else {
				FOR(j, 0, 55440 + 1) {
					a[j] += b[i][j%i];
				}
			}
		}
		ans += *max_element(ALL(a));
		cout << ans << endl;
	}
	return 0;

}
