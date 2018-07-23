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

/* -----  2018/07/23  Problem: AOJ 0200 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0200  ----- */
/* ------問題------

太郎君は夏休みに電車で長旅をする計画を立てています。しかし高校生の身である太郎君が一ヵ月しかない夏休みで可能な限り遠くに旅をするには、出来るだけ安い行き方と出来るだけ早い行き方をそれぞれ見つけなければうまく計画が立てられません。太郎君が素敵な旅を満喫できるように、太郎君の計画の助けになるプログラムを作ってあげましょう。
線路の情報、駅の数を入力とし、問い合わせに応じて、最小金額または最短時間を出力するプログラムを作成してください。

-----問題ここまで----- */
/* -----解説等-----

WF

----解説ここまで---- */

int main() {

	int N, M; ;
	while (cin >>M>>N,N) {

		VVI dist(N, VI(N, INF));
		VVI sp(N, VI(N, INF));
		FOR(i, 0, N)dist[i][i] = 0;
		FOR(i, 0, M) {
			int a, b, c, d;
			scanf("%d%d%d%d,", &a, &b, &c, &d);
			a--, b--;
			dist[a][b] = dist[b][a] = min(dist[a][b], c);
			sp[a][b] = sp[b][a] = min(sp[a][b], d);
		}
		FOR(k, 0, N)FOR(i, 0, N)FOR(j, 0, N)dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		FOR(k, 0, N)FOR(i, 0, N)FOR(j, 0, N)sp[i][j] = min(sp[i][j], sp[i][k] + sp[k][j]);
		int Q;
		cin >> Q;
		LL ans;
		FOR(i, 0, Q) {
			int a, b, q; cin >> a >> b >> q;
			a -- , b--;
			if (!q)ans = dist[a][b];
			else ans = sp[a][b];
			cout << ans << "\n";
		}
	}
	return 0;
}
