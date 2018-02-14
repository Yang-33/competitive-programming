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

/* -----  2018/02/14  Problem: 054_abc_c / Link: https://abc054.contest.atcoder.jp/tasks/abc054_c?lang=en ----- */
/* ------問題------

自己ループと二重辺を含まない N 頂点 M 辺の重み無し無向グラフが与えられます。
i(1≦i≦M) 番目の辺は頂点 ai と頂点 bi を結びます。 
ここで、自己ループは ai=bi(1≦i≦M) となる辺のことを表します。 
また、二重辺は ai=aj かつ bi=bj(1≦i<j≦M) となる辺のことを表します。 
 頂点 1 を始点として、全ての頂点を1度だけ訪れるパスは何通りありますか。 
ただし、パスの始点と終点の頂点も訪れたものとみなします。

-----問題ここまで----- */
/* -----解説等-----

頂点に一度しか訪れないので愚直に全探索すれば良い

----解説ここまで---- */

LL N,M;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>M;
	VVI G(N, VI(N,0));
	FOR(i, 0, M) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		G[a][b] = 1;
		G[b][a] = 1;
	}
	VI root;
	FOR(i, 1, N)root.push_back(i);

	do	{
		int pos = 0;
		int ok = 1;
		FOR(i,0,SZ(root)) {
			if (G[pos][root[i]]) {
				pos = root[i];
			}
			else {
				ok = 0;
				break;
			}
		}
		if (ok)ans++;


	} while (next_permutation(ALL(root)));

	cout << ans << "\n";

	return 0;
}
