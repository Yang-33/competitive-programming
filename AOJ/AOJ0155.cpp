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

/* -----  2018/06/15  Problem: AOJ 0155 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0155  ----- */
/* ------問題------

正義のヒーロー「スパイダー人」は、腕からロープを出してビルからビルへ飛び移ることができます。
しかし、ロープが短いので自分からの距離が 50 以下のビルにしか移動できません。
それより遠くのビルに移動するには、一旦別のビルに飛び移らなくてはなりません。
ビルの数 n、n 個のビルの情報、スパイダー人の移動開始位置及び目的地を入力とし、
その移動の最短経路を出力するプログラムを作成してください。
どのようにビルを経由しても目標のビルに移動できない場合は NA と出力してください。
各ビルは点として扱い、最短距離で移動するビルの経由方法が２つ以上存在することはないものとします。

-----問題ここまで----- */
/* -----解説等-----

グラフを自分で作って経路復元をすれば良い。pathなしに注意する。

----解説ここまで---- */

vector<int> Dijkstra(const vector<vector<pair<int,double>>>& G, int s, int t) {
	swap(s, t);
	vector<double> dist(SZ(G), INF);
	dist[s] = 0; // 頂点sを0で初期化
	using T = pair<double, int>;
	priority_queue<T, vector<T>, greater<T>> que; //優先度付きqueue 降順(距離、頂点)
	que.push(T(0LL, s)); // push(距離,頂点)

	while (!que.empty()) {
		T p = que.top(); que.pop(); //queueのデータ構造
		int v; /* 頂点*/ double d; /* 頂点vまでの距離 */
		tie(d, v) = p;

		if (d > dist[v]) continue; //最適でないならば考慮しない

		FOR(i, 0, (int)G[v].size()) { //頂点vからはi本の辺が存在
			int nv = G[v][i].first; // v->nv
			if (dist[nv] > dist[v] + G[v][i].second) {
				dist[nv] = dist[v] + G[v][i].second;
				que.push(T(dist[nv], nv)); //push(距離,頂点) 
			}
		}
	}
	if (dist[t] >= INF)return VI({ INF });

	int cur = t;
	vector<int >path{ t };
	while (cur != s) {
		int nx_v = INF;
		FOR(i, 0, (int)G[cur].size()) {
			if (dist[cur] == dist[G[cur][i].first] + G[cur][i].second) {
				nx_v = min(nx_v, (int)G[cur][i].first);
			}
		}
		cur = nx_v;
		path.push_back(cur);
	}
	return path;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	while (cin >> N, N) {
		using tp = tuple<int, int, int>;
		vector<tp>pos;
		FOR(i, 0, N) {
			int b, x, y;
			cin >> b >> x >> y;
			b--;
			pos.push_back(tp(b, y, x));
		}
		SORT(pos);
		vector<vector<pair<int, double>>>G(N);
		FOR(i, 0, N) {
			int y, x;
			tie(ignore, y, x) = pos[i];
			FOR(j, i + 1, N) {
				int yy, xx;
				tie(ignore, yy, xx) = pos[j];
				double dist = sqrt((x - xx)*(x - xx) + (y - yy)*(y - yy));
				if (dist <= 50) {
					G[i].push_back(pair<int, double>(j, dist));
					G[j].push_back(pair<int, double>(i, dist));
				}
			}
		}
		int Q;
		cin >> Q;
		FOR(q, 0, Q) {
			int s, t; cin >> s >> t;
			s--, t--;
			VI path = Dijkstra(G, s, t);
			if (path.size() && path[0] == INF) {
				cout << "NA" << endl;
			}
			else {
				FOR(i, 0, SZ(path)) {
					cout << path[i]+1 << " \n"[i==SZ(path)-1];
				}
			}
		}
	}
	return 0;
}
