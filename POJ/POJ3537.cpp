#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;

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

/* -----  2017/11/04  Problem: POJ 3537 / Link: http://poj.org/problem?id=3537  ----- */
/* ------問題------

1*Nの盤面に〇を書いていく。
不偏ゲームとしてゲームを行ったとき、このゲームはどちらにとって必勝の目か。

-----問題ここまで----- */
/* -----解説等-----

分割したらゲームは直和として取れるので、これはgurndy数のやつ。
Xorをとればよい。g[4]!=0に気を付けましょう(それはそう)

----解説ここまで---- */

int N;

vector<int>g;
int grundy(int x) {
	if (x < 0)return 0;
	if (g[x] != -1)return g[x];

	bool se[2048];
	fill(se, se + 2048, 0);
	FOR(i, 1, x + 1) {
		int num = grundy(i - 3) ^ grundy(x - i - 2);
		se[num] = 1;
	}
	int subg = 0;
	while (se[subg])subg++;
	return g[x] = subg;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	g = vector<int >(2048, -1);
	g[0] = 0;
	g[1] = g[2] = g[3] = 1;
	while (cin >> N) {
		cout << (grundy(N) != 0 ? "1" : "2") << "\n";
	}
	return 0;
}
