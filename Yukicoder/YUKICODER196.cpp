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

/* -----  2018/07/31  Problem: yukicoder 196  / Link: http://yukicoder.me/problems/no/196  ----- */
/* ------問題------

N 個の頂点をもつ根付き木と整数 K が与えられます。この木の各頂点を白または黒で塗ることを考えます。
次の2条件をともに満たすような塗り方の個数を 1,000,000,007 で割った余りを求めてください。
1. ちょうど K 個の頂点が黒で塗られる。
2. 黒で塗られる任意の頂点 v について、v のどの子もまた黒で塗られる。

-----問題ここまで----- */
/* -----解説等-----

2012年ぐらいの有名なアレ?->2乗の木DP
dp[v][k]:=v以下に黒の塗り数がkの塗り方
乗法の和をdpすればよい。
ただし、子からマージする時に情報がかぶるので、一回退避させる。

計算量解析できるようになりたい。O(NK)

----解説ここまで---- */

LL dp[2002][2002];
int sz[2002];
LL temp[2002];
int K;
void f(int v, int p, const VVI&G) {
	sz[v] = 1;

	dp[v][0] = 1;
	for (int nx : G[v]) {
		if (nx == p)continue;
		f(nx, v, G);
		FOR(rk, 0, sz[v] + 1) {
			FOR(k, 0, sz[nx] + 1) {
				if (rk + k == sz[v] + sz[nx])continue;
				temp[k+rk] += dp[v][rk]*dp[nx][k];
				temp[k + rk] %= MOD;
			}
		}
		sz[v] += sz[nx];
		FOR(i, 0, sz[v]+1) {
			dp[v][i] = temp[i];
			temp[i] = 0;
		}
	}
	dp[v][sz[v]]++;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N >> K;
	VVI G(N);
	FOR(i, 0, N - 1) {
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	f(0, -1, G);

	LL ans = 0;
	ans = dp[0][K];


	cout << ans << "\n";

	return 0;
}
