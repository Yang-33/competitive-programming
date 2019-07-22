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

/* -----  2019/07/21  Problem: AOJ 0144 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0144  ----- */


int main() {
	int N; cin >> N;
	VVI dist(N, VI(N, INF));
	FOR(i, 0, N)dist[i][i] = 0;
	FOR(i, 0, N) {
		int s; cin >> s;
		s--;
		int n; cin >> n;
		FOR(_, 0, n) {
			int t; cin >> t;
			t--;
			dist[s][t] = 1;
		}
	}
	FOR(k, 0, N)FOR(i, 0, N)FOR(j, 0, N)dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	int Q; cin >> Q;
	FOR(_, 0, Q) {
		int s, t, v; cin >> s >> t >> v;
		s--, t--;
		int d = dist[s][t] + 1; // 経由数
		if (d > v)cout << "NA\n";
		else cout << d << "\n";
	}
}