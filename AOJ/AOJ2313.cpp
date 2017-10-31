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

/* -----  2017/10/30  Problem: NU23 H / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2313  ----- */
/* ------問題------

ハコの魔女 H.N.ELLY はとある動画サイトの熱狂的なファンである．ハコの魔女の強さはその時々のその動画サイトからの転送速度に応じて変化するのではないかと美樹さやかは考えた．
そこで動画サイトからハコの魔女の持つコンピュータまでの過去の転送速度 (=単位時間あたりのデータの転送量) を調べたい．

初期のインターネットのネットワークの構造とそれ以降のネットワークの構造の変化を表すクエリが与えられるので，
各変化について変化した直後の動画サイトからハコの魔女の持つコンピュータまでの転送速度を求めよ．

インターネットは複数の転送装置からなるものと見なし，各々をつなぐ回線は双方向に情報を送ることができ，その転送速度の最大は 1 であるとする．
また，ネットワークは常に動画サイトからハコの魔女へ送られるデータの転送速度を最大化するように運ぶものとする．

-----問題ここまで----- */
/* -----解説等-----

再計算を行えば無駄がないので、各辺についておしもどせばよい。
a->b,b->aで押し戻して流せればそのまま、そうでないならans--である。
類題：acpc2017 day1 attackなんちゃら

----解説ここまで---- */



/* 最大流  Fordflukarson Ｏ(FE)  */
#define max_flow_MAX 1005

struct edge {
	int from, to, cap, rev;
	edge() {}
	edge(int from, int to, int cap, int rev) :from(from), to(to), cap(cap), rev(rev) {}
};
vector<edge> G[max_flow_MAX];
bool used[max_flow_MAX];

void add_edge(int from, int to, int cap) {
	G[from].emplace_back(edge(from, to, cap, (int)G[to].size()));
	//G[to].emplace_back(edge(to, from, 0, (int)G[from].size() - 1));
	G[to].emplace_back(edge(to, from, cap, (int)G[from].size() - 1));
}

int dfs(int v, int t, int f) {
	if (v == t)return f;
	used[v] = true;
	FOR(i, 0, (int)G[v].size()) {
		edge &e = G[v][i];
		if (!used[e.to] && e.cap > 0) {
			int d = dfs(e.to, t, min(f, e.cap));
			if (d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s, int t) {// O(FE)
	const int INF = INT_MAX;
	int flow = 0;
	for (;;) {
		memset(used, 0, sizeof(used));
		int f = dfs(s, t, INF);
		if (f == 0)return flow;
		flow += f;
	}
	//return -1;
	return 0;
}
int check(int s, int t) { // F=1, E -> O(E)
	memset(used, 0, sizeof(used));
	return dfs(s, t, 1);
}

LL N, M, Q;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> Q;
	VVI lk(N + 1, VI(N + 1, 0));
	FOR(i, 0, M) {
		int s, t; cin >> s >> t;
		if (lk[s][t] == 0)add_edge(s, t, 1);
		lk[s][t] = lk[t][s] = 1;
	}
	ans = max_flow(1, N);
	using Tp = tuple<int, int, int>;
	vector<Tp>in;
	FOR(_, 0, Q) {
		int m, a, b;
		cin >> m >> a >> b;
		if (lk[a][b] == 0)add_edge(a, b, 0), lk[a][b] = lk[b][a] = 1;
		in.push_back(Tp(m, a, b));
	}

	FOR(_, 0, Q) {
		int m, a, b;
		tie(m, a, b) = in[_];
		if (m == 1) {// add 
			FOR(i, 0, SZ(G[a])) {
				if (G[a][i].to == b) {
					edge &e = G[a][i];
					e.cap = G[e.to][e.rev].cap = 1;
					ans += check(1, N);
					break;
				}
			}
		}
		else {// delete
			FOR(i, 0, SZ(G[a])) {
				if (G[a][i].to == b) {
					edge &e = G[a][i];
					int capcap = e.cap;
					e.cap = G[e.to][e.rev].cap = 0;
					//debug(capcap);
					if (capcap == 1)break;
					if (capcap == 2) {
						if (check(b, a) == 0) {
							check(b, 1);
							check(N, a);
						}
						else break;//流せれば減らない
					}
					else if (capcap == 0) {
						if (check(a, b) == 0) {
							check(a, 1);
							check(N, b);
						}
						else break;//流せれば減らない
					}
					ans--;
					break;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
