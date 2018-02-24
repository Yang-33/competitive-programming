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

/* -----  2018/02/24  Problem: soundhound-2018-spring_c / Link: https://soundhound2018.contest.atcoder.jp/tasks/soundhound2018_c?lang=en  ----- */
/* ------問題------

縦に r 個、横に c 個の r×c 個のマスからなるグリッドがあり、それぞれのマスには * か . が書かれています。上から i 番目、左から j 番目のマスに書かれた文字を Ci,j とおきます。
kenkooooさんは . のマスにSoundHoundの広告を打つことにしました。1 つのマスには 1 個だけ広告を打てます。しかし、あまりに密集していると逆効果なので、隣り合う 2 つのマスの両方に広告を打つことはありません。ここで、隣り合う 2 つのマスとは、あるマスとその上下左右で隣り合うマスのことを表します。
kenkooooさんは最大でいくつ広告を打てるでしょうか？

-----問題ここまで----- */
/* -----解説等-----

最大安定集合だけど二部グラフなので貼るだけ。
そういうのいいでーす

----解説ここまで---- */
struct Bipartite_Matching {
	vector<vector<int> > graph;
	vector<int> match, alive, used;
	int timestamp;

	Bipartite_Matching(int n) {
		timestamp = 0;
		graph.resize(n);
		alive.assign(n, 1);
		used.assign(n, 0);
		match.assign(n, -1);
	}

	void add_edge(int u, int v) {
		graph[u].push_back(v);
	}

	bool dfs(int v) {
		used[v] = timestamp;
		for (int i = 0; i < (int)graph[v].size(); i++) {
			int u = graph[v][i], w = match[u];
			if (alive[u] == 0) continue;
			if (w == -1 || (used[w] != timestamp && dfs(w))) {
				match[v] = u;
				match[u] = v;
				return (true);
			}
		}
		return (false);
	}

	int bipartite_matching() {
		int ret = 0;
		for (int i = 0; i < (int)graph.size(); i++) {
			if (alive[i] == 0) continue;
			if (match[i] == -1) {
				++timestamp;
				ret += dfs(i);
			}
		}
		return (ret);
	}
};


LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int H, W;
	cin >> H >> W;
	VS s(H);
	
	map<PII, int>Map;
	FOR(i, 0, H) {
		cin >> s[i];
		FOR(j, 0, W) {
			if (s[i][j] == '.')Map[PII(i,j)]=N++;
		}
	}
	Bipartite_Matching F(N);
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (s[i][j] == '.') {
				FOR(k, 0, 4) {
					int ny = i + DY[k];
					int nx = j + DX[k];
					if (0 <= ny&&ny < H && 0 <= nx&&nx < W) {
						if (s[ny][nx] == '.') {
							F.add_edge(Map[PII(i, j)], Map[PII(ny, nx)]);
						}
					}
				}
			}
		}
	}
	ans = N - F.bipartite_matching();
	cout << ans << "\n";

	return 0;
}
