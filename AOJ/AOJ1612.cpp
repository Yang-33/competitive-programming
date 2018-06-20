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

/* -----  2018/06/19  Problem: AOJ 1612 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1612  ----- */
/* ------問題------

立方体印刷によるインスタレーションコンテスト (Installation art Contest with Printed Cubes, ICPC) に出品するため， 我々は 3D プリンタを使って立方体を組み合わせたインスタレーションの作品をデザインしている． 今回はちょうど k 個の同じ大きさで同じ向きの立方体を用いて作品を作ることを試みている．
まず， CAD を用いて，立方体を配置する場所の候補となる場所を n (n ≥ k) 個 3D 空間中に用意する． 立方体を全ての候補場所に置いたとすると， 以下の 3 条件が満たされる．
各立方体は 0 個，1 個 または 2 個の立方体と重なることがあるが，3 個以上とは重ならない．
ある立方体が 2 個の立方体と重なるとき，その 2 個の立方体は重ならない．
面や辺や頂点で接触するだけで重なりのない 2 個の立方体はない．
つぎに，この n 個の候補の中から k 個の異なる場所を上手に選び， そこに立方体を配置して， k 個の立方体の併合としてひとつの連結した多面体を得る． 3Dプリンタを用いるときは， 物体の薄い表面だけを印刷するのが普通である． プリンタ用の材料を節約するため， 最小の表面積を持つ多面体を見つけたい．

あなたの仕事は， 与えられた n 個の位置の中から選ばれた k 個の位置に置かれた k 個の連結する立方体が作る多面体のうち表面積が一番小さいものを探すことである．

-----問題ここまで----- */
/* -----解説等-----

自明に列か環そのもの。
問題を全体の表面積-重なっている部分の表面積としてみる。
このときグラフで表現をすると、K頂点の連結グラフを選択し、これの辺の重みを最大化したいことがわかる。
環で一周しているときのケースとそうでないケースを分ければO(N^2)で計算ができる。

----解説ここまで---- */


LL x[2003], y[2003], z[2003];
LL decS(int i, int j, int S) {
	LL X = S - abs(x[i] - x[j]);
	LL Y = S - abs(y[i] - y[j]);
	LL Z = S - abs(z[i] - z[j]);
	LL area = 2 * (X*Y + Y * Z + Z * X);
	return abs(area);
}

#define SZ(a) (int)a.size()
using PLL = pair<LL, LL>;

LL dfs(int v, int p, int POS, int leftK, const vector<vector<PLL>> &G) {
	if (leftK == 0) {
		if (SZ(G[v]) == 2) { //分岐さんね
			if (G[v][0].first == POS && G[v][0].first != p)return G[v][0].second;
			if (G[v][1].first == POS && G[v][1].first != p)return G[v][1].second;
		}
		return 0;
	}

	LL res = -1;
	FOR(i, 0, SZ(G[v])) {
		if (G[v][i].first == p)continue;
		LL subres = dfs(G[v][i].first, v, POS, leftK - 1, G);
		if (subres != -1)res = max(res, subres + G[v][i].second);
	}
	return res;
}


int N, K, S;
//連結での重みを最大にしてくり
LL solve2(const vector<vector<PLL>>& G) {
	LL res = -1;
	FOR(i, 0, N) {
		res = max(res, dfs(i, -1, i, K - 1, G));
	}
	if (res == -1)return -1;
	else return 6 * K *S*S - res;
}

void solve() {
	while (cin >> N >> K >> S, N || K || S) {

		FOR(i, 0, N) {
			cin >> x[i] >> y[i] >> z[i];
		}
		vector<vector<PLL>>G(N);
		FOR(i, 0, N) {
			FOR(j, i + 1, N) {
				LL X = S - abs(x[i] - x[j]);
				LL Y = S - abs(y[i] - y[j]);
				LL Z = S - abs(z[i] - z[j]);

				if (X <= 0 || Y <= 0 || Z <= 0) {
					continue;
				}
				LL W = decS(i, j, S);
				G[i].push_back(PLL(j, W));
				G[j].push_back(PLL(i, W));
			}
		}
		cout << solve2(G) << endl;
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	solve();

	return 0;
}