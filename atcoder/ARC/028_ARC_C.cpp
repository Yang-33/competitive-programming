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

/* -----  2018/11/03  Problem: ARC 028 C / Link: http://arc028.contest.atcoder.jp/tasks/arc028_c  ----- */
/* ------問題------

高橋王国は N 個の町からなり、それぞれの町には 0 から N−1 までの番号がついています。また、２つの町を繋ぐ道が N−1 本あり、どの町からどの町へもいくつかの道を使うことで辿り着けるようになっています。
高橋王国の王様である高橋君は、首都にする町を決めようとしています。高橋君は首都を決める参考にするために「バランス値」を計算してみることにしました。町 v を首都としたときの「バランス値」は、町 v を通らずに相互に通行可能である町の集合の最大の大きさです。
例えば、下の図の町 1 を首都とした場合、{町 0, 町 4} や {町 2} や {町 3} などの町の集合において、町 1 を通らずに相互に通行することが可能となっています。そのうち最も大きい集合は {町 0, 町 4} であり、その大きさは 2 であるため、町 1 を首都としたときの「バランス値」は 2 となります。

-----問題ここまで----- */
/* -----解説等-----

根付き木の部分木のサイズを列挙できれば、全方位木DPをしなくても周りの情報が全部わかる。

----解説ここまで---- */


// return sz
int dfs(int v, int p, const VVI &G, VI& ans) {
	int sz = 0;
	for (int nx : G[v]) {
		if (nx == p)continue;
		int ret = dfs(nx, v, G, ans);
		ans[v] = max(ans[v], ret);
		sz += ret;
	}
	sz++;
	ans[v] = max(ans[v], SZ(G) - sz);
	return sz;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	VVI G(N);
	FOR(i, 0, N - 1) {
		int p; cin >> p;
		G[p].push_back(i + 1);
		G[i + 1].push_back(p);
	}
	VI ans(N, 0);

	dfs(0, -1, G, ans);
	FOR(i, 0, N) {
		cout << ans[i] << endl;
	}

	return 0;
}