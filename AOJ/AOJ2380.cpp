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

/* -----  2017/10/30  Problem: NU23 F / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2380  ----- */
/* ------問題------

意訳
4*4の盤面に水風船がある。これにはサイズがあり、1-4のときはそのままで、5になると破裂して四方に水をまき散らす。
これは一秒ごとに隣のマスに水が移動するとする。
盤面が与えられたとき、すべての水風船を破壊するためには最小で何滴水を追加すればよいか。

-----問題ここまで----- */
/* -----解説等-----

やるだけだった
5よりおおきいものは考えなくてもいいので愚直にやる

----解説ここまで---- */

void sumi(VI &v, int p) {
	bool temp[16][4], use[16][4] = { { 0 } };
	FOR(j, 0, 4)use[p][j] = 1;
	bool update = 1;
	while (update) {
		VI cp_v = v;
		update = false;
		FOR(i, 0, 16)FOR(j, 0, 4)temp[i][j] = 0;
		FOR(i, 0, 16) {
			FOR(j, 0, 4) {
				if (!use[i][j]) continue;
				int nx = i % 4 + DX[j], ny = i / 4 + DY[j];
				int np = nx + 4 * ny;
				if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) {
					continue;
				}
				update = true;
				if (v[np] > 0) cp_v[np]++;
				else temp[np][j] = 1;
			}
		}
		FOR(i, 0, 16) {
			if (cp_v[i] >= 5) {
				cp_v[i] = 0;
				FOR(j, 0, 4)temp[i][j] = 1;
			}
		}
		v = cp_v;
		FOR(i, 0, 16)FOR(j, 0, 4)use[i][j] = temp[i][j];
	}
}

int solve(VI &v, int step) {
	if (count(ALL(v), 0) == 16) {
		return step;
	}
	if (step == 5) return INF;
	int res = INF;
	FOR(i, 0, 16) {
		VI cp_v = v; cp_v[i]++;
		if (cp_v[i] == 5) {
			cp_v[i] = 0;
			sumi(cp_v, i);
		}
		res = min(res, solve(cp_v, step + 1));
	}
	return res;
}

int main() {
	VI v(16);
	FOR(i, 0, 16) {
		cin >> v[i];
	}
	int ans = solve(v, 0);
	if (ans == INF)ans = -1;
	cout << ans << "\n";
	return 0;
}
