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

/* -----  2018/06/15  Problem: AOJ 1162 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1162  ----- */
/* ------問題------

摩擦のない国での自動車旅行を考える． この国の自動車にはエンジンがない． ある速さで動き出したら，その速さをずっと維持する（摩擦がないから）． 道路上の固定設備として加減速装置が設置してあって， ここを通る時に速さを1だけ増やしたり，減らしたりすることができる． 速さを変えないことも可能である． このような世界で，出発地から目的地まで最短の時間で移動するルートを決定するプログラムを書くことがあなたの仕事である．
この国には複数の都市があり，それらの間を結ぶ道路網が整備されている． 加減速装置はそれぞれの都市に設置してある． 上に述べたとおり，ある都市に速さv で到着した場合，その都市から次の都市に移動する時の速さはv - 1，v ，v + 1 のいずれかである． 出発地を出た直後の道路を走る速さは1に限られる． 同様に目的地に到着する直前の道路を走る速さも1でなければならない．
出発地と目的地（それぞれ都市である）が与えられる． いくつかの都市を経由しながら目的地に到達する最善のルートを求めることが問題である． ある都市に到着した直後に，今来たばかりの道路を引き返すことはできない（Uターン禁止）． この制限を除けば，経路の選び方は自由である． 同じ都市や同じ道路を何度も通ってよいし，出発地や目的地を途中で通過してもかまわない．
都市と都市を結ぶ道路のそれぞれに対して，その距離と制限速度が与えられる． その道路を走る時の速さは制限速度以下でなければならない． 道路を通り抜ける所要時間は，距離÷速さである． 都市の通過や加減速に要する時間は無視する．

-----問題ここまで----- */
/* -----解説等-----

最短路上で区別したいのは現在の速度とどこからきたのかの情報なので、これをもてばよい。

----解説ここまで---- */

vector<pair<int, pair<double, double>>>G[40];
double d[40][40][40];


void dijkstra(int s) {
	d[s][1][35] = 0;
	using Ty = tuple<double, int, int, int>;
	priority_queue<Ty, vector<Ty>, greater<Ty>>q;

	FOR(i, 0, G[s].size()) {
		pair<int, PII>b = G[s][i];
		int nv = b.first;
		double cost = b.second.first;
		double lim = b.second.second;

		int nsokudo = 1;
		if (nsokudo<1 || nsokudo>lim)continue;
		double cc = cost / (double)nsokudo;
		if (d[nv][nsokudo][s] > d[s][1][35] + cc) {
			d[nv][nsokudo][s] = d[s][1][35] + cc;
			q.push(Ty(d[nv][nsokudo][s], nsokudo, nv, s));

		}
	}

	while (!q.empty()) {
		Ty a = q.top(); q.pop();
		double dist; int sokudo, v, bef;
		tie(dist, sokudo, v, bef) = a;
		if (d[v][sokudo][bef] < dist)continue;

		FOR(i, 0, G[v].size()) {
			pair<int, PII>b = G[v][i];
			int nv = b.first;
			double cost = b.second.first;
			double lim = b.second.second;
			if (bef == nv)continue;

			FOR(j, -1, 2) {
				int nsokudo = sokudo + j;
				if (nsokudo<1 || nsokudo>lim)continue;
				double cc = cost / (double)nsokudo;
				if (d[nv][nsokudo][v] > d[v][sokudo][bef] + cc) {
					d[nv][nsokudo][v] = d[v][sokudo][bef] + cc;
					q.push(Ty(d[nv][nsokudo][v], nsokudo, nv, v));

				}
			}
		}
	}
}


int main() {
	//cin.tie(0); ios::sync_with_stdio(false);

	while (true) {
		FOR(i, 0, 40)G[i].clear();
		FOR(i, 0, 40)FOR(j, 0, 40)FOR(k, 0, 40)d[i][j][k] = LINF;
		//init


		int N, M; cin >> N >> M;
		if (N == 0 && M == 0)break;
		int  start, target; cin >> start >> target;
		start--; target--;
		FOR(i, 0, M) {
			int x, y; double d, c;
			cin >> x >> y >> d >> c;
			x--; y--;
			G[x].push_back(make_pair(y, make_pair(d, c)));
			G[y].push_back(make_pair(x, make_pair(d, c)));
		}

		dijkstra(start);
		double ans = LINF;
		FOR(i, 0, N) {
			ans = min(ans, d[target][1][i]);
		}
		if (ans >= LINF - 10) {
			cout << "unreachable" << endl;
		}
		else {
			printf("%.10lf\n", ans);
		}

	}
	return 0;
}