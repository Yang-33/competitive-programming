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

/* -----  2018/07/23  Problem: AOJ 0117 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0117  ----- */
/* ------問題------

ある日、殿様は一人の大工に、「台風や地震が来たときに町人が避難できる、頑丈で大きな建物を造りなさい。」と命じました。しかし、その頑丈で大きな建物を完成させるには、大きな太い柱が必要です。町にそんな大きな柱はありません。そこで、大工は遠くの山里まで大きな柱を調達しに行くことになりました（大工は町から里山に行って、町に戻ってくる必要があります）。
大工の褒美は、殿様から受け取ったお金から柱の代金と交通費を差し引いた余りです。下の地図のように、山里に行くには、いろいろな町を通るたくさんの街道があり、2つの町をつなぐ街道はそれぞれ交通費が違います。大工の褒美を最大にするにはどのように街道をたどり調達すればよいでしょうか。最大となる大工の褒美を出力するプログラムを作成してください。ただし、町の数を n とすれば、各町は 1 から n までの整数で識別されます。2 つの町を直接つなぐ街道は 2 本以上ありません。

-----問題ここまで----- */
/* -----解説等-----

WF

----解説ここまで---- */


int main() {

	int N, M; cin >> N >> M;
	VVI dist(N, VI(N, INF));
	FOR(i, 0, N)dist[i][i] = 0;
	FOR(i, 0, M) {
		int a, b, c, d;
		scanf("%d,%d,%d,%d,", &a, &b, &c, &d);
		a--, b--;
		dist[a][b] = min(dist[a][b], c);
		dist[b][a] = min(dist[b][a], d);
	}
	FOR(k, 0, N)FOR(i, 0, N)FOR(j, 0, N)dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	int s, g, v, p;
	scanf("%d,%d,%d,%d,", &s, &g, &v, &p);
	s--, g--;
	LL ans = v - dist[s][g] - dist[g][s] - p;
	
	cout << ans << "\n";

	return 0;
}
