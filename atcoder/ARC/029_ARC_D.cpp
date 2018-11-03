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
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e18;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/11/03  Problem: ARC 029 D / Link: http://arc029.contest.atcoder.jp/tasks/arc029_d  ----- */
/* ------問題------

高橋君は妹から誕生日プレゼントに木のおもちゃを貰った。
木のおもちゃは N 個の球と N−1 本の節からなる。各球には 1 から N まで番号がつけられており、各節には 1 から N−1 まで番号が付けられている。
N−1 本の節は、異なる 2 つの球を接続しており、これらはすべて番号の大きい方の球から番号の小さい方の球へと向きが付けられている。また、球 1 以外のどの球からも、その球から番号の小さい別の球へと向きがつけられている節がある。
どの球もちょうど 1 つの整数を格納することができる。最初、球 i(1≦i≦N) には整数 si が格納されている。
高橋君は妹と一緒に、手元にある M 個の整数を使って木のおもちゃでゲームをすることにした。
ゲームの目的は、木のおもちゃのそれぞれの球に格納されている整数の合計ができるだけ大きくなるようにすることにした。
高橋君は M 回、以下のステップを行う。

手元にある整数を 1 つ取り出す。i(1≦i≦M) 回目のステップで取り出す整数は ti である。
以下のいずれかの操作を行う。
木のおもちゃに対して何もせず、整数 ti を捨てる。
木のおもちゃを構成する球から 1 つ選び、整数 ti を置く。
球 j(1≦j≦N) は、整数が置かれたとき、以下の動作を行う。
j=1 のとき、球 1 は元から格納してある整数を捨て、球 1 に置かれた整数を格納する。
j≧2 のとき、球 j は元から格納してある整数を、球 j から出ている節の行き先となる球におき、球 j に置かれた整数を格納する。
木のおもちゃの変化が止まるまで、高橋君と妹は次のステップに移動することができない。
最終的に木のおもちゃの各球に格納されている整数の合計値として考えられる最大値を求めよ。

-----問題ここまで----- */
/* -----解説等-----

列が押し出されることばかり考えていると何もわからない。
そこで、vが取り除かれるか？ということを考えるとvが取り除かれるなら、根からvまでの連続した頂点は必ず取り除かれることになる。
したがって、根から連続した頂点集合だけ取り除く際に、木では取り除かれる数字の和を最小化して、挿入する数字の和は最大化すれば良い。
これらは独立してできるので、最小化を考える。
頂点vを*選択し*合計k個選択した際の最小値、というDPをdp(v,k)とすると、適当にできる。
部分木のサイズでループを回せば2乗の木DPになる。

----解説ここまで---- */


LL dp[5003][5003];
void dfs(int v, int p, const VVI& G, const VI& s, VI& sz) {
	sz[v] = 1;
	dp[v][0] = 0, dp[v][1] = s[v];
	for (int nx : G[v]) {
		if (nx == p)continue;
		dfs(nx, v, G, s, sz);
		for (int i = sz[v]; i > 0; i--) {
			for (int j = sz[nx]; j >= 0; j--) {
				dp[v][i + j] = min(dp[v][i + j], dp[v][i] + dp[nx][j]);
			}

		}
		sz[v] += sz[nx];
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	VI s(N, 0);
	FOR(i, 0, N) {
		cin >> s[i];
	}
	VVI G(N);
	FOR(i, 0, N - 1) {
		int a, b; cin >> a >> b;
		a--, b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	VI sz(N);
	fill(*dp, *dp + 5003 * 5003, LINF);
	dfs(0, -1, G, s, sz);

	int M; cin >> M;
	VL t(M + 1, 0);
	FOR(i, 0, M) {
		cin >> t[i];
	}
	RSORT(t);
	// \sum s + i個根の周りから取り除いてtをi個追加する感じのmax
	LL sum = accumulate(ALL(s), 0LL);
	LL ans = sum;
	FOR(i, 0, M + 1) {
		ans = max(ans, sum - dp[0][i]);
		sum += t[i];
	}

	cout << ans << "\n";

	return 0;
}
