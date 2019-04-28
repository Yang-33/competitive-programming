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

/* -----  2019/04/28  Problem: square869120Contest_01 B / Link: __CONTEST_URL__  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL H, W; cin >> H >> W;
	LL N; cin >> N;
	vector<LL> x(N), y(N);
	for (int i = 0; i < N; ++i) {
		cin >> x[i] >> y[i];
	}
	vector<PII>anss;
	// 等分かつ直線に乗らない
	auto f = [&](int w, int h) {

		VI a(2);
		FOR(i, 0, N) {
			if (w*y[i] == h * x[i])return false;
			a[w*y[i] - h * x[i] > 0 ? 0 : 1]++;
		}
		return a.front() == a.back();
	};


	FOR(i, 1, W + 1) {
		if (f(i, H)) {
			anss.push_back(PII(i, H));
		}
	}
	FOR(i, 1, H + 1) {
		if (f(W, i)) {
			anss.push_back(PII(W, i));
		}
	}

	if (!SZ(anss)) {
		cout << -1 << endl;
		return 0;
	}
	SORT(anss);
	UNIQ(anss);
	for (auto it : anss) {
		cout << "(" << it.first << "," << it.second << ")" << endl;
	}

	return 0;
}