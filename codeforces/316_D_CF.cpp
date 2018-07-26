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

/* -----  2018/07/26  Problem: 316_D_CF / Link: http://codeforces.com/contest/570/problem/D  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */


VVI G;
vector<vector<PII>>Query;
short int  col[500005];
int dep[500005];
int sz[500005];
int heavy[500005];
bool ans[500005];
map<int, short int> onecnt[500005];
map<int, int>Map[500005]; // v, alpha, dep, cnt

void make_info(int v = 1, int p = 0) {
	sz[v] = 1;
	dep[v] = dep[p] + 1;
	for (int nx : G[v]) {
		if (nx == p)continue;
		make_info(nx, v);
		sz[v] += sz[nx];
		if (heavy[v] == 0 || sz[nx] > sz[heavy[v]]) {
			heavy[v] = nx;
		}
	}
}

// bitmaskでよさそう
// あー

// O(logN)にする
// Mapの変化でalphabetの偶奇が変化したときにonecntが変化するのでこれを検出して増減をみる
void add(int TOP, int cl, int de, int x) {
	int bef = Map[TOP][de];// 1001001001
	if (x % 2 == 1) {
		int addval = 1 << cl;
		if (bef&addval) {// 1->0
			Map[TOP][de] -= addval;
			onecnt[TOP][de]--;
		}
		else { // 0->1
			Map[TOP][de] += addval;
			onecnt[TOP][de]++;
		}
	}
}

void dfs(int v, int p, int TOP) {
	if (heavy[v]) {
		dfs(heavy[v], v, TOP);
	}
	add(TOP, col[v], dep[v], 1);// put
	for (int nx : G[v]) {// light add & merge
		if (nx == p || nx == heavy[v])continue;
		dfs(nx, v, nx);
		for (const auto&it : Map[nx]) {
			FOR(i, 0, 26) {
				if (it.second & 1 << i)
					add(TOP, i, it.first, 1);
			}
		}
	}
	// queryがあれば、ansにぶちこむ

	for (const auto& it : Query[v]) {
		ans[it.second] = onecnt[TOP][it.first] <= 1;
		//it.first:depなのでvのtopにおける情報をもってくる 
	}

}


char ch[500005];

int main() {


	int N, Q;
	scanf("%d%d", &N, &Q);
	G = VVI(N + 1);
	FOR(i, 2, N + 1) {
		int p; scanf("%d", &p);
		G[p].push_back(i);
		G[i].push_back(p);
	}
	scanf("%s", ch);
	FOR(i, 1, N + 1) {
		col[i] = ch[i-1] - 'a';
	}
	Query = vector<vector<PII>>(N + 1);
	FOR(i, 0, Q) {
		int a, b; 
		scanf("%d%d", &a, &b);
		Query[a].push_back(PII(b, i));
	}
	dep[1] = 1;
	make_info();
	dfs(1, 0, 1);

	FOR(i, 0, Q) {
		puts((ans[i] ? "Yes" : "No"));
	}

	return 0;
}
