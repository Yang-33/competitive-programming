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

/* -----  2018/10/29  Problem: CodeForces519 E div2 / Link: http://codeforces.com/contest/1043/problem/E  ----- */
/* ------問題------

グラフGが与えられる。頂点ごとにx,yが割り振られている。
隣接しない2点を選択し、和が最小になるx+y or y+xを選択する。
これを全頂点に行ったときの数値の和を求めよ。

-----問題ここまで----- */
/* -----解説等-----

x-yでそーとすればよい。
深夜に問題文を読んだので読めなかった(?)

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M; cin >> N >> M;
	VL x(N), y(N);
	vector<PII>a(N);
	FOR(i, 0, N) {
		cin >> x[i] >> y[i];
		a[i] = PII(x[i] - y[i], i);
	}
	VL ans(N);
	SORT(a);
	LL S = 0;
	FOR(i, 0, N) {
		int id = a[i].second;
		ans[id] += i * y[id] + S;
		S += x[id];
	}
	reverse(ALL(a));
	S = 0;
	FOR(i, 0, N) {
		int id = a[i].second;
		ans[id] += i * x[id] + S;
		S += y[id];
	}




	FOR(i, 0, M) {
		int aa, bb; cin >> aa >> bb;
		aa--, bb--;
		LL mnval = min(x[aa] + y[bb], x[bb] + y[aa]);
		ans[aa] -= mnval;
		ans[bb] -= mnval;
	}


	FOR(i, 0, N) {
		cout << ans[i] << " \n"[i == N - 1];
	}

	return 0;
}
