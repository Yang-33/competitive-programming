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

/* -----  2019/04/03  Problem: ARC 003 D / Link: http://arc003.contest.atcoder.jp/tasks/arc003_d  ----- */


#include<chrono>
#include<random>
struct randgen {
	mt19937_64 rng;
	randgen() :rng((int)std::chrono::steady_clock::now().time_since_epoch().count()) {}
	LL getrand(LL s, LL t) {
		return rng() % (t - s) + s;
	}
};


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M, K; cin >> N >> M >> K;
	VVI NG(N, VI(N, 0));
	FOR(i, 0, M) {
		int a, b; cin >> a >> b;
		NG[a][b] = NG[b][a] = 1;
	}
	VI ids(N, 0);
	iota(ALL(ids), 0);

	double ans = 0;
	const int TRY_TIMES = 5000000;
	randgen rnd;
	FOR(_, 0, TRY_TIMES) {
		VI state = ids;
		FOR(i, 0, K) {
			int a = rnd.getrand(0, N);
			while (1) {
				int b = rnd.getrand(0, N);
				if (a != b) {
					swap(state[a], state[b]);
					break;
				}
			}
		}
		int ok = 1;
		FOR(i, 0, N) {
			int a = state[i];
			int b = state[(i + 1) % N];
			if (NG[a][b]) {
				ok = 0;
				break;
			}
		}
		ans += ok;
	}




	ans /= TRY_TIMES;

	cout << (ans) << "\n";

	return 0;
}
