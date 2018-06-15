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

/* -----  2018/06/15  Problem: AOJ 2672 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2672  ----- */
/* ------問題------

あなたの担当する配達地域として無向グラフを考える．
n頂点からなる無向グラフを考えたとき，それぞれの頂点には1からnの番号が付けられている．
落とした郵便物の数と落ちている頂点，それぞれの郵便物の配達先の頂点が与えられたとき，
すべての郵便物を回収して配達先に届ける最短時間を求めよ．
このとき，ある郵便物をその郵便物の配達先に届ける場合に拾っていない他の郵便物が存在しても良い．
また，配達終了時にはどの頂点にいても良いこととする．
ここで，1つの頂点には高々1つの郵便物か高々1つの配達先しかなく，出発する頂点には郵便物も配達先も存在しない．
与えられる無向グラフは単純なグラフ，すなわち自己閉路や多重辺のないグラフである．

-----問題ここまで----- */
/* -----解説等-----

何度もダイクストラをしてまず2*K点間の最短距離を求める。
その後、state={ひろった,届けた}*を2^K個もったbitDPをすればよい

----解説ここまで---- */
using ll = LL;

ll N, M, K, P;
ll ans = 0LL;
using TypeDijk = pair<ll, ll>;

#define DijkV 1003
ll d[DijkV];
vector<PLL>G[DijkV];
void Dijkstra(int s, int t) {
	const int INF = INT_MAX;

	FOR(i, 0, DijkV)d[i] = LLONG_MAX / 10;

	d[s] = 0; 
	priority_queue<TypeDijk, vector<TypeDijk>, greater<TypeDijk>> que; 
	que.push(TypeDijk(0ll, s)); 

	while (!que.empty()) {
		TypeDijk p = que.top(); que.pop(); 
		int v = p.second; 
		ll dist = p.first; 
		if (dist > d[v]) continue;

		FOR(i, 0, G[v].size()) { 
			int nv = G[v][i].first; 
			if (d[nv] > d[v] + G[v][i].second) {
				d[nv] = d[v] + G[v][i].second;
				que.push(TypeDijk(d[nv], nv)); 
			}
		}
	}
}
ll dp[1 << 13][13];
int t[6]; int s[6];
ll dist[13][13];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> K >> P; P--;
	FOR(i, 0, M) {
		int a, b, c; cin >> a >> b >> c;
		a--; b--;
		G[a].push_back(PLL(b, c));
		G[b].push_back(PLL(a, c));
	}

	FOR(i, 0, K) {
		cin >> s[i] >> t[i];
		s[i]--; t[i]--;
	}

	FOR(i, 0, K) {
		Dijkstra(s[i], -1);
		FOR(j, 0, K) {
			dist[2 * i][2 * j] = d[s[j]];
			dist[2 * i][2 * j + 1] = d[t[j]];
		}
		Dijkstra(t[i], -1);
		FOR(j, 0, K) {
			dist[2 * i + 1][2 * j] = d[s[j]];
			dist[2 * i + 1][2 * j + 1] = d[t[j]];
		}
	}

	Dijkstra(P, -1);

	FOR(i, 0, 1 << 13)FOR(j, 0, 13)dp[i][j] = INF;
	FOR(i, 0, K) {
		dp[1 << (2 * i)][2 * i] = d[s[i]];
	}

	FOR(i, 0, (1 << (2 * K))) {
		FOR(j, 0, 2 * K) {
			if (dp[i][j] == INF)continue;
			FOR(k, 0, 2 * K) {
				if (i&(1 << k))continue;
				if ((k % 2 == 1) && ((i&(1 << (k - 1))) == 0))continue;
				dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + dist[j][k]);
			}
		}
	}
	ans = INF;
	FOR(i, 0, K) {
		ans = min(ans, dp[(1 << (2 * K)) - 1][2 * i + 1]);
	}
	if (ans == INF)cout << "Cannot deliver" << endl;
	else cout << ans << endl;

	return 0;
}