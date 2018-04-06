#include <bits/stdc++.h>
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

/* -----  2018/04/06  Problem: yukicoder 001  / Link: http://yukicoder.me/problems/no/001  ----- */
/* ------問題------

N個の町があります。それぞれ1…Nと番号がふられています。
それぞれの街は直接、道でつながっているものもあれば、つながってないものがあります。
それぞれの道は　町Siから町Tiに行くのに Yiのコスト（お金：円）がかかり、Mi 単位時間 かかります。

あなたは 1 の町にいます。
N の都市に行きたいと思っています。
何個道や町を経由してもいいですが、あなたは今C円しか持っていません。

（つまり、通った道のコスト Yi の合計がC以下にしないといけない。）

その中で一番早く付く道を選べた時、合計の単位時間を答えてください。
この制約の中で辿りつけない場合 −1を返してください。

-----問題ここまで----- */
/* -----解説等-----

拡張ダイクストラの類の問題。
次の頂点に移動する場合に同じ距離に対しても別のコストが存在する可能性がある。
このようなときは頂点をコストの種類だけ持つようにしてあげれば複数の状態の頂点をもつことができる。
これは dist[ 現在使用したコストの総和 ][ いまいる頂点 ]:= 今いる頂点で使用したコストがcであるときの最短距離(時間)
として遷移してあげればよい。


----解説ここまで---- */

LL N,C,V;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> C>>V;
	VI s(V), t(V), y(V), m(V);

	FOR(i, 0, V) {
		cin >> s[i]; s[i]--;
	}
	FOR(i, 0, V) {
		cin >> t[i]; t[i]--;
	}
	FOR(i, 0, V) {
		cin >> y[i];
	}
	FOR(i, 0, V) {
		cin >> m[i];
	}
	// sum m[i]を最小化　成約はC
	using tp = tuple<int, int, int>;
	vector<vector< tp >> G(N);
	FOR(i, 0, V) {
		G[s[i]].push_back(tp(t[i], y[i], m[i]));
	}
	VVI dist(N, VI(C+1, INF));
	dist[0][0] = 0;
	priority_queue<tp,vector<tp>,greater<tp>> pq;
	pq.push(tp(0,0,0)); // d,c,v
	while (!pq.empty()) {
		tp a = pq.top(); pq.pop();
		int d, c, v; tie(d, c, v) = a;
		if (dist[v][c] < d)continue;
		FOR(i, 0, SZ(G[v])) {
			int nv, adc, adt;
			tie(nv, adc, adt) = G[v][i]; // nv,y,m
			if (adc + c > C)continue;
			if (dist[nv][adc + c] > dist[v][c] + adt) {
				dist[nv][adc + c] = dist[v][c] + adt;
				pq.push(tp(dist[nv][adc+c] , adc+c, nv));
			}
		}
	}
	ans = INF;
	FOR(i, 0, C + 1) {
		ans = min(ans, (LL)dist[N - 1][i]);
	}
	
	cout << (ans== INF? -1:ans) << "\n";

	return 0;
}
