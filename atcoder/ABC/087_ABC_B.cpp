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

/* -----  2019/03/11  Problem: ABC 087 B / Link: http://abc087.contest.atcoder.jp/tasks/abc087_b  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL A, B, C, X; cin >> A >> B >> C >> X;
	LL ans = 0LL;
	FOR(i, 0, A + 1) {
		FOR(j, 0, B + 1) {
			FOR(k, 0, C + 1) {
				if (i * 500 + j * 100 + k * 50 == X)ans++;
			}
		}
	}
	
	
	cout << (ans) << "\n";

	return 0;
}
