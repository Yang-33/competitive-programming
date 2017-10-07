#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/05/20  Problem: ARC 074 D / Link: http://arc074.contest.atcoder.jp/tasks/arc074_d  ----- */
/* ------問題------

長方形の池があります。 池は縦 H 行、横 W 列のマス目状に分割されています。 上から i 行目、左から j 列目のマスを (i, j) と表します。
池のいくつかのマスには蓮 (はす) の葉が浮かんでいます。 ある葉 S にはカエルが乗っており、別の葉 T まで移動しようとしています。 マス (i, j) の情報は、文字 aij によって次のように表されます。
. : 葉が浮かんでいないマスである。
o : 葉が浮かんでいるマスである。
S : 葉 S が浮かんでいるマスである。
T : 葉 T が浮かんでいるマスである。
カエルは「今乗っている葉と同じ行または同じ列に浮かんでいる葉へジャンプする」ことを繰り返し行い、葉 T まで移動しようとしています。

すぬけ君の目標は、あらかじめ葉 S, T 以外の葉を何枚か取り除いておくことで、カエルが葉 T まで移動できないようにすることです。 この目標が達成可能か判定し、可能ならば取り除く葉の枚数の最小値を求めてください。

-----問題ここまで----- */
/* -----解説等-----

H*Wの領域に辺を張りたくなるが、それは厳しいので(Dinicなら通るのかもしれないが)
縦の集合と横の集合にわけたフローグラフを考えると、(i,j)はi,jの集合にアクセスできるので、
そこに辺を張ればよい。
題意はは最小カットそのものなので、あとは流せばよい。


----解説ここまで---- */

ll N;

ll ans = 0LL;

struct FordFulkerson {
#define max_flow_MAX 1005

	struct edge {
		int to, cap, rev;
		edge() {}
		edge(int to, int cap, int rev) :to(to), cap(cap), rev(rev) {}
	};
	vector<edge> G[max_flow_MAX];
	bool used[max_flow_MAX];

	void add_edge(int from, int to, int cap) {
		G[from].emplace_back(edge(to, cap, (int)G[to].size()));
		G[to].emplace_back(edge(from, 0, (int)G[from].size() - 1));
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

	int max_flow(int s, int t) {
		const int INF = INT_MAX;
		int flow = 0;
		for (;;) {
			memset(used, 0, sizeof(used));
			int f = dfs(s, t, INF);
			if (f == 0)return flow;
			flow += f;
		}
		return -1;
	}
#undef max_flow_MAX
};

ll W, H;
string s[102];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> H >> W;
	int sx, sy, tx, ty;
	FOR(i, 0, H) {
		cin >> s[i];
		FOR(j, 0, W) {
			if (s[i][j] == 'S')sx = j, sy = i;
			if (s[i][j] == 'T')tx = j, ty = i;
		}
	}
	if (sx == tx || sy == ty) {
		cout << -1 << endl;
		return 0;
	}
	FordFulkerson flow;
	int S = H + W;
	int T = H + W + 1;
	flow.add_edge(S, sy, INF);
	flow.add_edge(S, H + sx, INF);
	flow.add_edge(ty, T, INF);
	flow.add_edge(H + tx, T, INF);

	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (s[i][j] == 'o')	flow.add_edge(i, H + j, 1), flow.add_edge(H + j, i, 1);
		}
	}
	ans = flow.max_flow(S, T);
	if(ans<=INF)
	cout << ans << endl;

	return 0;
}
