#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i,s,e) for(int (i) = (s) ;(i) < (e) ;(i)++)
#define debug(x) cout << #x << ": " << x << endl
#define ALL(x) (x).begin(),(x).end()

const int INF = 1e9;
const ll LINF = 1e16;

/* -----  2017/06/27  Problem: ICPC国内予選2010 E / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1165&lang=jp  ----- */
/* ------問題------

string dijkstra

-----問題ここまで----- */
/* -----解説等-----

拡張ダイクストラ的なノリで、
無限ループの場合はこれを行うものを検出するために各頂点のノードを拡張して文字数を状態に持てばよい。
300を超えるようなものが存在すれば最短なものは無限に作ることができうるのでこれを検出した場合はNO、
そうでない場合は最小の値が一意に存在することになるのでこれを出力すればいい。

----解説ここまで---- */

string dist[41][360];
vector<pair<int, string>>G[41];


string dijkstra(int s, int t) {
	FOR(i, 0, 41)FOR(j, 0, 360)dist[i][j] = "~";
	dist[s][0] = "";
	using Ty = tuple<string, int, int>;
	priority_queue<Ty, vector<Ty>, greater<Ty>>que;
	que.push(Ty("", 0, s));
	while (!que.empty()) {
		auto q = que.top(); que.pop();
		int len, v; string d;
		tie(d, len, v) = q;

		if (dist[v][len]<d)continue;
		FOR(i, 0, G[v].size()) {

			int nv = G[v][i].first;
			string cost = G[v][i].second;
			string nx = d + cost;
			int nlen = nx.size();
			if (nlen >= 360)continue;
			if (nx< dist[nv][nlen]) {
				dist[nv][nlen] = nx;
				que.push(Ty(nx, nlen, nv));
			}
		}

	}

	string res = "~";
	FOR(i, 0, 360) {
		if (res > dist[t][i]) {
			res = dist[t][i];
			if (i > 300)return "NO";
		}
	}

	if (res == "~")return "NO";
	else return res;
}



int main() {
	//cin.tie(0); ios::sync_with_stdio(false);
	while (1) {
		FOR(i, 0, 41)G[i].clear();
		int N, M, s, t;
		scanf("%d%d%d%d", &N, &M, &s, &t);
		//cin >> N >> M >> s >> t;
		if (N == 0)break;
		bool f = 0;
		FOR(i, 0, M) {
			int a, b;
			string ss;
			scanf("%d%d", &a, &b);
			cin >> ss;
			//scanf("%s", &ss);
			G[a].push_back(make_pair(b, ss));
		}

		string ans = dijkstra(s, t);
		cout << ans << endl;
	}
	return 0;
}