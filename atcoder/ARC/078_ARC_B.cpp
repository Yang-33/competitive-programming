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

/* -----  2018/02/23  Problem: 078_arc_b / Link: https://abc067.contest.atcoder.jp/tasks/arc078_b?lang=en  ----- */
/* ------問題------

フェネックとすぬけくんがボードゲームで遊んでいます。
このボードゲームには 1 番から N 番までの番号がついた N 個のマスと、マスどうしをつなぐ N−1 本の道が存在しています。 ai 番のマスと bi 番のマスは i 番目の道を介して隣り合っています。どの 2 つのマスも隣接するマスをいくつか辿って必ず辿り着くことが可能です。すなわち、グラフ理論の言葉を用いると、マスと道から構成されるグラフは木です。
はじめに 1 番のマスは黒く、N 番のマスは白く塗られています。その他のマスはまだ色が塗られていません。 先手のフェネックと後手のすぬけくんは残りのマスに交互に色を塗ります。 自分の手番において、2 人はそれぞれ以下のような行動を行います。
フェネック：黒く 塗られたマスに隣接したマスであって、色が塗られていないマスを 1 つ選んで 黒く 塗る。
すぬけくん：白く 塗られたマスに隣接したマスであって、色が塗られていないマスを 1 つ選んで 白く 塗る。
手番のプレイヤーがマスに色を塗ることができなかったとき、敗者となります。フェネックとすぬけくんが最適に行動したとき勝者はどちらか判定してください。

-----問題ここまで----- */
/* -----解説等-----

与えられるグラフは木なので、ガンガン遠くに行って良い。
お互いの反対側には到達できないので考えるのは境界の位置だけで良い。
これは0,N-1の中心の位置であるが、木なのでこれは一点しか無い。また先攻が少し有利なので中心的な場所も先攻の場所となる。
したがって木上の距離を記録しこれを比較すれば良い。

----解説ここまで---- */

LL N;

LL ans = 0LL;
void dfs(int v, int p, int d, VVI& G, VI& dist) {
	dist[v] = d;
	FOR(i, 0, SZ(G[v])) {
		int nx = G[v][i];
		if (nx != p) {
			dfs(nx, v, d + 1, G, dist);
		}
	}
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VVI G(N);
	FOR(i, 0, N - 1) {
		int a, b;
		cin >> a >> b;
		G[a - 1].push_back(b - 1);
		G[b - 1].push_back(a - 1);
	}
	VI distF(N, -1);
	VI distS(N, -1);
	dfs(0, -1, 0, G, distF);
	dfs(N-1, -1, 0, G, distS);
	int Fcnt = 0;
	FOR(i, 0, N) {
		if (distF[i] <= distS[i])Fcnt++;
	}

	if (Fcnt > N - Fcnt) {
		cout << "Fennec" << endl;
	}
	else cout << "Snuke" << endl;

	return 0;
}
