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

/* -----  2019/04/09  Problem: ABC 023 D / Link: http://abc023.contest.atcoder.jp/tasks/abc023_d  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	vector<double> H(N), S(N);
	for (int i = 0; i < N; ++i) {
		cin >> H[i] >> S[i];
	}

	auto f = [&](double hh) {
		vector<double>xs;
		FOR(i, 0, N) {
			xs.push_back((hh - H[i]) / S[i]);
		}
		SORT(xs);
		FOR(i, 0, N) {
			if (xs[i] < i)return false;
		}
		return true;
	};
	double L = N - 1, R = LINF;
	FOR(i, 0, 100) {
		double mid = (L + R) / 2;
		if (f(mid)) {
			R = mid;
		}
		else {
			L = mid;
		}
	}
	double ans = R + 1e-5;

	LL ANS = ans;
	cout << ANS << endl;

	return 0;
}
