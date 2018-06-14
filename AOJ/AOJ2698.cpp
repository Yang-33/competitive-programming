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

/* -----  2018/06/14  Problem: AOJ 2698 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2698  ----- */
/* ------問題------

4面分割grundy数を求める

-----問題ここまで----- */
/* -----解説等-----

4^すればよいね(こういうのをコドフォでやったことがある)
testcase内には20*20以下、grundy数の最大値は53以下だったためset以外の高速化が可能。(しなくてもいい)

----解説ここまで---- */

int grundy[22][22][22][22];
int f(int sy, int ty, int sx, int tx, const VS& vs) {
	if (grundy[sy][ty][sx][tx] != -1)return grundy[sy][ty][sx][tx];

//	set<int>Se;
	bool se[55] = { 0 };
	FOR(i, sy, ty) {
		FOR(j, sx, tx) {
			if (vs[i][j] == 'X')continue;
			int val = 0;
			val ^= f(sy   ,  i, sx   , j, vs);
			val ^= f(sy   ,  i, j + 1, tx, vs);
			val ^= f(i + 1, ty, sx   , j, vs);
			val ^= f(i + 1, ty, j + 1, tx, vs);
			//Se.insert(val);
			if (val <= 54)se[val] = 1;
		}
	}


	int subgame = 0;
	//	while (Se.count(subgame))subgame++;
	while (se[subgame])subgame++;
	//assert(subgame <= 53);
	return grundy[sy][ty][sx][tx] = subgame;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	int H, W;
	cin >> H >> W;
	VS vs(H);
	FOR(i, 0, H) {
		cin >> vs[i];
	}
	fill(***grundy, ***grundy + 22 * 22 * 22* 22, -1);
	int ret = f(0, H, 0, W, vs);
	cout << (f(0, H, 0, W, vs) != 0 ? "First" : "Second") << "\n";

	return 0;
}
