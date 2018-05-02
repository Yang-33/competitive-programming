#include <bits/stdc++.h>
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

/* -----  2018/05/02  Problem: AOJ 1236 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1236  ----- */
/* ------問題------

グラフの順回路が与えられる。グラフを復元せよ。ルールは以下
A:はじめて訪れた頂点はその頂点の入次数が正の値で示される。
B:一度訪れた頂点に来たときは、今の深さ-その頂点の深さが与えられる。ただし負の値

-----問題ここまで----- */
/* -----解説等-----

一意に定まるグラフなので、これは頑張る

----解説ここまで---- */

int v = 0;
void dfs(int& id, int dep, const VI& a, VI& deg, VVI& res,VI& dv) {
	deg[v] += a[id];
	dv[dep] = v;

	int nv = v++;
	//cout << v << "," << nv << "," << id << endl;
	while (id < SZ(a) && deg[nv] > 0) {
		int val = a[++id];
		if (val > 0) {
			deg[nv]--; deg[v]--;
			res[nv].emplace_back(v);
			res[v].emplace_back(nv);
			dfs(id, dep + 1, a, deg, res,dv);
		}
		else {
			int u = dv[dep + val];
			deg[u]--; deg[nv]--;
			res[u].emplace_back(nv);
			res[nv].emplace_back(u);
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	int Case;
	cin >> Case;
	FOR(kim, 0, Case) {
		int val, N = 0;
		VI a;
		while (cin >> val, val) {
			if (val > 0)N++;
			a.push_back(val);
		}
		v = 0;
		VI deg(N, 0);
		VVI res(N, VI());
		VI dv(N);
		int id = 0;
		dfs(id, 0, a, deg, res,dv);

		//debug(v);
		FOR(i, 0, N) {
			cout << i + 1;
			SORT(res[i]);
			
			FOR(k, 0, SZ(res[i])) {
				cout << " " << res[i][k] + 1;
			}
			cout << "\n";
		}

	}

	return 0;
}
