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

/* -----  2019/07/07  Problem: AOJ 2531 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2531  ----- */

int lis(const vector<int>& a) {
	int n = a.size();
	const int inf = 1e9;
	vector<int> dp(n, inf);
	for (int i = 0; i < n; i++) *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
	return lower_bound(dp.begin(), dp.end(), inf) - dp.begin();
}
inline int readint() { int in; (void)scanf("%d", &in); return in; }
inline void outint(int out, bool endl = 1) { printf("%d%c", out, " \n"[endl]); }

int main() {
	int N = readint(), K = readint();
	vector<int> a(N);
	vector<int> rev(N);
	for (int i = 0; i < N; ++i) {
		a[i] = readint() - 1;
		rev[a[i]] = i;
	}
	int ans = 1;
	FOR(i, 0, N) {
		if (i > a[i])continue;
		// [i, a[i]]
		vector<PII>b;
		b.push_back(PII(i, a[i]));
		FOR(j, a[i] + 1, N) {
			if (a[i] < rev[j])continue;// soto
			if (rev[j] < i)continue;
			b.push_back(PII(rev[j],j));
		}
		vector<int>c; {
			SORT(b);
			FOR(i, 0, SZ(b)) {
				c.push_back(b[i].second);
			}
		}
		ans = max(ans, lis(c));
	}

	outint(min(ans + K, N / 2));


	return 0;
}
