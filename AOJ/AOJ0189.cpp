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

/* -----  2019/07/26  Problem: AOJ 0189 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0189  ----- */


int main() {
	int N = 10;
	int M;
	while (cin >> M, M) {
		int nn = 0;
		VVI dist(N, VI(N, INF)); {
			FOR(i, 0, N)dist[i][i] = 0;
			FOR(i, 0, M) {
				int a, b, c; cin >> a >> b >> c;
				dist[b][a] = dist[a][b] = min(dist[a][b], c);
				nn = max({ nn,a,b });
			}
		}
		nn++;
		FOR(k, 0, nn)FOR(i, 0, nn)FOR(j, 0, nn)dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		int id = -1;
		int sum = INF;
		DD(de(nn));
		FOR(x, 0, nn) {
			int ret = 0;
			FOR(i, 0, nn) {
				if (i == x)continue;
				ret += dist[i][x];
			}
			if (sum > ret) {
				sum = ret;
				id = x;
			}
		}
		cout << id << " " << sum << "\n";
	}

	return 0;
}
