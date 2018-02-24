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

/* -----  2018/02/23  Problem: 090_arc_b / Link: https://abc087.contest.atcoder.jp/tasks/arc090_b?lang=en  ----- */
/* ------問題------

x 軸上に N 人の人が立っています。 人 i の位置を xi とします。 任意の i に対して、xi は 0 以上 109 以下の整数です。 同じ位置に複数の人が立っていることもありえます。
これらの人の位置に関する情報が M 個与えられます。 このうち i 個めの情報は (Li,Ri,Di) という形をしています。 この情報は、人 Ri は人 Li よりも距離 Di だけ右にいること、 すなわち、xRi−xLi=Di が成り立つことを表します。
これら M 個の情報のうちのいくつかに誤りがある可能性があることがわかりました。 与えられる M 個すべての情報と矛盾しないような値の組 (x1,x2,…,xN) が存在するかどうか判定してください。

-----問題ここまで----- */
/* -----解説等-----

この前やった
相対的な距離は重み付きUFでもできるけどグラフとしては逆辺に負のコストを与えれば良い。

----解説ここまで---- */

LL N, M;

int ans;

void dfs(int v, int p, LL d, VL& dist, VI& visit, vector<vector<PLL>>& G) {
	if (!visit[v])dist[v] = d, visit[v] = 1;
	FOR(i, 0, SZ(G[v])) {
		int nx = G[v][i].first;
		LL cost = G[v][i].second;
		if (nx != p) {
			if (visit[nx]) {
				if (dist[v] + cost != dist[nx])ans = 0;
			}
			else {
				dfs(nx, v, d + cost, dist, visit, G);
			}

		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	vector<vector<PLL>> G(N);
	FOR(i, 0, M) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		G[a].push_back(PLL(b, c));
		G[b].push_back(PLL(a, -c));
	}
	VL dist(N, 0);
	VI visit(N, 0);
	ans = 1;
	FOR(i, 0, N) {
		if (!visit[i])dfs(i, -1, 0, dist, visit, G);
	}

	cout << (ans==1 ? "Yes" : "No") << "\n";

	return 0;
}
