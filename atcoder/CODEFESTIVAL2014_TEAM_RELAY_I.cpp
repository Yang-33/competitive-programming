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

/* -----  2018/12/19  Problem: codefestival2014_team_relay I / Link: __CONTEST_URL__  ----- */
/* ------問題------

陸運企業陸道社の社員である amylase 伯爵さんは、荷物を届けるためにとある街を訪れました。この街は、n 個の交差点と、交差点同士を結ぶ m 本の道路でできており、交差点には 1 から n までの番号がつけられています。
それぞれの交差点には信号機が 1 つずつ存在し、各信号機は青または赤の 2 つの状態を持ちます。時刻 t = 0, 1, 2, … における交差点 i の信号機の状態は、パラメータ ai, bi, ci によって次のように定まります。

最初の ci 秒、すなわち t = 0, 1, …, ci−1 は、赤である
その後、 ai 秒の青と bi 秒の赤が繰り返される
青から赤に変わる時刻 (たとえば t=ci+ai の時) は信号は赤であり、赤から青に変わる時刻 (たとえば t=ci の時) は信号は青であることに注意してください。
各交差点は、信号機の状態に関係なく到着することができますが、その交差点を出発できるのは信号機の状態が青のときのみに限られます。また、信号機による待ち時間を除いて、交差点は 0 秒で通過することができます。
さて、amylase 伯爵さんが時刻 0 で交差点 s にいるとき、そこから交差点 d へ移動するために必要な最小の所要時間を求めてください。

-----問題ここまで----- */
/* -----解説等-----

ある頂点について速く到達しても困らない。ダイクストラの辺をいじっても最適性は保持される。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M, S, T; cin >> N >> M >> S >> T;
	S--, T--;
	vector<vector<PLL>>G(N);
	VL a(N), b(N), c(N);
	FOR(i, 0, N) {
		cin >> a[i] >> b[i] >> c[i];
	}

	FOR(i, 0, M) {
		int a, b, c; cin >> a >> b >> c;
		a--, b--;
		G[a].push_back(PLL(b, c));
		G[b].push_back(PLL(a, c));
	}
	priority_queue<PLL, vector<PLL>, greater<PLL>>pq;
	VL dist(N, LINF);
	auto PUSH = [&](int nx, LL val) {
		if (dist[nx] > val) {
			dist[nx] = val;
			pq.push(PLL(val, nx));
		}
	};
	PUSH(S, 0);
	while (!pq.empty()) {
		LL cd, cv; tie(cd, cv) = pq.top(); pq.pop();
		if (dist[cv] < cd)continue;
		if (cd <= c[cv]) {
			cd = c[cv];
		}
		else {
			LL s = a[cv] + b[cv];
			LL ti = (cd - c[cv]) / s;
			LL left = (cd - c[cv]) % s;
			if (left >= a[cv]) {
				cd = (ti + 1)*(s);
			}
			else {
				cd = ti * (s)+left;
			}
			cd += c[cv];
		}
		for (auto edge : G[cv]) {
			PUSH(edge.first, cd + edge.second);
		}
	}


	LL ans = dist[T];
	cout << ans << endl;

	return 0;
}