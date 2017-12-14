#include "bits/stdc++.h"
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

/* -----  2017/10/11  Problem: 52_csacademy C  / Link:   ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

LL N, K;

LL ans = 0LL;
vector<vector<PLL>>G;
int Node[100005];
VI delv;
void dfs(int v, int p) {
	FOR(i, 0, SZ(G[v])) {
		if (G[v][i].first == p)continue;
		dfs(G[v][i].first, v);
		Node[v] += Node[G[v][i].first];
	}
	Node[v]++;
}

void dl_make(int v, int p) {
	FOR(i, 0, SZ(G[v])) {
		if (G[v][i].first == p)continue;
		if (G[v][i].second == 1)delv.push_back(Node[G[v][i].first]);
		else dl_make(G[v][i].first, v);
	}
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	G = vector<vector<PLL>>(N + 3, vector<PLL>());
	FOR(i, 0, N - 1) {
		LL a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		G[a].push_back(PLL(b, c));
		G[b].push_back(PLL(a, c));
	}
	dfs(0, -1);
	dl_make(0, -1);

	if (N <= K) { cout << 0 << endl; return 0; }
	RSORT(delv);
	FOR(i, 0, SZ(delv)) {
		N -= delv[i];
		if (N <= K) { cout << i + 1 << endl; return 0; }
	}

	cout << -1 << "\n";

	return 0;
}