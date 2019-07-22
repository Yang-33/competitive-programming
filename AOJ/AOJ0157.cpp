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

/* -----  2019/07/23  Problem: AOJ 0157 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0157  ----- */


int lis(const vector<int>& a) {
	int n = a.size();
	const int inf = 1e9;
	vector<int> dp(n, inf);
	for (int i = 0; i < n; i++) *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
	return lower_bound(dp.begin(), dp.end(), inf) - dp.begin();
}
// (w1,h1)<(w2,h2)の最長部分列(w1<w2 && h1<h2)
int lis2d(vector<pair<int, int>>a) {
	int n = (int)a.size();
	for (int i = 0; i < n; i++) {
		a[i].second = -a[i].second;
	}
	sort(a.begin(), a.end());
	vector<int> b(n);
	for (int i = 0; i < n; i++) b[i] = -a[i].second;
	return lis(b);
}

int main() {
	int n;
	while (cin >> n, n) {
		vector<pair<int, int>> a;
		for (int i = 0; i < n; i++) {
			int w, h;
			scanf("%d %d", &w, &h);
			a.emplace_back(h, w);
		}
		int m; cin >> m;
		for (int i = 0; i < m; i++) {
			int w, h;
			scanf("%d %d", &w, &h);
			a.emplace_back(h, w);
		}
		cout << lis2d(a) << endl;
	}
	return 0;
}