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

/* -----  2019/08/04  Problem: AOJ 0211 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0211  ----- */

long long  gcd(long long  a, long long  b) { return b ? gcd(b, a%b) : a; }
long long  lcm(long long  a, long long  b) { return a / gcd(a, b) * b; }


// 慣れっぽい
int main() {
	int N;
	while (cin >> N, N) {
		VL d(N), v(N);
		FOR(i, 0, N) {
			cin >> d[i] >> v[i];
			// ここがないと落ちる
			LL g = gcd(d[i], v[i]);
			d[i] /= g; 
			v[i] /= g;
		}
		LL l = d.front();
		LL g = v.front();
		FOR(i, 0, N) {
			l = lcm(l, d[i]);
			g = gcd(g, v[i]);
		}
		FOR(i, 0, N) {
			LL ans = v[i] * l;
			ans /= d[i];
			ans /= g;
			cout << ans << "\n";
		}
	}


	return 0;
}
