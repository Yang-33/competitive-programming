#include "bits/stdc++.h"
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

/* -----  2017/10/23  Problem: nu_4  / Link: http://joi2007ho.contest.atcoder.jp/tasks/joi2007ho_d  ----- */
/* ------問題------

あなたは JOI 新聞社の記者であり，スポーツ記事を担当している．
昨日までに，クロアチアでは，n 個のサッカーチームによる総当りのリーグ戦が行われた．大会実行委員会は，試合結果と規定に基づき各チームに 1 位から n 位までの順位をつけたようである．あなたには，一部の試合の勝敗とともに，次の情報が伝えられた．
情報 1 引き分けの試合はなかった．
情報 2 全てのチームに異なる順位がついた．
情報 3 全ての 1 ≤ a < b ≤ n に対し，a 位のチームと b 位のチームの試合において，必ず a 位のチームが勝利した．
あなたは記事を作成するために，一部の試合の勝敗と，伝えられた情報 1 3 をもとに，順位表を推測することにした．
入力として一部の試合の勝敗が与えられたとき，伝えられた情報に適合する順位表を 1 つ出力するプログラムを作れ．また，出力した順位表以外に，伝えられた情報に適合する順位表が存在するかどうかも判定せよ．
ここで，順位表とは 1 位から n 位の順にチームを並べたもののことをいう．

-----問題ここまで----- */
/* -----解説等-----

順序関係がわかると順位もわかりうれしくなる。
順序関係はグラフで表現可能で、これは勝った人が負けた人に有向辺を張ればよい。
あとはこれが一意に定まるかどうかを確認すればよい。

----解説ここまで---- */

template<typename T>
vector<T> tsort(const vector<vector<T>> &g) {
	int n = (int)g.size(), k = 0;
	vector<T> ord(n, 0), in(n, 0);
	for (int i = 0; i < (int)g.size(); i++)
		for (int j = 0; j < (int)g[i].size(); j++)
			in[g[i][j]]++;

	queue<T> q;
	for (int i = 0; i < n; ++i)
		if (in[i] == 0) q.push(i);

	while (q.size()) {
		int v = q.front(); q.pop();
		ord[k++] = v;
		for (int i = 0; i < (int)g[v].size(); i++)
			if (--in[g[v][i]] == 0) q.push(g[v][i]);
	}
	return *max_element(in.begin(), in.end()) == 0 ? ord : vector<int>();
}
LL N, M;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	VVI G = VVI(N, VI());
	FOR(i, 0, M) {
		int a, b;
		cin >> a >> b; a--; b--;
		G[a].push_back(b);
	}
	VI ord = tsort<int>(G);
	FOR(i, 0, N) {
		cout << ord[i] + 1 << endl;
	}
	int not_uniq = 0;
	FOR(i, 0, N - 1) {
		int f = 1;
		FOR(j, 0, SZ(G[ord[i]])) {
			if (G[ord[i]][j] == ord[i + 1])f = 0;
		}
		if (f == 1) { not_uniq = 1; }
	}

	cout << not_uniq << "\n";

	return 0;
}