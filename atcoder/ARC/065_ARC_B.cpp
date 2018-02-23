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

/* -----  2018/02/23  Problem: 065_arc_b / Link: https://arc065.contest.atcoder.jp/tasks/arc065_b?lang=en  ----- */
/* ------問題------

N 個の都市があり、K 本の道路と L 本の鉄道が都市の間に伸びています。 i 番目の道路は pi 番目と qi 番目の都市を双方向に結び、 i 番目の鉄道は ri 番目と si 番目の都市を双方向に結びます。 異なる道路が同じ 2 つの都市を結ぶことはありません。同様に、異なる鉄道が同じ 2 つの都市を結ぶことはありません。
ある都市から別の都市に何本かの道路を通って到達できるとき、それらの都市は道路で連結しているとします。また、すべての都市はそれ自身と道路で連結しているとみなします。
鉄道についても同様に定めます。
全ての都市について、その都市と道路・鉄道のどちらでも連結している都市の数を求めてください。

-----問題ここまで----- */
/* -----解説等-----

これ昔できなかった気がする
連結グラフの番号がアレばいいので適当にかんりすればよい。

----解説ここまで---- */

LL N, K, L;

LL ans = 0LL;
void dfs(int v, int p, VVI& G, VI& color, int k) {
	color[v] = k;
	FOR(i, 0, SZ(G[v])) {
		int nx = G[v][i];
		if (nx != p&&color[nx]==0)dfs(nx, v, G, color, k);
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> K >> L;

	VVI Rd(N);
	FOR(i, 0, K) {
		int p, q; cin >> p >> q;
		Rd[p - 1].push_back(q - 1);
		Rd[q - 1].push_back(p - 1);
	}
	VVI Ra(N);
	FOR(i, 0, L) {
		int p, q; cin >> p >> q;
		Ra[p - 1].push_back(q - 1);
		Ra[q - 1].push_back(p - 1);
	}

	VI rdc(N, 0);
	VI rac(N, 0);
	int k = 1;

	FOR(i, 0, N) {
		if (rdc[i] == 0)dfs(i, -1, Rd, rdc, k++);
	}
	k = 1;
	FOR(i, 0, N) {
		if (rac[i] == 0)dfs(i, -1, Ra, rac, k++);
	}
	map<PII, int>Map;
	FOR(i, 0, N) {
		Map[PII(rdc[i], rac[i])] ++;
	}
	FOR(i, 0, N) {
		cout<< Map[PII(rdc[i], rac[i])]<<endl;
	}

	return 0;
}
