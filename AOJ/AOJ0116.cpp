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

/* -----  2019/07/20  Problem: AOJ 0116 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0116  ----- */

LL Largest_Rectangle(const vector<vector<bool>> &A) {
	vector<vector<LL>> a(A.size(), vector<LL>(A[0].size(), 0));
	LL count;
	for (int i = 0; i < (int)A[0].size(); i++) {
		count = 0;
		for (LL h = 0; h < (int)A.size(); h++) {
			if (A[h][i]) { count++; }
			else { count = 0; }
			a[h][i] = count;
		}
	}
	LL mx = 0;
	stack<PLL> s;
	for (int i = 0; i < (int)A.size(); i++) {
		for (int t = 0; t < (int)A[0].size(); t++) {
			LL mi = t;
			while (!s.empty() && s.top().first > a[i][t]) {
				PLL w = s.top(); s.pop();
				mx = max(mx, w.first*(t - w.second));
				mi = w.second;
			}
			s.push({ a[i][t],mi });
		}
		while (!s.empty()) {
			PLL w = s.top(); s.pop();
			mx = max(mx, w.first*((LL)A[0].size() - w.second));
		}
	}
	return mx;
}

int main() {
	int H, W;
	while (cin >> H >> W, H || W) {
		vector<string> s(H);
		for (int i = 0; i < H; ++i) {
			cin >> s[i];
		}
		vector<vector<bool>>a(H, vector<bool>(W, 0)); {
			FOR(i, 0, H) {
				FOR(j, 0, W) {
					a[i][j] = s[i][j] == '.';
				}
			}
		}
		LL ans = Largest_Rectangle(a);
		cout << (ans) << "\n";
	}


	return 0;
}
