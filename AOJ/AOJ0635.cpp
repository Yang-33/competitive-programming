#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/10/29  Problem:  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0635  ----- */
/* ------問題------

ヘビの JOI 君は，ある大きな屋敷に迷い込んでしまった．屋敷の住人に見つかる前に，屋敷を脱出しなければならない．
この屋敷には部屋が N 個あり，1, 2, ..., N の番号が付けられている．また，廊下が M 本あり，i 本目の廊下 (1 ≦ i ≦ M) は部屋 Ai と部屋 Bi を結んでいる．
JOI 君はこれらの廊下をどちらの向きにも通ることができ，廊下 i を通るのには Di 分かかる．部屋と部屋の間を廊下を通る以外の手段で移動する方法はない．
この屋敷の部屋の温度はそれぞれ一定に調節されており，JOI 君にとって寒すぎるか，快適であるか，暑すぎるかである．
JOI 君は，急な温度変化に対応できないため，最後に寒すぎる部屋を出てから X 分未満のうちに暑すぎる部屋に入ることはできない．
同様に，最後に暑すぎる部屋を出てから X 分未満のうちに寒すぎる部屋に入ることもできない．
JOI 君は，移動中に部屋に入るとすぐに部屋から出なければならない．
また，廊下の途中で引き返したり，廊下 i を Di 分より長い時間かけて通ることもできない．ただし，一度訪れた部屋にもう一度入ることや，一度使った廊下をもう一度使うことは許される．
JOI 君は現在部屋 1 にいる．この部屋は JOI 君にとって寒すぎる．JOI 君は屋敷の出口のある部屋 N に入ると，屋敷から脱出できる．
JOI 君が屋敷から脱出するのにかかる最短の時間を求めよ．

-----問題ここまで----- */
/* -----解説等-----

dist[i][j][k]:= 温度iであとj分温度変化に時間を要するときに頂点kにいるときの最小値
として最短距離をもとめればよい。
当時はpriority_queueではなくqueueで書いていて、は？となった
普通の温度はj==0なので分ける必要はない。

----解説ここまで---- */

using fp = tuple<int, int, ll, int>;
//s,time,dist,ver
ll N, M, X;
int t[10010];
ll d[2][220][10010];
vector<pii>G[10010];
ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> X;
	FOR(i, 0, N) {
		cin >> t[i];
		if (t[i] == 1)t[i] = 2;
		else if (t[i] == 2)t[i] = 1;
	}
	FOR(i, 0, M) {
		int a, b, d;
		cin >> a >> b >> d;
		a--; b--;
		G[a].pb(mp(b, d));
		G[b].pb(mp(a, d));
	}

	FOR(i, 0, 2)FOR(j, 0, 220)FOR(k, 0, 10010)d[i][j][k] = INF;
	d[0][X][0] = 0;
	priority_queue<fp, vector<fp>, greater<fp>>q;
	q.push(fp(0, X, 0, 0));
	// tie(dis, Time, cool or hot, v)
	while (!q.empty()) {
		fp nq = q.top(); q.pop();
		int s, Ti, v; ll dis; tie(dis, Ti, s, v) = nq;
		if (d[s][Ti][v] < dis)continue;

		FOR(i, 0, G[v].size()) {
			ll edge = G[v][i].second;
			int nv = G[v][i].first;

			if (t[nv] != 2 && s != t[nv]) {//さむ<->あつ
				if (Ti - edge <= 0) {//はいれる
					if (d[t[nv]][X][nv] > d[s][Ti][v] + edge) {
						d[t[nv]][X][nv] = d[s][Ti][v] + edge;
						q.push(fp(d[t[nv]][X][nv], X, t[nv], nv));
					}
				}
			}
			else if (t[nv] != 2 && s == t[nv]) {//おんなじ(もどる)
				if (d[t[nv]][X][nv] > d[s][Ti][v] + edge) {
					d[t[nv]][X][nv] = d[s][Ti][v] + edge;
					q.push(fp(d[t[nv]][X][nv], X, t[nv], nv));
				}
			}
			else {//ぬるーい
				if (d[s][max((ll)0, Ti - edge)][nv] > d[s][Ti][v] + edge) {
					d[s][max((ll)0, Ti - edge)][nv] = d[s][Ti][v] + edge;
					q.push(fp(d[s][max((ll)0, Ti - edge)][nv], max((ll)0, Ti - edge), s, nv));
				}
			}
		}
	}

	ans = LINF;
	FOR(i, 0, 2)FOR(j, 0, 220) {
		ans = min(ans, d[i][j][N - 1]);
	}
	cout << ans << endl;

	return 0;
}
