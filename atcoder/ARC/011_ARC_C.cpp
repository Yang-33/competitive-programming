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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/12/14  Problem: ARC 011 C / Link: http://arc011.contest.atcoder.jp/tasks/arc011_c  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

経路復元するだけ

----解説ここまで---- */

#define DijkV 200020
long long  dist[DijkV];
vector<int> Dijkstra(vector<vector<PLL>>& G, int s, int t) {

	const int INF = INT_MAX;
	const long long INIT_NUM = LLONG_MAX / 10;

	FOR(i, 0, DijkV)dist[i] = INIT_NUM;

	dist[s] = 0;
	priority_queue<PLL, vector<PLL>, greater<PLL>> que;
	que.push(PLL(0LL, s));

	while (!que.empty()) {
		PLL p = que.top(); que.pop();
		int v; /* 頂点*/ long long d; /* 頂点vまでの距離 */
		tie(d, v) = p;

		if (d > dist[v]) continue;

		FOR(i, 0, (int)G[v].size()) {
			int nv = G[v][i].first;
			if (dist[nv] > dist[v] + G[v][i].second) {
				dist[nv] = dist[v] + G[v][i].second;
				que.push(PLL(dist[nv], nv));
			}
		}
	}
	if (dist[t] == INIT_NUM)return VI();
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

#undef DijkV
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	long long int N, M, K, H, W, L, R;
	string s, t;
	cin >> s >> t;
	cin >> N;
	vector<string>v(N + 2);
	FOR(i, 1, N + 1) {
		cin >> v[i];
	}
	if (s == t) {
		cout << 0 << endl;
		cout << s << endl;
		cout << t << endl;
		return 0;
	}
	N += 2;
	v[0] = s;
	v[N - 1] = t;

	auto f = [&v](int a,int b) {
		string &s = v[a], &t = v[b];
		int diff = 0;
		FOR(i, 0, SZ(s)) {
			diff += !!(s[i] != t[i]);
		}
		return diff;
	};
	vector<vector<PLL>>G(N);
	FOR(i, 0, N) {
		FOR(j, i + 1, N) {
			int diff = f(i, j);
			if (diff == 1) {
				G[i].push_back(PLL(j, 1));
				G[j].push_back(PLL(i, 1));
			}
		}
	}
	auto res = Dijkstra(G, 0, N - 1);
	if (SZ(res)) {
		cout << SZ(res) - 2 << endl;
		reverse(ALL(res));
		for (int i : res) {
			cout << v[i] << endl;
		}
	}
	else {
		cout << -1 << endl;
	}


	return 0;
}