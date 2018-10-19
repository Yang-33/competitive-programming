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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DEBUG(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };    int DY[8] = { 1, 0, -1, 0, 1, -1, 1, -1 };

/* -----  2018/10/17  Problem: ARC 040 D / Link: http://arc040.contest.atcoder.jp/tasks/arc040_d  ----- */
/* ------問題------

イカの高橋君は床を塗るのが大好きです。床は N×N のマス目状に区切られており、いくつか（0 個もありうる）のマスには障害物があります。高橋君はこの床を以下のルールで塗ろうと考えています。
「今いるマスの床を塗って、上下左右いずれかの隣のマスに移動する」という行動を繰り返す。
移動するたびに向きを 90 度回転する。すなわち、上または下に移動した直後には右または左に移動し、右または左に移動した直後には上または下に移動する。
すでに塗ったマスには移動しない。
マス目の外や障害物のあるマスには移動しない。
高橋君は、すでにどのマスからスタートするかを決めています。このとき、高橋君はうまく移動しながら床を塗ることで、障害物のない全てのマスを塗ることが可能でしょうか。ただし、スタート直後の移動方向や最後に塗るマスには特に指定はありません。また、最後のマスを塗った直後には移動する必要はありません。

-----問題ここまで----- */
/* -----解説等-----

ハミルトンパスの判定...NP困難だけど性質が強いので解ける。(みたい)
ハミルトンパスを持つための必要十分条件は以下の通りである．
どの行，列も偶数個空きマスがある
上で示したように辺で連鎖的に連結したとき，空きマスだけからなるグラフが全体として連結
ここで終点の候補が O(N^2)個あって大変に思えるが，どの列，どの行を選ぶか，という候補が実は少ないため，終点の候補は O(N)個程度．

----解説ここまで---- */


struct UnionFind {
	vector<int> data;
	UnionFind(int n) { data.assign(n, -1); }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};



bool f(const PII s, const PII g, int sd, int gd, const VS& vs) {
	if (s == g)return false;
	if (vs[g.first][g.second] == '#')return false;

	int N = SZ(vs);
	UnionFind uf(N*N);
	auto za = [&N](int i, int j) {
		return i * N + j;
	};

	FOR(i, 0, N) {
		FOR(j, 0, N - 1) { // --
			if (vs[i][j] == '#' || vs[i][j + 1] == '#')continue;

			if (i == s.first && (j == s.second || j + 1 == s.second) && sd == 1)continue;
			if (i == g.first && (j == g.second || j + 1 == g.second) && gd == 1)continue;
			if (uf.same(za(i, j), za(i, j + 1)))continue;
			uf.unionSet(za(i, j), za(i, j + 1));
			j++;
		}
	}

	FOR(j, 0, N) {//         |
		FOR(i, 0, N - 1) {// |
			if (vs[i][j] == '#' || vs[i + 1][j] == '#')continue;

			if ((i == s.first || i + 1 == s.first) && (j == s.second) && sd == 0)continue;
			if ((i == g.first || i + 1 == g.first) && (j == g.second) && gd == 0)continue;

			if (uf.same(za(i, j), za(i + 1, j)))continue;
			uf.unionSet(za(i, j), za(i + 1, j));
			i++;
		}
	}

	FOR(i, 0, N) {
		FOR(j, 0, N) {
			if (vs[i][j] == '#')continue;
			if (!uf.same(za(s.first, s.second), za(i, j)))return false;
		}
	}

	return true;
}




const int H = 0;
const int W = 1;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	VS vs(N);
	FOR(i, 0, N) {
		cin >> vs[i];
	}
	PII s, t;
	VVI cnt(2, VI(N, 0));
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			if (vs[i][j] == '.') {
				cnt[H][i]++; cnt[W][j]++;
			}
			else if (vs[i][j] == 's') {
				vs[i][j] = '.';
				s = PII(i, j);
			}
		}
	}

	bool ok = 0;
	{
		cnt[H][s.first]++;
		{
			int gx = -1;
			FOR(x, 0, N)if (cnt[W][x] % 2)gx = x;
			if (gx != -1) {
				FOR(gy, 0, N) {
					ok |= f(s, PII(gy, gx), 0, 0, vs);
				}
			}
		}
		{
			int gy = -1;
			FOR(y, 0, N)if (cnt[H][y] % 2)gy = y;
			if (gy != -1) {
				FOR(gx, 0, N) {
					ok |= f(s, PII(gy, gx), 0, 1, vs);
				}
			}
		}
		cnt[H][s.first]--;
	}
	{
		cnt[W][s.second]++;
		{
			int gx = -1;
			FOR(x, 0, N)if (cnt[W][x] % 2)gx = x;
			if (gx != -1) {
				FOR(gy, 0, N) {
					ok |= f(s, PII(gy, gx), 1, 0, vs);
				}
			}
		}
		{
			int gy = -1;
			FOR(y, 0, N)if (cnt[H][y] % 2)gy = y;
			if (gy != -1) {
				FOR(gx, 0, N) {
					ok |= f(s, PII(gy, gx), 1, 1, vs);
				}
			}
		}
		cnt[W][s.second]--;
	}

	cout << (ok ? "POSSIBLE" : "IMPOSSIBLE") << endl;



	return 0;
}
