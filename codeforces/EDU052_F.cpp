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
const LL MOD = 998244353;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/10/11  Problem: EDU052 F / Link: __CONTEST_URL__  ----- */
/* ------問題------

根を頂点1とする n 頂点の根付き木と、整数 k が与えられる。頂点1にトークンを置いた状態から、以下の操作を0回以上繰り返す。
いまトークンが置かれている頂点を v として、
v が葉でない場合、v 以下の部分木に含まれる葉のうちいずれかにトークンを移す。
v が葉である場合、v から最大 k 回親を辿った先の頂点にトークンを移す。
頂点1にトークンを置いた状態からスタートし、なるべく多くの葉を訪れたい。その最大数を求めよ。
※接続されている辺の数が1本である頂点を葉と呼ぶが、今回は根である頂点1は葉ではないとして扱う。

-----問題ここまで----- */
/* -----解説等-----

これいい問題
まず、基本的にある部分木の頂点Vについて、葉まで降りてかえってこれるならそうした方が良い。
更に返ってこれない子のうち、最大値を取れば良いことになり、これを木DPすれば良い。
木DPに必要と思った情報は以下の3つ。
ndep(i):= 頂点iから最も近い葉までの距離
dp(i):= ndep(i'c)がK未満であるとき、i'cに到達可能なのでこれらの到達可能な頂点でgetできる葉の合計
ans(i):= dp(i)に加えて、どれか子に移動して得られる最大コスト
ndepは葉から持ち上げた値のminを取れば良い。
dpはndepがK未満なら足せば良い。
ansは基本的にans(i'c)-dp[i'c]の最大値である。
ただし、dp(i'c)を得ることすらできない場合はdpと連結されていないので、取り除く必要はない。

----解説ここまで---- */

int read() { int in; scanf("%d", &in); return in; }

int ans[1000006];
int dp[1000006];
int ndep[1000006];
int K;

void dfs(int v, const VVI& G) {
	if (SZ(G[v]) == 0) {
		ndep[v] = 0;
		dp[v] = 1;
		return;
	}
	int nearest = INF;
	int subans = 0;
	for (int nx : G[v]) {
		dfs(nx, G);
		nearest = min(nearest, ndep[nx] + 1);
		if (ndep[nx] < K) { // いけるなら取る
			dp[v] += dp[nx];
		}
		// 更に掘る分は、dpを含んでいるなら取り除く
		subans = max(subans,
			ans[nx] - (ndep[nx] < K ? dp[nx] : 0));
	}
	ndep[v] = nearest;
	ans[v] = dp[v] + subans;
}

int main() {
	int N = read();
	K = read();
	VVI G(N);
	FOR(i, 1, N) {
		int p = read() - 1;
		G[p].push_back(i);
	}
	dfs(0, G);
	cout << ans[0] << endl;
}