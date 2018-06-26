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

/* -----  2018/06/26  Problem: AOJ 2371 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2371  ----- */
/* ------問題------

うなぎは電車に乗るのが好きである. いま，うなぎは駅 A から駅 B へ電車を使って行こうとしている. うなぎは急いでいるので, 最短時間の経路を選ぶことにした. ただし，うなぎは乗り換えが苦手なので, 最短時間の経路が複数ある場合は最も乗り換え回数の少ない経路を選ぶことにした.
N 本の路線がある. i 本目の路線は ai 個の駅を通っている. i 本目の路線の通る駅名は通る順に si,0,...,si,ai−1 であり, 駅間の所要時間は ti,0,...,ti,ai−2 である. 電車は路線上を上下方向に走っており, 入力で与えられた逆順に乗ることもできる. 複数の路線の同じ駅名は同じ駅を表しており，乗り換えをすることが出来る. 乗り換えには駅や路線によらず T 分かかる.
一本の路線が同じ駅を複数回通ることもある．もし同じ路線，同じ駅の，路線内で異なる位置の駅に移動したい場合は乗り換えをする必要がある. たとえば, C - D - E - F - D - G という路線を使って C から G まで行く場合, 始点から終点まで一本の電車で行くことも，D 駅で乗り換えて C - D, D - G と乗ることもできる.
うなぎが駅 A から駅 B へ行くのにかかる時間と乗り換え回数を求めよ. 電車はとても頻繁に来るので待ち時間は無視してよい.

-----問題ここまで----- */
/* -----解説等-----

最短路上では最も短くあることと乗り換え回数は区別されず常に最小を取れば良い。
(区別する必要はない)

逆走
- してください
同じ路線の乗り換え
- 乗換駅の頂点を作れば良い。
違う路線の乗り換え
- 一緒

コストは上りにT,下りに0とすれば良い。
答えからT,-1をする(怪しい…)

----解説ここまで---- */
using tp = tuple<int, int, int>;

vector<PII> Dijkstra(vector<vector<tp>>& G, int s) {
	vector<PII> dist(SZ(G), PII(INF, INF));
	dist[s] = PII(0, 0);
	priority_queue<tp, vector<tp>, greater<tp>> que;
	que.push(tp(0LL, 0, s));

	while (!que.empty()) {
		int d, k, v;
		tie(d, k, v) = que.top(); que.pop();

		if (PII(d, k) > dist[v]) continue;

		FOR(i, 0, (int)G[v].size()) {
			int nv, cost, kp;
			tie(nv, cost, kp) = G[v][i];
			PII nstate = PII(dist[v].first + cost, dist[v].second + kp);
			if (dist[nv] > nstate) {
				dist[nv] = nstate;
				que.push(tp(dist[nv].first, nstate.second, nv));
			}
		}
	}
	return dist;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, T;
	while (cin >> N >> T) {
		map<string, int>nameMap;
		int nameid = 1;
		string A, B; cin >> A >> B;
		nameMap[A] = nameid++;
		nameMap[B] = nameid++;

		vector<vector<tp>>G(200005);
		int SH = 100003;
		int Vid = 0;
		FOR(hu, 0, N) {
			int n; cin >> n;
			VI s(n), t(n);
			FOR(i, 0, n) {
				string str;
				cin >> str;
				if (!nameMap.count(str))nameMap[str] = nameid++;
				s[i] = nameMap[str];
			}
			FOR(i, 0, n - 1) {
				cin >> t[i];
			}

			FOR(i, 0, n - 1) {
				G[Vid + i].push_back(tp(Vid + i + 1, t[i], 0));
				G[Vid + i + 1].push_back(tp(Vid + i, t[i], 0));
			}
			FOR(i, 0, n) {
				G[Vid + i].push_back(tp(SH + s[i], T, 1));
				G[SH + s[i]].push_back(tp(Vid + i, 0, 0));
			}
			Vid += n;
		}



		auto dist = Dijkstra(G, nameMap[A] + SH);
		// dijkstra nameMap[A] to nameMap[B]
		if (dist[nameMap[B] + SH].first == INF) {
			cout << -1 << endl;
		}
		else {
			cout << dist[nameMap[B] + SH].first - T << " " << dist[nameMap[B] + SH].second - 1 << endl;
		}
	}
	return 0;
}
