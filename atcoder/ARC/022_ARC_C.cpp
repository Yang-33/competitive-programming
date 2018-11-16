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

/* -----  2018/11/16  Problem: ARC 022 C / Link: http://arc022.contest.atcoder.jp/tasks/arc022_c  ----- */
/* ------問題------

高橋王国には N 個の村があり、1 から N の番号がついています。N−1 組の村の間は道で繋がっていて、どの村と村の間も道をいくつか辿ることによって移動できるようになっています。
高橋王国に住んでいるロミオさんとジュリエット君が引っ越しをすることになりました。2 人はとても仲が悪いので出来るだけ離れた村に引っ越したいと思っています。あなたは、2 人がそれぞれどの村に引っ越せば 2 人の住む村の間の距離が最大になるのかを計算してあげてください。ただし「村の間の距離」とは、片方の村からもう片方の村まで行くために通る必要のある道の本数であるとします。

-----問題ここまで----- */
/* -----解説等-----

貼った　木の直径そのままであるから、O(V)とかをすればよい
解説はおそらく全方位木DPのことを適当な木DPと書いている気がする?
実装したほうが良さそう

----解説ここまで---- */

PLL didfs(int v, int p, const vector<vector<PLL>>&G) {
	PLL ret = PLL(0, v);
	FOR(i, 0, (int)G[v].size()) {
		if (G[v][i].first == p)continue;
		PLL temp = didfs(G[v][i].first, v, G);
		temp.first += G[v][i].second;
		ret = max(ret, temp);
	}
	return ret;
}
PLL diamiter(const vector<vector<PLL>>& G) {
	PLL p = didfs(0, -1, G);
	PLL q = didfs(p.second, -1, G);
	return PLL(p.second, q.second);
}
LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	vector<vector<PLL>>G(N);
	FOR(i, 0, N-1) {
		int a, b; cin >> a >> b;
		a--, b--;
		G[a].push_back(PLL(b, 1));
		G[b].push_back(PLL(a, 1));
	}
	PLL ps = diamiter(G);
	cout << ps.first + 1 << " " << ps.second+1 << endl;

	return 0;
}
