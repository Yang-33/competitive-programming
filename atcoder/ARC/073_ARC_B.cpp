#include <bits/stdc++.h>
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

/* -----  2018/02/23  Problem: 073_arc_b / Link: https://arc073.contest.atcoder.jp/tasks/arc073_b?lang=en  ----- */
/* ------問題------

あなたは N 個の物と、強度 W のバッグを持っています。 i 個目の物は、重さが wi で価値が vi です。
あなたは、物のうちいくつかを選び、バッグに入れます。 ただし、選んだ物の重さの和は W 以下でなくてはいけません。
あなたは、バッグに入れた物の価値の総和を最大化したいです。

-----問題ここまで----- */
/* -----解説等-----

昔はDPを気合で解いていたけど、これはw[0] からの値が4種類しかないのでどれを何個使うかで全探索できる。
dpのときはdp(i,j,k):=i個目まで見てj個選択し,余計な重さがkのときの最大値として、
O(N^3)で解ける。

----解説ここまで---- */

LL N, W;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> W;
	VL w(N), v(N);

	VVL s(4,VL());
	LL baseW;
	FOR(i, 0, N) {
		cin >> w[i] >> v[i];
		if (i == 0)baseW = w[i];
		int id = w[i] - baseW;
		s[id].push_back(v[i]);
	}
	FOR(i, 0, 4)RSORT(s[i]);


	FOR(i, 0, SZ(s[0])+1) {
		FOR(j, 0, SZ(s[1])+1) {
			FOR(k, 0, SZ(s[2])+1) {
				FOR(l, 0, SZ(s[3])+1) {

					LL Vs = 0;
					LL Ws = 0;
					FOR(a, 0, i) {
						Ws += baseW;
						Vs += s[0][a];
					}FOR(a, 0, j) {
						Ws += baseW+1;
						Vs += s[1][a];
					}FOR(a, 0, k) {
						Ws += baseW+2;
						Vs += s[2][a];
					}FOR(a, 0, l) {
						Ws += baseW+3;
						Vs += s[3][a];
					}
					if (W >= Ws) {
						ans = max(ans, Vs);
					}

				}
			}
		}
	}
	cout << ans << "\n";

	return 0;
}
