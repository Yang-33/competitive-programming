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

/* -----  2018/10/11  Problem: EDU052 B / Link: __CONTEST_URL__  ----- */
/* ------問題------

N頂点,M辺のグラフがある時、孤立点の最小値と最大値は?

-----問題ここまで----- */
/* -----解説等-----

最小化するときは、2頂点を1辺でつないでいけば良い。
最大化するときは、完全グラフを作れば良い。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	LL N, M; cin >> N >> M;
	LL Min, Max;
	{ // Min
		Min = max(0LL, N - 2 * M);
	}
	{ // Max
		Max = N;
		FOR(v, 0, N + 1) {
			LL subs = (LL)v*(v - 1) / 2;
			if (subs >= M) {
				Max = N - v;
				break;
			}
		}

	}
	cout << Min << " " << Max << endl;

	return 0;
}
