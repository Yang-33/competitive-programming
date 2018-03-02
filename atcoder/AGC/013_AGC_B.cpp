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

/* -----  2018/03/02  Problem: 013_agc_b / Link: https://agc013.contest.atcoder.jp/tasks/agc013_b?lang=en  ----- */
/* ------問題------

N 頂点 M 辺の、連結な単純無向グラフが与えられます。 頂点には 1 から N までの番号がついており、辺には 1 から M までの番号がついています。 辺 i は、頂点 Ai と頂点 Bi を結んでいます。 次の条件を満たすパスを 1 つ見つけて、出力してください。
2 個以上の頂点を通る
同じ頂点を 2 度以上通らない
パスの少なくとも一方の端点と直接辺で結ばれている頂点は、必ずパスに含まれる
ただし、この問題の制約の下で、このようなパスが必ず存在することが証明できます。 また、あり得る答えのうちどれを出力しても構いません。

-----問題ここまで----- */
/* -----解説等-----

昔は次数で場合分けしていたけどその必要はない。
適当に頂点Pを選択し、これからpathをひとつ作成する。
作成後はPでない端の点は条件を満たしている。
一方Pは条件を満たしているかはわからないのでもう一回pathを作れば良い。

次数1だともっと見通しが良い気はする。

----解説ここまで---- */

LL N, M;

LL ans = 0LL;
void dfs(int v, VI& path, VI& visit, VVI& G) {
	visit[v] = 1;
	path.push_back(v);
	FOR(i, 0, SZ(G[v])) {
		int nx = G[v][i];
		if (!visit[nx]) {
			dfs(nx, path, visit, G);
			break;
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	VVI G(N);
	FOR(i, 0, M) {
		int a, b; cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	VI path;

	VI visit(N,0);
	dfs(0, path, visit, G);
	VI path2;
	dfs(0, path2, visit, G);
	cout << SZ(path) + SZ(path2) -1<< endl;
	reverse(ALL(path2));
	FOR(i, 0, SZ(path2)-1) {
		cout << path2[i] + 1 << " ";
	}
	FOR(i, 0, SZ(path)) {
		cout << path[i] + 1<< " ";
	}
	cout << "\n";

	return 0;
}
