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

/* -----  2018/10/01  Problem: yukicoder 317  / Link: http://yukicoder.me/problems/no/317  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

dpっぽそう
しかし愚直DPだと、更新だけでもO(N^2)掛かりそうということがわかる。
ここで、ufのszについて考える。
sz(i)がcnt(i)個あるという風にまとめることができれば、個数はsqrt(N)個以下になる。
これはよくある個数制限dpに帰着できる。
具体的には以下
dp(i):=szがiとなるようにしたときの最小個数の和
ans(i) = dp(i)-1となる。
dpの更新は、dp(i+sz(k)) =min dp(i)+cnt(k)
とすれば良い。
O(sqrt(N)*NlogN+M)ぐらいだろうか…？


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


LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;
	UnionFind uf(N);
	FOR(i, 0, M) {
		int a, b; cin >> a >> b;
		a--, b--;
		uf.unionSet(a, b);
	}
	VI watch(N, 0);
	map<int, int>Map;
	FOR(i, 0, N) {
		if (watch[uf.root(i)])continue;
		watch[uf.root(i)] = 1;
		Map[uf.size(i)]++;
	}
	vector<PII>items;
	for (auto it : Map) {
		// it: (sz, cnt)
		for (int i = 1; ; i *= 2) {
			int sz = min(i, it.second);
			it.second -= sz;
			items.push_back(PII(it.first*sz, sz));
			if (it.second == 0)break;
		}
	}

	VI dp(N + 1, INF);
	dp[0] = 0;
	auto chmin = [](int&a, int b) {
		if (a > b)a = b;
	};
	for (auto item : items) {
		FORR(i, N-item.first, 0 - 1) {
			if (dp[i] == INF)continue;
			chmin(dp[i+item.first], dp[i] + item.second);
		}
	}

	// dp(i):=sz iを作る際に必要な要素数の和の最小値
	FOR(i, 1, N + 1) {
		if (dp[i] == INF)ans = -1;
		else ans = dp[i] - 1;
		cout << ans << "\n";
	}

	return 0;
}
