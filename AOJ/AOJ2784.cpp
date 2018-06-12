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

/* -----  2018/06/13  Problem: AOJ 2784 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2784  ----- */
/* ------問題------

ある部分木T,T'が似ているというのは、それ以下の部分木での任意の深さについて、その深さに存在するノードの数が等しいことを言う。
N<=10^5の木が与えられるので、似ている木の組を数え上げよ。

-----問題ここまで----- */
/* -----解説等-----

しっかり考えると情報を持たないといけないが、陽にdataを持つと計算量が壊れることがわかる。
情報を多項式的に持てば解けそうとなるが分からない。
全然わからないのでハッシュをえいすると通る。

追記：ハッシュは多項式

----解説ここまで---- */

const LL mod = 1000000007;
using ukuku = unsigned long long;
map<ukuku, LL>Map;

ukuku dfs(int v, const VVL& G) {
	ukuku ret = 1000000009;
	FOR(i, 0, SZ(G[v])) {
		int nx = G[v][i];
		ret += dfs(nx, G)*mod;
	}
	Map[ret]++;
	return ret;
}

void solve() {
	int N;
	cin >> N;
	VVL G(N);
	FOR(i, 0, N - 1) {
		int a, b; cin >> a >> b;
		a--, b--;
		G[a].push_back(b);
	}
	dfs(0, G);
	LL ans = 0;
	for (auto it : Map) {
		ans += (it.second)*(it.second - 1) / 2;
	}
	cout << ans << endl;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	solve();

	return 0;
}