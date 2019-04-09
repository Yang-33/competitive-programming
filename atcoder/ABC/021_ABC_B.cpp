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

/* -----  2019/04/09  Problem: ABC 021 B / Link: http://abc021.contest.atcoder.jp/tasks/abc021_b  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	LL a, b; cin >> a >> b;
	LL K; cin >> K;
	vector<LL>P(K);
	FOR(i, 0, K) {
		cin >> P[i];
	}

	LL ans = 1;
	set<LL>se({ a,b });
	FOR(i, 0, K) {
		ans &= se.count(P[i]) == 0;
		DD(de(ans, P[i]))
			se.insert(P[i]);
	}
	auto print_yesno = [](LL yes, int mode = 0) {
		if (mode == 0) {
			cout << (yes ? "yes" : "no") << endl;
		}
		else if (mode == 1) {
			cout << (yes ? "Yes" : "No") << endl;
		}
		else if (mode == 2) {
			cout << (yes ? "YES" : "NO") << endl;
		}
		else assert(0);
	};
	print_yesno(ans, 2);

	return 0;
}
