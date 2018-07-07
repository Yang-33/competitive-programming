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

/* -----  2018/07/07  Problem: AOJ 2885 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2885  ----- */
/* ------問題------

太郎さんと花子さんと次郎さんは3人で JAG 王国を統治している．JAG 王国には N 個の街が存在し，いくつかの街は双方向の道路で繋がっている．どの街からも別のすべての街へ 1 本以上の道路を経由して必ず辿り着くことができる．
ある日太郎さんと花子さんはとうとう仲違いを起こしてしまい，3 人で街を分担して統治することに決めた．しかし，あまりにも仲が悪くなりすぎてしまったため，太郎さんが統治している街と花子さんが統治している街が 1 本の道路で直接繋がっていることすら嫌がっている．そこで，以下の条件を満たすように統治する街を分担することにした．
太郎さんが統治する街と花子さんが統治する街からなる任意のペアは，直接道路で繋がっていない．これは太郎さんと花子さんの仲がめちゃくちゃ悪いからである．
同じ人に統治されている街同士も直接道路で繋がっていない．これは，そんな中でも他者の統治下の経由を義務付けることで外交を促すためである．
太郎さんの統治する街の総数と花子さんが統治する街の総数は同じでなければならない．これは総数を等しくしないと太郎さんと花子さんの仲がさらにめちゃくちゃ悪くなりそうだからである．ここで，次郎さんはとても心が広いので，次郎さんが統治する街の総数はいくつでもよい．
以上の条件を満たすような分担であれば，3 人は納得して統治することができ，たとえ誰かの統治する街が 0 個であっても文句はない．このとき，太郎さんが統治する街の総数 (=花子さんが統治する街の総数) としてあり得る数をすべて列挙するプログラムを作成せよ．

-----問題ここまで----- */
/* -----解説等-----

二部グラフじゃないときは題意をみたさない
おしまい

----解説ここまで---- */

std::vector<int> isBipartiteGraph(const std::vector<std::vector<int>>& g) {
	int n = g.size();
	std::vector<int> res(n, -1);
	std::queue<int> que;
	que.push(0);
	res[0] = 0;
	while (!que.empty()) {
		int now = que.front(); que.pop();
		for (auto to : g[now]) {
			if (res[to] != -1) {
				if (res[now] == res[to]) {
					return std::vector<int>();
				}
			}
			else {
				res[to] = res[now] ^ 1;
				que.push(to);
			}
		}
	}
	return res;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M;
	int Case = 1;
	while (cin >> N >> M, N) {
		VVI G(N);
		FOR(i, 0, M) {
			int a, b;
			cin >> a >> b;
			a--, b--;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		VI res = isBipartiteGraph(G);
		if (res.size()) {
			int sum = accumulate(ALL(res), 0LL);
			set<int>se;
			if (sum % 2 == 0) {
				se.insert(sum / 2);
			}
			if ((N - sum) % 2 == 0) {
				se.insert((N - sum) / 2);
			}

			cout << SZ(se) << endl;
			for (auto i : se) {
				cout << i << endl;
			}
		}
		else {
			cout << 0 << endl;
		}
	}

	return 0;
}
