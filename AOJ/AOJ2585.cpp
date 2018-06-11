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

/* -----  2018/06/10  Problem: AOJ 2585 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2585  ----- */
/* ------問題------

某国に住む大学生D氏は，国民的ギタリストA氏の大ファンで，この夏都心で行われるライブに行こうと考えている． しかし，D氏は辺境の地に住んでいるため，交通費がかかることがとても不安だった． そんなとき彼は，JAGという組織から安価で販売されている「1Dayパスポート」の存在を知った．
JAG (Journey Administrative Group) は，D氏が住む国に存在するいくつかの鉄道会社を統括する組織である． JAGは，全国に複数の駅を持ち，それらの間を結ぶ路線を整備している． 各路線は，JAGに所属する会社の内いずれか1社により管理されており，2駅間を途中駅無しで双方向に結んでいる． また各路線には，利用する際の運賃と所要時間が定まっている (これらはどちら向きに移動する場合でも等しい)． JAGのダイヤはシンプルに作られており，列車は毎時0分に駅に発着する． またJAGの各駅は，極めて賢くデザインされており，路線の乗り換えにかかる時間は無視することができる． 移動に必要な交通費は運賃の単純な合計となる.
1Dayパスポートは，JAGが昨今の経営難を脱するために販売し始めた，乗り放題パスポートである． JAGは，何種類かの1Dayパスポートを販売している． 各パスポートは，JAGが指定する販売価格で購入することができる． またパスポートには，JAGに所属する会社名がいくつか書かれており，これらの会社が管理する全ての路線が1日間 (追加料金無しで) 乗り放題になる． パスポートは，いくつでも購入することができ，複数のパスポートを併用することができる． ただし，パスポートに書かれていない会社の管理路線を通る場合，その路線の運賃は通常通り必要となる．
D氏は，1Dayパスポートをうまく使い，なるべくお金をかけずライブ会場まで行きたいと考えている． また，彼は宿泊で余計にお金をかけるのが嫌なので，この国の1日であるHH時間以下でライブ会場まで辿り着きたいと考えている． しかし，彼は計算が得意ではないため，同じ大学の友人でプログラミングが得意なあなたに助けを求めて来た． 困っているD氏のために，次のようなプログラムを書いてあげよう．
JAGの路線情報と1Dayパスポートの情報が与えられたとき，D氏の最寄り駅からライブ会場の最寄り駅へ，HH時間以下で移動するための最小費用 (パスポート代と運賃の合計の最小) を求めるプログラムを作成せよ． HH時間以下で到達できない場合や，ライブ会場へ到達する経路がない場合は，-1を出力せよ．

-----問題ここまで----- */
/* -----解説等-----

拡張ダイクストラをやる。
dist[node][hour]:=cost
みたいなかんじでやるとうれしい。
パスポートはまとめていくのがよいのでまとめる。
まとめる際にはbit列で管理をする。今回はこのbitが少ないもの、すなわちパスポートの適用される会社がなくてもパスポートが安い可能性があるので、
bitがよりたっていないモノにも最小値をとらせる。
またこれらのパスポートを用いて新たな合成パスポートをmergeしてつくっておくとよい。

bitで部分集合を扱うやつを思い出した(wikiにもまとめた)

----解説ここまで---- */

LL N, M, H, K;//駅(100)　路線(500)　Hmax(24) 会社の数(8)

LL ans = 0LL;
LL dist[102][1 << 8][25]; //おねだん
LL pass[1 << 8];
using Ty = tuple<int, int, int, int>;

// bitmask 1 のときのコストは0
void dijkstra(vector<vector<Ty>>&g, int s, int bitk) {
	using D = tuple<int, int, int>;
	priority_queue<D, vector<D>, greater<D>>q;
	q.push(D(0, s, 0));
	dist[s][bitk][0] = 0; // node,bitk,hour ->cost
	int cost, v, hour;
	int nv, c, h, r;
	int nc, nh;
	while (!q.empty()) {
		tie(cost, v, hour) = q.top(); q.pop();
		if (dist[v][bitk][hour] < cost)continue;
		FOR(i, 0, SZ(g[v])) {
			tie(nv, c, h, r) = g[v][i];
			nc = (bitk&(1 << r) ? 0 : c);
			nh = hour + h;
			if (nh > H)continue;
			if (dist[nv][bitk][nh] > dist[v][bitk][hour] + nc) {
				dist[nv][bitk][nh] = dist[v][bitk][hour] + nc;
				q.push(D(dist[nv][bitk][nh], nv, nh));
			}
		}
	}
}

int main() {

	while (scanf("%lld%lld%lld%lld", &N, &M, &H, &K), N) {
		int a, b, c, h, r;
		vector<vector<Ty>> g(N);
		FOR(i, 0, M) {
			scanf("%d%d%d%d%d", &a, &b, &c, &h, &r);
			a--; b--; r--;
			// a-b cost, dist, 会社
			g[a].push_back(Ty(b, c, h, r));
			g[b].push_back(Ty(a, c, h, r));
		}
		int S, T, P;
		scanf("%d%d%d", &S, &T, &P);
		S--; T--;
		fill(pass, pass + (1 << 8), LINF);
		pass[0] = 0;
		FOR(i, 0, P) {
			int l; LL d;
			scanf("%d%lld", &l, &d);// パスポートの会社の数, 料金
			int idx = 0;   int k;
			FOR(j, 0, l) {
				scanf("%d", &k);//会社
				k--;
				idx |= 1 << k;
			}
			pass[idx] = min(pass[idx], d);
			for (int y = 0; ; y = (y - idx)&idx) {
				pass[y] = min(pass[y], d);
				if (y == idx)break;
			}
		}
		FOR(k, 0, 1 << K) {//merge
			for (int y = 0; ; y = (y - k)&k) {
				pass[k] = min(pass[k], pass[y] + pass[k^y]);
				if (y == k)break;
			}
		}
		fill(**dist, **dist + 102 * 25 * (1 << 8), LINF);
		FOR(i, 0, 1 << K) {
			dijkstra(g, S, i);
		}

		ans = LINF;
		FOR(k, 0, 1 << K) {
			FOR(t, 0, H + 1) {
				ans = min(ans, dist[T][k][t] + pass[k]);
			}
		}

		if (ans >= LINF)ans = -1;

		printf("%lld\n", ans);
	}

	return 0;
}