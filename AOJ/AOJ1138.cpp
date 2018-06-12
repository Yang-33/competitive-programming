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

/* -----  2018/06/12  Problem: AOJ 1138 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1138  ----- */
/* ------問題------

昔，昔のことである． 一人の旅人がいた． 彼は，馬車（駅馬車）を使っての旅行を計画している． 出発地と目的地は決まっているのだが，ルートが決まらなくて困っている． 彼のためにルートを決定するプログラムを書くことがあなたの仕事である．
この国には複数の都市があり，それらの間を結ぶ道路網が整備されている． 道路で直結されている二つの都市の間は，馬車で移動することができる． 馬車に乗るには，馬車券が必要である． それぞれの馬車券には，馬の頭数が指定されている． 当然ながら，頭数の多い馬車ほど速い．
旅人は，出発時に何枚かの馬車券を持っている． 道路網と手持ちの馬車券に関する情報から， どのようなルートを選べば最も早く目的地に着けるかを求めたい． この際，馬車券をどう使えばよいかも考える必要がある．
次のような条件を仮定する．
1台の馬車で移動できるのは，1区間（道路で直結された都市間）だけである． すなわち，都市に到着するたびに馬車を乗り換えなければならない．
1区間に使える馬車券は1枚だけである．
1枚の馬車券は一度しか使えない．
都市間の所要時間は，距離を頭数で割った値である．
乗り換えに要する時間は無視する．

-----問題ここまで----- */
/* -----解説等-----

DAGなのでDPできる。
最短路でもできる。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int B, N, E, S, T;
	while (cin >> B >> N >> E >> S >> T, N) {
		vector<double> speed(B);
		FOR(i, 0, B) {
			cin >> speed[i];
		}
		VVI G(N, VI(N, -1));
		FOR(i, 0, E) {
			int a, b, c;
			cin >> a >> b >> c;
			a--, b--;
			G[a][b] = G[b][a] = c;
		}
		S--, T--;
		vector<vector<double>>dp(1 << B, vector<double>(N,INF));
		dp[0][S] = 0;
		FOR(state, 0, 1 << B) {
			FOR(v, 0, N) {
				FOR(b, 0, B) {
					if (state & 1 << b)continue;
					FOR(nv, 0, N) {
						if (G[v][nv]>=0) {
							dp[state|1<<b][nv] = min(dp[state|1<<b][nv], dp[state][v] + G[v][nv]/speed[b]);
						}
					}
				}
			}
		}
		double ans = INF;
		FOR(state, 0, 1 << B) {
			ans = min(ans, dp[state][T]);
		}
		if (ans >= INF) {
			cout << "Impossible" << endl;
		}
		else {
			cout << fixed << setprecision(10) << ans << "\n";
		}
	}
	return 0;
}
