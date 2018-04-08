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

/* -----  2018/04/08  Problem: yukicoder 017  / Link: http://yukicoder.me/problems/no/017  ----- */
/* ------問題------

0 からN−1までのN個の地点がある。
地点から地点の移動コストがM個与えられる。
また各地点に滞在コストがある。

0地点からN−1地点にたどり着くまでに、 0地点とN−1地点以外の異なる2つの地点に滞在しなければならない。
滞在する地点は自由に決めて良い。
この条件での移動コストと滞在コストの合計の最小値を求めよ。

都市を通るけど、滞在しないこともできます。

-----問題ここまで----- */
/* -----解説等-----

2点よりも多い点に移動しても滞在するのはダメなので二点をきめると3つの最短路をつなぐことになる。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VI s(N);
	FOR(i, 0, N) {
		cin >> s[i];
	}
	int M; cin >> M;
	VVI d(N, VI(N, INF));
	FOR(i, 0, N)d[i][i] = 0;
	FOR(i, 0, M) {
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = d[b][a] = c;
	}
	FOR(k, 0, N)FOR(i, 0, N)FOR(j, 0, N) {
		d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	}
	ans = INF;
	FOR(i, 1, N - 1) {
		FOR(j, 1, N - 1) {
			if (i != j)
				ans = min(ans, (LL)d[0][i] + d[i][j] + d[j][N - 1] + s[i] + s[j]);
		}
	}
	cout << ans << "\n";

	return 0;
}
