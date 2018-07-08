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

/* -----  2018/07/07  Problem: soundhound2018_master_qual E / Link: __CONTEST_URL__  ----- */
/* ------問題------

kenkooooさんは n 頂点 m 辺の単純連結グラフを拾いました。 グラフの頂点には 1 から n の番号が付けられていて、 i 番目の辺は頂点 ui と vi をつないでいます。 また、i 番目の辺には整数 si が定められています。
kenkooooさんは次の条件を満たすようにそれぞれの頂点に 正の整数 を書き込もうとしています。
どの辺 i についても、頂点 ui と vi に書かれた正の整数の和は si に等しい
条件を満たすような正の整数の書き方が何通りあるか求めてください。

-----問題ここまで----- */
/* -----解説等-----

木のときを考えると、値Xを頂点0から伝播させれば良い。あとは条件を満たす共通範囲を求めれば良い。
次に閉路がある時を考える。二部グラフのときは条件をみたす範囲が狭まるだけなのでこれは求められる。
二部グラフではないときは更に条件が狭まり、0か1になる。(ちょうど存在するパターンも有る)


----解説ここまで---- */

VL A, B, C;
void dfs(int v, VL&cost, VI&visit, VI&color, const vector<vector<PLL>>&G) {
	for (auto ed : G[v]) {
		int nx = ed.first;
		if (visit[nx]) {
			if (color[v] == color[nx]) {
				A.push_back(v);
				B.push_back(nx);
				C.push_back(ed.second);
			}
			continue;
		}
		visit[nx] = 1;
		color[nx] = 1 ^ color[v];
		cost[nx] = ed.second - cost[v];
		dfs(nx, cost, visit, color, G);
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	vector<vector<PLL>>G(N);
	using tp = tuple<int, int, int>;
	vector<tp>edge;
	FOR(i, 0, M) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		G[a].push_back(PLL(b, c));
		G[b].push_back(PLL(a, c));
		edge.push_back(tp(a, b, c));
	}

	VL cost(N, 0);
	VI visit(N, 0);
	VI color(N, 0);
	cost[0] = 1;
	visit[0] = 1;
	dfs(0, cost, visit, color, G);
	auto check = [&]() {
		FOR(i, 0, N)if (cost[i] < 1)return false;
		FOR(i, 0, SZ(edge)) {
			int a, b, c; tie(a, b, c) = edge[i];
			if (cost[a] + cost[b] != c)return false;
		}
		return true;
	};
	if (SZ(A)) {// 矛盾しうる -> 二部グラフでない
		LL dist0 = C[0] - (cost[A[0]] + cost[B[0]]);
		if (abs(dist0) % 2) {
			cout << 0 << endl;
		}
		else { // 差が偶数なら調整可能かも
			dist0 /= 2;
			FOR(i, 0, N) {
				if (color[i] == color[A[0]])cost[i] += dist0;
				else cost[i] -= dist0;
			}
			cout << check() << endl; // 調整してあり得る場合
		}
	}
	else { // 0 or R-L+1
		LL L = LINF, R = LINF;
		FOR(i, 0, N) {
			if (color[i]) {
				R = min(R, cost[i]);
			}
			else {
				L = min(L, cost[i]);
			}
		}
		if (L < 1) {
			
			FOR(i, 0, N) {
				if (color[i]) {
					cost[i] -= 1 - L;
				}
				else {
					cost[i] += 1 - L;
				}
			}
		}
		debug(R);
		debug(L);
		LL ans = max(0LL, L + R - 1);
		if (!check())ans = 0;
		cout << ans << endl;

	}


	return 0;
}
