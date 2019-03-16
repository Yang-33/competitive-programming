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

/* -----  2019/03/12  Problem: ABC 082 D / Link: http://abc082.contest.atcoder.jp/tasks/abc082_d  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	int x, y; cin >> x >> y;
	VVI poss(2, VI(1, 0));
	{
		int mode = 0;
		for (auto c : s) {
			if (c == 'F') {
				poss[mode].back()++;
			}
			else {
				poss[mode].push_back(0);
				mode ^= 1;
			}
		}
	}
	const int base = 10000;
	auto f = [](const VI& xs, bool first) {
		bitset<2 * base>a;
		a[base] = 1;
		FOR(i, 0, SZ(xs)) {
			int dx = xs[i];
			bitset<2 * base>nx;
			nx |= a << dx;
			if (i || first)nx |= a >> dx;
			a = nx;
		}
		return a;
	};
	auto X = f(poss[0], 0);
	auto Y = f(poss[1], 1);
	cout << (X[base + x] && Y[base + y] ? "Yes" : "No") << "\n";

	return 0;
}
