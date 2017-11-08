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

/* -----  2017/11/08  Problem: 056_csacademy C / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

順序関係が、トポロジカル順序であればいので逐次チェックして頑張るとできる。
問題文がクソだった

----解説ここまで---- */

LL N;

LL ans = 0LL;
VVI g, flag, adj;
vector<PII>lis;
int ok = 1;
void dfs(int s,int t,int p) {
	flag[s][t] = 1;
	int v = adj[s][t];


	lis.push_back(PLL(s, v));
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	g=VVI(N, VI());
	adj=VVI(N, VI());
	flag=VVI(N, VI());

	FOR(i, 0, N) {
		int num; cin >> num;
		FOR(j, 0, num) {
			int a; cin >> a;
			adj[i].push_back(a - 1);
			flag[i].push_back(0);
			g[i].push_back(a - 1);
			g[a - 1].push_back(i);
		}
	}
	/*FOR(i, 0, N) {
		FOR(j, 0, SZ(adj[i])) {
			cout << adj[i][j] << " ";
		}cout << endl;
	}*/

	FOR(i, 0, N) {
		FOR(j, 0, SZ(adj[i])) {
			if (flag[i][j] == 0)dfs(i,j,-1);
		}
	}


	if (ok) {
		FOR(i, 0, SZ(lis)) {
			cout << lis[i].first << " "<<lis[i].second << endl;
		}
	}
	else cout << -1 << "\n";

	return 0;
}
