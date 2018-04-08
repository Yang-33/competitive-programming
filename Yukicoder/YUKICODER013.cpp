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

/* -----  2018/04/08  Problem: yukicoder 013  / Link: http://yukicoder.me/problems/no/013  ----- */
/* ------問題------

kevinはとあるゲームをしている。
横W縦H個のマスで構成されるフィールドが与えられる。
最初にあるマスを選択し、上下左右の同じ数字のみ辿れ、任意の場所で離す事ができる。
この時、同じ数字のみをたどって、囲みができたら高得点になるゲームである。

囲みとは、辿ったマスの順番に線をつないだ時に、K(≥4)角形ができていることである。

フィールドが与えられた時に囲みができるかどうか判定してください。
囲みが出来る場合 possible 出来ない場合は impossible を出力してください。

-----問題ここまで----- */
/* -----解説等-----

つまるところ四方向に移動できるグリッドグラフで閉路検出をすればよい。
これは今まで訪れたことのある頂点を発見できればよくて、bfsでもdfsでも書くことができる。
よくある感じで実装すれば良い。

----解説ここまで---- */

LL W,H;

LL ans = 0LL;

void bfs(int y, int x,int num, VVI& a, VVI& visit) {

	using tp = tuple<PII, PII>;
	queue<tp>q;
	q.push(tp(PII(y, x), PII(-1, -1)));
	while (!q.empty()) {
		PII pos, pre;
		tie(pos, pre) = q.front(); q.pop();

		FOR(k, 0, 4) {
			int ny = pos.first + DY[k], nx = pos.second + DX[k];
			if (0 <= ny && ny < H && 0 <= nx && nx < W) {
				if (ny == pre.first && nx == pre.second)continue;
				if (a[ny][nx] == num) {
					if (visit[ny][nx])ans = 1;
					else {
						q.push(tp(PII(ny,nx), pos));
						visit[ny][nx] = 1;
					}
				}
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> W >> H;
	VVI a(H, VI(W, 0));
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			cin >> a[i][j];
		}
	}
	VVI visit(H, VI(W, 0));
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (!visit[i][j])bfs(i, j, a[i][j], a, visit);
		}
	}
	cout << (!ans?"impossible":"possible") << "\n";

	return 0;
}
