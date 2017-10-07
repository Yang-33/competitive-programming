#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const double PI = acos(-1.0);
ll dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
ll dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/05/13  Problem: ABC 061 D / Link: http://abc061.contest.atcoder.jp/tasks/abc061_d  ----- */
/* ------問題------

N 頂点 M 辺の重み付き有向グラフがあります。
i(1≦i≦M) 番目の辺は 頂点 ai から 頂点 bi を重み ci で結びます。
このグラフと駒を利用して、次の1人ゲームを行います。

最初、駒を頂点 1 に置いて、プレイヤーのスコアを 0 とします。
プレイヤーは、次の条件で駒を繰り返し移動させることができます。

頂点 ai に駒があるとき、i 番目の辺を利用して頂点 bi に移動する。移動後にプレイヤーのスコアが ci 加算される。
頂点 N に駒があるときのみ、ゲームを終了できます。
なお、与えられる有向グラフの上で頂点 1 から頂点 N に移動できることは保障されています。

プレイヤーがゲーム終了時のスコアを出来るだけ大きくするような行動を取ったとき、ゲーム終了時のスコアはいくつになるでしょうか?
ゲーム終了時のスコアをいくらでも大きくできる場合は inf と出力してください。

-----問題ここまで----- */
/* -----解説等-----

ベルマンフォードっぽいことを考えると、もう一回同じ要領で最大経路を作成した場合に一意に決まらなければこれは無限にできることになる。
したがって0からの最大化を2回やればその判定ができる。

----解説ここまで---- */

ll N, M;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	vector<vector<pll>>G = vector<vector<pll>>(N, vector<pll>());
	FOR(i, 0, M) {
		int a, b, c; cin >> a >> b >> c;
		a--;
		b--;
		G[a].push_back({ b,c });
	}
	ll INF = 1e18;
	vector<ll>dist1(N, -INF);
	vector<ll>dist2;
	dist1[0] = 0;
	FOR(i, 0, N + 1) {
		FOR(j, 0, N) {
			FOR(k, 0, (int)G[j].size()) {
				dist1[G[j][k].first] = max(dist1[G[j][k].first], dist1[j] + G[j][k].second);
			}
		}
	}

	dist2 = dist1;
	FOR(i, 0, N + 1) {
		FOR(j, 0, N) {
			FOR(k, 0, (int)G[j].size()) {
				dist2[G[j][k].first] = max(dist2[G[j][k].first], dist2[j] + G[j][k].second);
			}
		}
	}

	if (dist1[N - 1] != dist2[N - 1]) {
		cout << "inf" << endl;
	}
	else {
		cout << dist1[N - 1] << endl;
	}

	return 0;
}
