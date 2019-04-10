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

/* -----  2019/04/10  Problem: ABC 019 D / Link: http://abc019.contest.atcoder.jp/tasks/abc019_d  ----- */

int main() {
	auto ask = [](int a, int b) {
		cout << "? " << a + 1 << " " << b + 1 << endl;
		int dist; cin >> dist;
		return dist;
	};
	auto ansoutput = [](int d) {
		cout << "! " << d << endl;
	};

	LL N; cin >> N;

	// 2N回聞けばのやつ
	auto f = [&](int S) {
		int maxD = -1;
		int dpoint = 0;
		FOR(i, 0, N) {
			if (S == i)continue;
			int dist = ask(S, i);
			if (dist > maxD) {
				maxD = dist;
				dpoint = i;
			}
		}
		return PII(dpoint, maxD);
	};
	PII P1 = f(0);
	PII P2 = f(P1.first);
	ansoutput(P2.second);


	return 0;
}
