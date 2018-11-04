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
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/11/04  Problem: ARC 045 C / Link: http://arc045.contest.atcoder.jp/tasks/arc045_c  ----- */
/* ------問題------

多橋君は橋が大好きです。したがって、全ての辺が橋(グラフ理論用語)となる木と呼ばれるグラフが大好きです。また、多橋君は最近学校でXORについて学びました。そこで、次のような問題について考えています。
N 頂点と N−1 本の辺からなる連結な無向グラフ、つまり木が与えられます。各頂点は、それぞれ頂点 1、頂点 2、…、頂点 N と呼ばれます。各辺にはそれぞれ非負整数のコストが割り振られています。
整数 X が与えられるので、頂点 a と頂点 b を結ぶ単純パス(同じ辺を二度通らないパス、木においては必ず 1 つだけ存在する)上の辺のコストのxor和が X になるような組 (a,b) (1≦a<b≦N)の総数を求めてください。 ただしxor和とは、いくつかの整数 A1,A2,… があったとき、それらの2進表現のビット毎の排他的論理和 A1 xor A2 xor… により得られる値のことを表します。 例えば、1 xor 2 xor 5 は 6 です。
あなたの仕事は、多橋君の代わりにこの問題を解くことです。

-----問題ここまで----- */
/* -----解説等-----

ICPCregionalでみた
l = lca(x,y), X = pathxor(x,y) = pathxor(0,x)^pathxor(0,y)^pathxor(0,l)^pathxor(0,l)
なので、対を数えるだけで良い。
path^X=pathは数えてはいけないので注意(X==0だけ)

----解説ここまで---- */


void dfs(int v, int p, const vector<vector<PLL>>&G, LL Xor, map<LL, LL>&Map,VL & val) {
	Map[Xor]++;
	val[v] = Xor;
	for (PLL nx : G[v]) {
		if (nx.first == p)continue;
		DD(de(v, p, Xor, nx.second, Xor^nx.second));
		dfs(nx.first, v, G, Xor^nx.second, Map,val);
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, X; cin >> N >> X;
	vector<vector<PLL>>G(N);
	FOR(i, 0, N - 1) {
		LL x, y, c; cin >> x >> y >> c;
		x--, y--;
		G[x].push_back(PLL(y, c));
		G[y].push_back(PLL(x, c));
	}
	VL val(N,0);
	map<LL, LL>Map;
	dfs(0, -1, G, 0, Map,val);
	LL ans = 0;
	DD(De(val));
	FOR(i, 0, N) {
		LL fromRoot = val[i];
		auto it = Map.find(fromRoot^X);
		if (it != Map.end()) {
			ans += it->second;
			if (X == 0)ans--; // fromRoot^X == fromRoot
		}
	}
	cout << ans / 2 << endl;

	return 0;
}
