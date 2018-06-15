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

/* -----  2018/06/15  Problem: AOJ 2021 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2021  ----- */
/* ------問題------

ある貧乏な国のおてんばで勇敢なお姫様が，政略結婚のため別の国に嫁ぐことになった．ところが，お姫様を亡き者としようとしている悪漢に嫁ぎ先への道中で襲われお姫様が大けがをしてしまい，近くの病院に搬送された．ところが，悪漢はお姫様は確実に亡き者とするため特殊な毒を使っていた．そのため，お姫様を助けるには本国から特別な薬と冷凍された肉親の血液を大急ぎで運ばなければならなくなった．
この血液は冷凍状態で輸送されるのだが，鮮度を保つため，前回の冷凍から最大 M 分以内に血液冷凍施設で再冷凍しなければならない．しかし，冷凍施設が設置されている場所は数カ所しかない．
血液は，十分に冷凍した状態から，再冷凍なしで M 分の間無事である．再冷凍しなくてすむ残り時間が S 分のときに，T 分間冷凍しないで輸送した場合，再冷凍しなくてすむ残り時間は S - T 分となる．再冷凍しなくてすむ残り時間は，再冷凍することにより，最大 M 分まで回復する．血液の再冷凍にかかる時間は，どれだけ冷凍するかに依存する．血液を冷凍施設で，1分冷凍するごとに再冷凍しなくてすむ残り時間は1分回復する．
本国の首都を出発する時点の，血液を再冷凍しなくてすむ残り時間はM分である．
お姫様の従者であるあなたは，大切な主君の命を救うため，本国の首都からお姫様が搬送された病院まで血液の鮮度を保ったまま輸送するための経路を計算しなければならない．そう，あなたの使命は，本国の首都からその病院への最短経路を割り出し，その最短時間を求めることである．

-----問題ここまで----- */
/* -----解説等-----

特に工夫もなく拡張ダイクストラやるだけ。

----解説ここまで---- */
VVL Dijkstra(const vector<vector<PII>>& G, int s, int M, const VI & posRe) {
	VVL dist(SZ(G), VL(M + 1, LINF));
	dist[s][M] = 0;//のこりM
	using tp = tuple<LL, LL, LL>;
	priority_queue<tp, vector<tp>, greater<tp>> que;
	que.push(tp(0LL, s, M));

	while (!que.empty()) {
		LL d, v, m;
		tie(d, v, m) = que.top(); que.pop();
		if (d > dist[v][m]) continue;

		FOR(i, 0, (int)G[v].size()) {
			int nv = G[v][i].first;
			int cost = G[v][i].second;
			if (m - cost >= 0) {
				if (dist[nv][m - cost] > dist[v][m] + G[v][i].second) {
					dist[nv][m - cost] = dist[v][m] + G[v][i].second;
					que.push(tp(dist[nv][m - cost], nv, m - cost));
				}

			}
			if (posRe[v]) { // mm>=1だけ回復してから次に行くお
				FOR(mm, 1, M - m + 1) {
					int newm = m - cost + mm;
					if (newm >= 0) {
						if (dist[nv][newm] > dist[v][m] + cost + mm) {
							dist[nv][newm] = dist[v][m] + cost + mm;
							que.push(tp(dist[nv][newm], nv, newm));
						}

					}
				}
			}
		}
	}
	return dist;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M, L, E, S, T;
	while (cin >> N >> M >> L >> E >> S >> T, N) {
		// L
		VI posRe(N, 0);
		FOR(i, 0, L) {
			int pos; cin >> pos;
			posRe[pos] = 1;
		}
		// E 
		vector<vector<PII>>G(N);
		FOR(i, 0, E) {
			int a, b, c;
			cin >> a >> b >> c;
			G[a].push_back(PII(b, c));
			G[b].push_back(PII(a, c));
		}
		VVL dist = Dijkstra(G, S, M, posRe);
		LL ans = LINF;
		FOR(i, 0, M + 1) {
			ans = min(ans, dist[T][i]);
		}
		if (ans == LINF)cout << "Help!" << endl;
		else cout << ans << endl;
	}

	return 0;
}
