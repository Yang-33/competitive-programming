#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i,s,e) for(int (i) = (s); (i) < (e); (i)++)
#define debug(x) cout  << #x << ": " << x << endl
#define ALL(x) (x).begin(),(x).end()
#define mp(x,y) make_pair(x,y)


const int INF = 1e9;
const double LINF = 1e16;

/* -----  2017/06/27  Problem: ICPC国内予選2009E / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1162&lang=jp  ----- */
/* ------問題------

長い。みて

-----問題ここまで----- */
/* -----解説等-----

拡張ダイクストラで解く。
状態には前の頂点と速度を持たせる。
d[ 現在の頂点 ][ 現在の速度 ][ 現在頂点に到達する前の頂点 ]:= この状態に到達する際の最小値
として、d[ N-1 ][ 1 ][ i ]をうちの最小値をとればよい。
初めの遷移は1で固定なのに注意。

----解説ここまで---- */

vector<pair<int, pair<double, double>>>G[40];
double d[40][40][40];


void dijkstra(int s) {
	d[s][1][35] = 0;
	using Ty = tuple<double, int, int, int>;
	priority_queue<Ty, vector<Ty>, greater<Ty>>q;

	FOR(i, 0, G[s].size()) {
		pair<int, pii>b = G[s][i];
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
			pair<int, pii>b = G[v][i];
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
					q.push(Ty(d[nv][nsokudo][v], nsokudo, nv,v));

				}
			}
		}
	}
}


int main() {
	//cin.tie(0); ios::sync_with_stdio(false);

	while (true) {
		FOR(i, 0, 40)G[i].clear();
		FOR(i, 0, 40)FOR(j, 0, 40)FOR(k,0,40)d[i][j][k] = LINF;
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
			ans = min(ans,d[target][1][i]);
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